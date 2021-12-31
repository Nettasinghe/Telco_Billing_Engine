

//////////////////////////////////////////////////////////////////////
//
// connections.cpp: implementation of the connections class.
// Telco Billing Engine
// developer - Chandika Nettasinghe
// development - 1998-2000
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"

extern int global_invoice_no;



void connections::print_detail()
{
	for(CONNECTION_DEF::iterator i=conn.begin(); i!=conn.end(); i++)
		cout<<"{"<<(*i).first<<"} {"<<(*i).second.connection<<"}"<<endl;
}


connections::connections()
{
	start_date = ""; 
	current = NULL;
	summary.set_id("Bill summary ");
}



void connections::populate_taxes_discounts_charges()
{
	summary["DISSUR_CHG"]	= current->charge.get_discounts()
							  + current->charge.interest;			// Discounts/Surcharges
	summary["GOVTAX_TOT"]	= current->charge.tax;					// Govenment Tax / Levy
	summary["CUR_CHG"]		= current->total_current_charge();		// Total current charges
	summary["AMT_DUE"]		= current->charge.total_due;			// total_due;					// Amount due
	summary["DISCOUNT"]		= current->charge.get_discounts();		// 1FOR1, value plus plus

	// differentate 
	if(current->charge.vpp_payment)
	{
		summary["VALUE_PP"] = current->charge.discounts;			// value plus plus
	}
	else
	{
		summary["1FOR1"] = current->charge.discounts;				// 1FOR1
	}

	if(current->charge.bulk_discounts != 0)
		summary["BULK_DISCOUNT"] = current->charge.bulk_discounts;	// write if only the value is present

	// taxes
	summary["GST"]	= current->charge.gst;
	summary["NSL"]	= current->charge.nsl;

}

void connections::populate_useage()
{
	summary.clear();	// remove stuff  from previous bill

	summary["B_F"]			= current->charge.brought_forward;		// Brought Forward
	summary["PAY"]			= current->charge.payments;				// Payments
	summary["TOT_PM"]		= current->get_total_previous_month();	// Total Previous month
	summary["M_SURV"]		= current->charge.get_rental() 
							  + current->charge.rental_pro_rate;	// Monthly Services, inc rent for part months
	summary["T_CALL_CHG"]	= current->call.call_charges 
							  + current->call.anyware 
							  + current->call.gprs;					// Total call charges
	summary["CON_CHG"]		= current->charge.get_contract_charge();// Contract Charges
	summary["RENTAL"]		= current->charge.get_rental();			// Monthly Rental (package+value added services)
	summary["MSC_CHG"]		= current->charge.misc_charges;			// Miscellaneous Charges, adjustments
	summary["PKG_RENTAL"]	= current->charge.package_rental;		// package rental only for the for month
	summary["VAS"]			= current->call.air;					// "air" Value Added Services (Roaming)
	summary["PRO_RATE"]		= current->charge.rental_pro_rate;		// for the within bill cycle services
	summary["INT_LATE"]		= current->charge.interest;				// late payment interest
	
	summary["GPRS"]			= current->call.gprs;					// GPRS
	summary["SMS_VAS"]		= current->call.anyware;				// SMS value added
	summary["AIR"]			= current->call.air;					// roaming
	summary["OUT_D_D"]		= current->call.out_d_d;
	summary["OUT_D_ND"]		= current->call.out_d_nd;
	summary["IN_F_D"]		= current->call.in_f_d;
	summary["IN_F_ND"]		= current->call.in_f_nd;
	summary["RE_R_INT"]		= current->call.re_r_int;				// re routed international
	summary["INT"]			= current->call.international;
	summary["SMS"]			= current->call.sms;

	if(current->call.oth > 0)	// uncalssified calls
	{
		summary["OTH"]		= current->call.oth;
	}

	summary["P_TOT_LOC"]	= current->call.out_d_d 				// points total local charges
							  + current->call.out_d_nd 
							  + current->call.in_f_d 
							  + current->call.in_f_nd;

	summary["P_TOT_INT"]	= current->call.air 
							  + current->call.re_r_int 
							  + current->call.international;
	summary.append(current->charge.rent_breakup); // copy the rents
}




// sets the current pointer to correct account_no
bool connections::set_current(int account_no)
{
	i_current = conn.find(account_no);
	if(i_current != conn.end())
	{
		current=&(*i_current).second;
		return true;
	}
	return false;
}

int connections::get_current_ac_no()
{
	if(i_current != conn.end())
	{
		return (*i_current).first;
	}
	cout<<" Bad call to 'get_current_ac_no::' end of container "<<endl;
	return 0; // at end of container 
}



void connections::insert(int account_no, connection_detail &c_d )
{
	conn[account_no].connection = c_d;
	conn[account_no].charge.init();
	conn[account_no].call.init();
}


int	connections::start()
{
	i_current = conn.begin();

	if(i_current == conn.end())
	{
		cout<<" No connections to bill "<<endl;
		exit(1);
	}
	current = &(*i_current).second;
	return conn.size();
}


bool connections::next()
{
	i_current++;
	if(i_current != conn.end())
	{	
		current = &(*i_current).second;
		return true;
	}
	return false;
}

connections::connections(string start_dte, string end_dte)
{
	start_date = start_dte;
	end_date = end_dte; 
	due_date = "20001022";
}


// folks who are eligible for bulk discounts
// If they have a credit minutes balance they automatically
// become eligible
void   connections::enable_bulk_discount_bill()
{
	connection_state *c;

	CONNECTION_DEF::iterator i;
	for(i=conn.begin(); i!=conn.end(); i++)
	{
		c= &(*i).second;
		if(c->blk_discount.min_balance.size() > 0)
		{
			c->connection.bulk_discount=true;
		}
	}
}
