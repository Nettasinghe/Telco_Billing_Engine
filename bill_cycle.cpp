

//////////////////////////////////////////////////////////////////////
//
// bill_cycle.cpp: implementation of the bill_cycle class.
// Telco Billing Engine
// developer - Chandika Nettasinghe
// development - 1998-2000
//
//////////////////////////////////////////////////////////////////////

#include "db_data_containers.h"



bill_cycle::bill_cycle(string b_r_c)
{
	bill_cycle_code = b_r_c;
}


string bill_cycle::get_bill_cycle_code()
{
	return bill_cycle_code;
}


void bill_cycle::print_dates()
{
	cout<<" CDR range = "<<first_cdr_date<<" to "<<last_cdr_date<<" bill on = "<<bill_on_date<<endl;
	cout<<" pay on ="<<pay_date<<" run no = "<<run_no<<endl;
}

