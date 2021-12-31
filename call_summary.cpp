

//////////////////////////////////////////////////////////////////////
//
// call_summary.cpp: implementation of the call_summary class.
// Telco Billing Engine
// developer - Chandika Nettasinghe
// development - 1998-2000
//
//////////////////////////////////////////////////////////////////////




#include "db_data_containers.h"
#include <math.h>
#include <stdlib.h>
#include <algorithm>

extern holiday_day_types	*gsm_holiday_day_types; // even worse hacks
extern holiday_groups		*gsm_holiday_groups;	// a compounded sin

#define OUT_GOING_THRESHOLD 2500*CENTS
#define IDD_THRESHOLD 10000*CENTS
#define IDD_PERCENT 15
#define IDD_OUTGOING_THRESHOLD 3500*CENTS


void call_summary::init()
{
	air				= 0;	// roaming
	out_d_d			= 0;	// out going dialog to dialog
	out_d_nd		= 0;	// out going dialog to non dialog
	in_f_d			= 0;	// incomming from non dialog
	in_f_nd			= 0;	// in comming from non dialog
	re_r_int		= 0;	// re routed internaltional
	international	= 0;	// idd calls
	sms				= 0;	// sms charges
	oth				= 0;	// un_classified
	anyware			= 0;	// anywahe
	call_charges	= 0;	// telphony charges
	ofo_out_units	= 0;	// one for one outgoing units
	ofo_incomming	= 0;	// one for one incomming value
	ofo_discount	= 0;
	vpp_outgoing	= 0;	// value plus plus
	vpp_incomming	= 0;	// value plus plus
	vpp_idd			= 0;	// value plus plus
	vpp_discount	= 0;
	gprs			= 0;	// gprs calls
}



ostream& operator<<(ostream& out, cdr_data x)
{
	out<<
	"account = "<<x.account_no<<", "<<endl<<
	"termination_type="<<x.termination_type<<", "<<	
	"units="<<x.units<<", "<<	
	"charge="<<x.charge<<", "<<	
	"call_partner_id="<<x.call_partner_id<<", "<<
	"duration="<<x.duration<<", "<<	
	"call_time="<<x.call_time<<", "<<
	"ms_location="<<x.ms_location<<", "<<
	"call_type_id="<<x.call_type_id<<", "<<
	"network_id="<<x.network_id<<", "<<	
	"service_type_id="<<x.service_type_id<<", "<<
	"locale_id="<<x.locale_id;	

	return out;
}



void call_summary::classify_calls(cdr_data *cdr)
{
	if (  (cdr->service_type_id == (int)TELEPHONY ||
			cdr->service_type_id == (int)FAX_G3_SPEECH ||
			cdr->service_type_id == (int)AUTO_FAX_G3 ||
			cdr->service_type_id == (int)NOT_USED ) // data
			&&  
			cdr->locale_id == (int)NATIONAL_CALL) // N=NATIONAL
	{
		if (cdr->call_type_id == (int)ORIGINATING_CALL_RADIO)  
		{
			if( cdr->network_id == "077")		//	"Out going Dialog to Dialog"
			{
				out_d_d += cdr->charge;
			}
			else if (cdr->network_id != "077")	//	"Out going Dialog to Non Dialog";
			{
				out_d_nd += cdr->charge;
			}
		}
		// Terminating
		else if (cdr->call_type_id == (int)TERMINATING_CALL_RADIO || 
				cdr->call_type_id == (int)MSC_FORWARDED_TERMINATING_CALL ||
				cdr->call_type_id == (int)REROUTED_TERMINATING_CALL || 
				cdr->call_type_id == (int)GMSC_FORWARDED_TERMINATING_CALL )
		{
			if( cdr->network_id == "077")		// 	"In coming Dialog to  Dialog"
			{
				in_f_d += cdr->charge;
			}
			else if (cdr->network_id != "077")	//	"In coming non Dialog to Dialog"
			{
				in_f_nd += cdr->charge;
			}
		}
	}
	// re routed international for roaming
	else if (  (cdr->service_type_id == (int)TELEPHONY ||
				cdr->service_type_id == (int)FAX_G3_SPEECH ||
				cdr->service_type_id == (int)AUTO_FAX_G3 ||
				cdr->service_type_id == (int)NOT_USED ) &&  
			 cdr->locale_id == (int)INTERNATIONAL_CALL &&
			 cdr->call_type_id == (int)ORIGINATING_CALL_RADIO &&  
			 cdr->ms_location  == "RRI"  ) // for system issued international CDR, 
			 // other cases handled under re-routed international calls
	{
		re_r_int += cdr->charge;
	}
	// normal IDD
	else if (  (cdr->service_type_id == (int)TELEPHONY ||
				cdr->service_type_id == (int)FAX_G3_SPEECH ||
				cdr->service_type_id == (int)AUTO_FAX_G3 ||
				cdr->service_type_id == (int)NOT_USED ) &&  
			 cdr->locale_id == (int)INTERNATIONAL_CALL &&
			 cdr->call_type_id == (int)ORIGINATING_CALL_RADIO &&  
			 cdr->ms_location  != "RRI"  ) 
	{
		international += cdr->charge;
	}
	else if(/*cdr->service_type_id == "SMS_MT" ||*/ cdr->service_type_id == (int)SMS_MO_PP)		// sms
	{
		sms += cdr->charge;
	}
	else // uncalssified calls
	{
		oth += cdr->charge;
	}

	call_charges += cdr->charge;
	// compute discounts
	one_for_one_classify(cdr);
	value_p_p_classify(cdr);
}


