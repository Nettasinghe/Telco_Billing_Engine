
//////////////////////////////////////////////////////////////////////
//
// bill_block.cpp: implementation of the bill_block class.
// Telco Billing Engine
// developer - Chandika Nettasinghe
// development - 1998-2000
//
//////////////////////////////////////////////////////////////////////

#include "db_data_containers.h"

extern bill_cycle	*gsm_bill_cycle;
extern connections	*gsm_connections;

void bill_block::set_bill_block(connection_state *c)
{
	char buf[50];
	sprintf(buf,"%d",c->connection.account_no);
	strcpy(client_code, buf);
	account_no = c->connection.account_no;
	
	strcpy(bill_no, get_invoice_no(buf));
	strcpy(br_code,gsm_bill_cycle->bill_cycle_code.c_str());
	total_bill_value = floor(c->charge.total_charges) / 100.0;
	/*
	strcpy(start_date, gsm_connections->start_date.c_str());
	strcpy(end_date, gsm_connections->end_date.c_str());
	strcpy(due_date, gsm_connections->due_date.c_str());
	strcpy(bill_date, gsm_connections->end_date.c_str());
	*/
	balance_bf = floor(c->charge.brought_forward) / 100.0;
	balance_cf = floor(c->charge.total_due) / 100.0;
#ifndef INTERIM
	bill_payments = floor(c->charge.payments) /100.0;
#else
	bill_payments = 0;
#endif
	run_no = gsm_bill_cycle->run_no;
	strcpy(corporate_bill_code,c->connection.corporate_bill_code.c_str());
	idd = floor(c->call.international) /100.0;
}
//ATD-077-360361