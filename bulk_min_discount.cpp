

//////////////////////////////////////////////////////////////////////
//
// bulk_min_discount.cpp: implementation of the bulk min discounting
// Telco Billing Engine
// developer - Chandika Nettasinghe
// development - 1998-2000
//
//////////////////////////////////////////////////////////////////////


// a) collect all calls for folks who are elegibale for bulk discounting
// b) Ordered collection in time increasing order
// c) mark as calls are used in discounting. 

#pragma warning(disable:4786)

#include "db_data_containers.h"
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <set>
#include <stdio.h>
#include <time.h>

using namespace std;
 
extern holiday_day_types	*gsm_holiday_day_types; // even worse hacks
extern holiday_groups		*gsm_holiday_groups;	// a compounded sin


bulk_min_balance::bulk_min_balance()
{
	used		= 0;
	balance		= 0;
	discount	= 0;
}

// make elegant some of the matching
bool bulk_min_balance::match_tb(e_time_band t)
{
	if(t==time_band || time_band==TB_ANY)
		return true;
	
	return false;
}

// same as above
bool bulk_min_balance::match_tc(e_type_of_call t)
{
	if(t==call_type_id || call_type_id==TC_ANY)
		return true;
	
	return false;
}


bulk_discount_call::bulk_discount_call()
{
	charge = 0;
	available = true;
	charged_units=0;
	dialog = false;
	call_time = "";
}


bool bulk_discount_call::operator < (const bulk_discount_call  &t) const 
{
	if(call_time < t.call_time) // oldest call first
		return true;
	return false;
}

// convert to short format from cdr and store 
// calls applicable for disounts
// a) national
// b) voice 
// c) originate, terminate
bool bulk_discount::insert_cdr(cdr_data *cdr)
{
	if ( (cdr->call_type_id == ORIGINATING_CALL_RADIO ||  
		  cdr->call_type_id == TERMINATING_CALL_RADIO ||
		  cdr->call_type_id == MSC_FORWARDED_TERMINATING_CALL ||
		  cdr->call_type_id == GMSC_FORWARDED_TERMINATING_CALL)  
		  && cdr->locale_id == NATIONAL_CALL 
		  && cdr->service_type_id == TELEPHONY 
		  && cdr->charge > 0)
	{
		bulk_discount_call c;

		string hour = cdr->call_time.substr(4+2+2,2); 
		// have one type of termination to make logic comprehensible
		if(cdr->call_type_id == MSC_FORWARDED_TERMINATING_CALL ||
			cdr->call_type_id == GMSC_FORWARDED_TERMINATING_CALL)
		{
			c.call_type_id	= TERMINATING_CALL_RADIO;
		}
		else
			c.call_type_id	= (e_type_of_call)cdr->call_type_id;

		c.time_band		= (hour >= "06" && hour < "20") ? PEAK : OFF_PEAK;
		c.available		= true;					// can discount on call
		c.charge		= cdr->charge;
		c.charged_units	= cdr->charged_units; // change when r_rated cdr is changed TODO
		c.units			= cdr->units; 
		c.call_time		= cdr->call_time;
		c.dialog		= (cdr->network_id == "077") ? true : false;
		discountable_calls.insert(c);
		return true;
	}
	return false;
}


// mark useage of one for one in call list
float bulk_discount::compute_one_for_one()
{
	string  day_type;
	
	DISCOUNTABLE_CALLS_DEF::iterator i;
	
	int ofo_out_units=0;
	float ofo_incomming_charge=0, ofo_discount=0 ;
	
	bulk_discount_call	*c;
	
	for(i=discountable_calls.begin(); i!= discountable_calls.end(); i++)
	{
		c = &(*i);
		
		// is call date weekend, holiday etc,
		day_type = gsm_holiday_day_types->get_day_type(c->call_time);
		
		if(
			c->dialog == false && 
			c->time_band == PEAK &&
			gsm_holiday_groups->is_in_group("1FOR1",day_type) &&
			c->available == true
			)
		{
			// total out going calls
			if ((int)ORIGINATING_CALL_RADIO == c->call_type_id  && c->charge > 0 )
			{
				ofo_out_units += c->units;
			}
			// total incomming calls non dialog------------------------------
			if ( c->call_type_id == (int)TERMINATING_CALL_RADIO ) 
			{
				// valid only for weekdays and non zero charged calls
				ofo_incomming_charge  += c->charge;
			}
		}
		
		if (ofo_incomming_charge >= ofo_out_units*4.00*CENTS)
			ofo_discount = -ofo_out_units*4.00*CENTS;
		else //(outgoing_units >= incomming_value)
			ofo_discount = -ofo_incomming_charge;
		
		//	printf("service useage		= %8.02f\n",incomming_value);
		//	printf("potential discount	= %8.02f\n",outgoing_units*4.00*CENTS);
		//	printf("call limited dis	= %8.02f\n",discount);
	}
	return ofo_discount; // value;
}

// the free minute balances
bool bulk_discount::insert_balance(char* tb, char* ctid, float bal)
{
	bulk_min_balance b;

	b.balance=bal;
	
	if(strcmp(tb,"PK")==0)
		b.time_band=PEAK;
	else if (strcmp(tb,"OPK")==0)
		b.time_band=OFF_PEAK;
	else if (strcmp(tb,"ANY")==0)
		b.time_band = TB_ANY;
	else
	{
		cout<<" BAD time band "<<tb<<endl;
	}

	if(strcmp(ctid,"IN")==0)
		b.call_type_id=TERMINATING_CALL_RADIO;
	else if (strcmp(ctid,"OUT")==0)
		b.call_type_id=ORIGINATING_CALL_RADIO;
	else if (strcmp(ctid,"ANY")==0)
		b.call_type_id = TC_ANY;
	else
	{
		cout<<" BAD call_type_id "<<ctid<<endl;
	}

	min_balance.push_back(b);

	return true;
}


// mark useage of value plus plus calls
// all incomming are free
void bulk_discount::mark_value_pp()
{
	DISCOUNTABLE_CALLS_DEF::iterator i;

	bulk_discount_call	*c;

	for(i=discountable_calls.begin(); i!= discountable_calls.end(); i++)
	{
		c = &(*i);
		if (c->call_type_id == TERMINATING_CALL_RADIO)
		{
			c->available = false;
		}
	}
}



// maximum pack algo
// last call if partially used is marked as un available
float bulk_discount::compute_bulk_discount()
{
	DISCOUNTABLE_CALLS_DEF::iterator i;
	BULK_CREDITS_DEF::iterator j;

	bulk_discount_call *c;
	bulk_min_balance *bcc;
	
	total_discount_value=0;

	// do as many passes as required by the bulk credit definitions.
	for(j = min_balance.begin(); j != min_balance.end(); j++)
	{
		bcc = &(*j);	// debugger friendly in MS VC
		for(i=discountable_calls.begin(); i!= discountable_calls.end(); i++)
		{
			c = &(*i);
			if ( c->available && bcc->match_tc(c->call_type_id) && bcc->match_tb(c->time_band))
			{
				if (c->charged_units <= (bcc->balance - bcc->used) )
				{
					c->available			=  false;		// cant use call any more for other discounts
					bcc->used				+= c->charged_units;
					bcc->discount			+= c->charge;
					total_discount_value	-= c->charge; // for all the discounts and calls 
				}
			}
		}
	}
	return total_discount_value;
}