// discount is applicable to
// a) non dialog
// b) voice
// c) peak
// d) local
float call_summary::one_for_one_classify(cdr_data *cdr)
{
	string  day_type;

	// is call date weekend, holiday etc,
	day_type = gsm_holiday_day_types->get_day_type(cdr->call_time);

	if(cdr->service_type_id == (int)TELEPHONY &&
	   (int)NATIONAL_CALL == cdr->locale_id &&
	   cdr->network_id != "077" && 
	   (cdr->call_time.substr(4+2+2,2) >= "06" && cdr->call_time.substr(4+2+2,2) < "20") &&
	   gsm_holiday_groups->is_in_group("1FOR1",day_type))
	{
		// total out going calls
		if ((int)ORIGINATING_CALL_RADIO == cdr->call_type_id  && cdr->charge > 0)
		{
			ofo_out_units += cdr->units;
		}
		// total incomming calls non dialog------------------------------
		if ( (cdr->call_type_id == (int)TERMINATING_CALL_RADIO || 
			  cdr->call_type_id == (int)MSC_FORWARDED_TERMINATING_CALL ||
			  cdr->call_type_id == (int)GMSC_FORWARDED_TERMINATING_CALL ) )
		{
			// valid only for weekdays and non zero charged calls
			ofo_incomming  += cdr->charge;
		}
	}

	if (ofo_incomming >= ofo_out_units*4.00*CENTS)
		ofo_discount = -ofo_out_units*4.00*CENTS;
	else //(outgoing_units >= incomming_value)
		ofo_discount= -ofo_incomming;

//	printf("service useage		= %8.02f\n",incomming_value);
//	printf("potential discount	= %8.02f\n",outgoing_units*4.00*CENTS);
//	printf("call limited dis	= %8.02f\n",discount);
	
/*
	if(discount > 0)
	{
		u_summary->add_bill("1FOR1", discount);
	}
*/
	return ofo_discount; // value;
}



float call_summary::value_p_p_classify(cdr_data *cdr)
{
	if(cdr->service_type_id == (int)TELEPHONY
	   /*cdr->service_type_id == "FAX" ||
	   cdr->service_type_id == "AUTO_FAX" ||
	   cdr->service_type_id == "NOT_USED"*/ )
	{
		// totalize out going calls 
		if ((int)NATIONAL_CALL == cdr->locale_id &&
			(int)ORIGINATING_CALL_RADIO == cdr->call_type_id )
		{
			vpp_outgoing +=  cdr->charge;
		}

		// totalize idd calls 
		if (cdr->locale_id == (int)INTERNATIONAL_CALL &&
			cdr->call_type_id == (int)ORIGINATING_CALL_RADIO &&
			cdr->ms_location != "RRI")
		{
			vpp_idd += cdr->charge;
		}

		// totalize incomming calls 
		if ((int)NATIONAL_CALL == cdr->locale_id &&
			(cdr->call_type_id == (int)TERMINATING_CALL_RADIO || 
			  cdr->call_type_id == (int)MSC_FORWARDED_TERMINATING_CALL ||
			  cdr->call_type_id == (int)GMSC_FORWARDED_TERMINATING_CALL ) )
		{
			vpp_incomming += cdr->charge;
		}
	}

	if (vpp_outgoing >= OUT_GOING_THRESHOLD ||
		vpp_idd > IDD_THRESHOLD ||
		(vpp_outgoing + vpp_idd*IDD_PERCENT/100 > IDD_OUTGOING_THRESHOLD)
		)
	{
			vpp_discount = -vpp_incomming; // discount is all incomming free.
	}

//	printf("service useage		= %8.02f\n",incomming_value);
//	printf("potential discount	= %8.02f\n",outgoing_value);
//	printf("call limited dis	= %8.02f\n",discount);

/*
	if(discount > 0)
	{
		u_summary->add_bill("VALUE_P_P", discount);
	}
*/
	return vpp_discount; //discount; // value;
}
