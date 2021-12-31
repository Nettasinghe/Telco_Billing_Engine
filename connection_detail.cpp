

//////////////////////////////////////////////////////////////////////
//
// connection_detail.cpp: implementation of the connection_detail class.
// Telco Billing Engine
// developer - Chandika Nettasinghe
// development - 1998-2000
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"

extern int global_invoice_no;


void connection_detail::init()
{
	account_no			= 0;
	contract_charge		= 0;
	package_code		= "";
	contract_end_date	= "";
	tax_group			= "";
	corporate_bill_code = "";
	value_plus_plus		= "";
	connection_status   = "";
	bulk_discount		= false;   // elegibility for bulk discount
}



ostream& operator<<(ostream& out, connection_detail x)
{
	out
	<<" contract charge = "<<x.contract_charge <<", "
	<<" contract end = "<<x.contract_end_date <<", "
	<<" tax group = "<<x.tax_group <<", "
	<<" corporate_bill_code = "<<x.corporate_bill_code <<", "
	<<" value_plus_plus = "<<x.value_plus_plus;
	return(out);
}



