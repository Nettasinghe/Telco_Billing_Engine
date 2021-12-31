

//////////////////////////////////////////////////////////////////////
// 
// connection_state.cpp: implementation of the connection_state class.
// Telco Billing Engine
// developer - Chandika Nettasinghe
// development - 1998-2000
//
//////////////////////////////////////////////////////////////////////

#include "db_data_containers.h"

extern int global_invoice_no;
extern char *bill_prefix;




// if call changes meet the contacted value then there is no top up
// else a differenec is added to fill to the obligated amount.
// prorated contact charges
float connection_state::set_contract_charge()
{
	// check if contract charge is applicable
	float useage;
	useage = call.call_charges + charge.get_rental() + charge.rental_pro_rate;

	//useage = tot_call_charge+charge.rental;

	if (connection.contract_charge <= useage)
		charge.contract_charges = 0;
	else
		charge.contract_charges = connection.contract_charge - useage;

	// just in case catch
	if (charge.contract_charges < 0)
	{
		cout<<" error contract charge less tha zero"<<endl;
		charge.contract_charges = 0;
	}

	// For tempory disconnects & permenant discconect no contact charges
	if (charge.charge_rental == false)  
		charge.contract_charges=0;

	return charge.contract_charges;
}



float connection_state::get_nsl_taxable_value()
{
	float nsl;
	nsl =	  charge.get_contract_charge()
			+ call.call_charges	
			+ call.anyware
			+ call.gprs
			+ call.air // roaming 	calls
			+ charge.get_rental()
			+ charge.misc_charges
			+ charge.get_discounts()
			+ charge.rental_pro_rate
			+ charge.interest
			+ charge.other_charges_taxable;
	return nsl;
}

// note no roaming
float connection_state::get_gst_taxable_value()
{
	float gst;
	gst =	  charge.get_contract_charge()
			+ call.call_charges // migrate
			+ call.anyware
			+ call.gprs
			+ charge.get_rental()
			+ charge.misc_charges
			+ charge.get_discounts()
			+ charge.rental_pro_rate
			+ charge.interest
			+ charge.other_charges_taxable;
	return gst;
}


float connection_state::total_current_charge()
{
	charge.total_charges =	charge.get_rental()
							+ call.air 
							+ call.call_charges	
							+ call.anyware
							+ call.gprs
							+ charge.misc_charges
							+ charge.get_contract_charge()
							+ charge.get_discounts()
							+ charge.tax
							+ charge.rental_pro_rate
							+ charge.interest
							+ charge.other_charges;

	return charge.total_charges;
}


float connection_state::get_charity_amount()
{
//	charity = total_due*charity_percent;
	charge.charity = floor(charge.total_charges * 0.5F/100.0F);

	if(charge.charity > 25*CENTS)
		charge.charity = 25*CENTS;

	// if overpayment has been made
	if (charge.charity < 0) 
		charge.charity = 0;
	return charge.charity;
}


float connection_state::get_total_due()
{
	charge.total_due =  charge.total_charges
						+ charge.brought_forward
						- charge.payments
						+ charge.charity; 
	return charge.total_due;
}


float connection_state::get_total_previous_month()
{
	return(charge.brought_forward-charge.payments);
}


char* get_invoice_no(char *buf)
{
	sprintf(buf,"%s%08d",bill_prefix, global_invoice_no);
	return buf;
}




