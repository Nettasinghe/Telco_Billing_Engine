
///////////////////////////////////////////////////////////////////////////////////////////
// 
// Telco Billing Engine – 
// The function of a Telecom Billing Engine is to read the rated CDRs and customers billing
// plans from the databaseand while keeping them in memory, calculating the periodic bill 
// values, discounts, taxesand other chargesand finally writing those values which need to 
// bill the customer base, to the database.
//
///////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
//
// bill_eng.cpp
// Telco Billing Engine
// main method contains here
// developer - Chandika Nettasinghe
// development - 1998-2000
//
//////////////////////////////////////////////////////////////////////


// #define DIALOG
#define BILL_BLOCK_SIZE 100

#pragma warning(disable:4786)
#include <list>
#include <string>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdio.h>
#include <new.h>

using namespace std;

#include "db.h"
#include "db_data_containers.h"


int new_failure_handler( size_t )
{
   cout<<" New failure: could not allocate enough memory "<<endl;
   exit(1);
}

// -- db data containers begin
connections				*gsm_connections;
taxes					*gsm_taxes;
holiday_day_types		*gsm_holiday_day_types;
holiday_groups			*gsm_holiday_groups;
bill_cycle				*gsm_bill_cycle;
bill_block				*gsm_bill_block;
bill_item_block			*gsm_bill_item_block;
temporary_termination	*gsm_temporary_termination;
package_discount	    *gsm_package_discount;
other_charges			*gsm_other_charges;
// --db data containers end

int global_invoice_no;


char *bill_start_date, *bill_end_date, *bill_prefix, *bill_cycle_code;
char *version = "1.0.21";

char in_login[256];

void main(int argc, char *argv[])
{
	_set_new_handler( new_failure_handler );
	
	cout<<"Dialog GSM"<<endl
		<<"Colombo, Sri Lanka"<<endl
#ifdef INTERIM
		<<"***** Interim Bill Engine ******* "<<endl
#else
		<<"Bill Engine "<<endl
#endif
		<<"ver "<<version<<" compiled on "<<__DATE__<<" at "<<__TIME__
		<<endl;
	

#ifdef INTERIM
	if (argc == 1+2)
	{
		bill_start_date = argv[1];
		bill_end_date =argv[2];
		bill_prefix = "I0";
		bill_cycle_code = "WW";
		cout<<"\n\n[start date="<<bill_start_date<<"]  [end date="<<bill_end_date<<"]"<<endl;
	}
	else
	{
		cout<<"\n\n\nUsage:\n\t interim_bill  start date,  end date"<<endl
		<<"\t e.g \n\t interim_bill 20000215 20000314"<<endl<<endl;
		exit(1);
	}
#else
	if (argc == 1+4)
	{
		// WW 20020415  20020514  YY
		bill_cycle_code =  argv[1];
		bill_start_date = argv[2];
		bill_end_date = argv[3];
		bill_prefix = argv[4];
		if(strlen(bill_prefix) !=2)
		{
			cout<<" Bill prefix must be two characters not {"<<bill_prefix<<"}"<<endl;
			exit(1);
		}
		cout<<" bill_cycle="<<argv[1];
		cout<<" start date="<<bill_start_date<<" end_date="<<bill_end_date<<" prefix="<<bill_prefix<<endl;
	}
	else
	{
		cout<<"\n\n\nUsage:\n\t bill_eng  bill_cycle start_date end_date bill_prefix"<< endl
			<<" \t date is in 'YYYYMMDD' "<<endl
			<<"\t e.g \n\t bill_eng WW 200000815 200001014 C"<<endl<<endl
		    <<argc<<endl;
		exit(1);
	}
#endif

	// make space in heap for data containers
	gsm_bill_cycle				= new bill_cycle(bill_cycle_code);
	gsm_connections				= new connections(bill_start_date, bill_end_date); 
	gsm_taxes					= new taxes;
	gsm_holiday_day_types		= new holiday_day_types;
	gsm_holiday_groups			= new holiday_groups;
	gsm_bill_block				= new bill_block[BILL_BLOCK_SIZE];
	// assumtion each bill has a max of 50 items;
	gsm_bill_item_block			= new bill_item_block[BILL_BLOCK_SIZE*50];
	gsm_temporary_termination	= new temporary_termination;
	gsm_package_discount		= new package_discount(bill_end_date);
	gsm_other_charges			= new other_charges(bill_start_date, bill_end_date);

	//-------------- data base logins and print file location -----------------------
	FILE *login;
	char cust_care_login[128];
	char rate_login[128];
	char print_file_location[128];
	
	// get config data
	if( (login  = fopen( "./bill_eng.config", "r" )) == NULL )
	{
		printf( "The file 'bill_eng.config' was not opened\n" );
		exit(0);
	}
	
	fscanf( login, "%s", cust_care_login );
	fscanf( login, "%s", rate_login );
	fscanf( login, "%s", print_file_location );
	
	//cout<<cust_care_login<<" "<<rate_login<<" "<<print_file_location<<endl;
	
	if( fclose( login ) )
		printf( "The file 'bill_eng.config' was not closed\n" );
	
	//-------------- data base logins and print file location -----------------------
	
	// establish connection to database
	db_connect_cust_care(cust_care_login);
	db_connect_rating(rate_login);

	// performance measurures 
	time_t start_time, end_time;
	time(&start_time);

#ifdef INTERIM		
	gsm_connections->db_read_interim_bill_date();
	gsm_bill_cycle->run_no = 0;						// cjn - 20 mar 2003 - otherwise value too large since no initialization for interim bill
#else
	gsm_bill_cycle->db_pre_bill();
	gsm_bill_cycle->print_dates();
#endif

	
	cout<<"gsm_taxes->db_read"<<endl;
	gsm_taxes->db_read();

	cout<<"gsm_holiday_day_types"<<endl;
	gsm_holiday_day_types->db_read();
	
	cout<<"gsm_holiday_groups "<<endl;
	gsm_holiday_groups->db_read();
	
	cout<<"db_read_connections"<<endl;
	gsm_connections->db_read_connections();

	cout<<"db_read_tap"<<endl;
	gsm_connections->db_read_tap();

	cout<<"db_read_gprs"<<endl;
	gsm_connections->db_read_gprs();

	cout<<"db_read_anyware"<<endl;
	gsm_connections->db_read_anyware();

	cout<<"db_read_package_rental"<<endl;
	gsm_connections->db_read_package_rental();

	cout<<"db_read_value_add_rental"<<endl;
	gsm_connections->db_read_value_add_rental();

	cout<<"db_read_payments"<<endl;
	gsm_connections->db_read_payments();

	cout<<"db_read_interest"<<endl;
	gsm_connections->db_read_interest();

	cout<<"db_read_adjustments"<<endl;
	gsm_connections->db_read_adjustments();

	cout<<"db_read_pro_rates"<<endl;
	gsm_connections->db_read_pro_rates();

	cout<<"db_read_value_pp"<<endl;
	gsm_connections->db_read_value_pp();

	cout<<"db_read_contract_charge_pro_rate"<<endl;
	gsm_connections->db_read_contract_charge_pro_rate();

	cout<<"db_read_bulk_discount_get_balance"<<endl;
	gsm_connections->db_read_bulk_discount_get_balance();
	
	cout<<"db_gsm_temporary_termination"<<endl;
	gsm_temporary_termination->db_read();

	cout<<"db_gsm_other_charges"<<endl;
	gsm_other_charges->db_read();

	cout<<"db_gsm_package_discounts"<<endl;
	gsm_package_discount->db_read();

	gsm_connections->enable_bulk_discount_bill();  // mark all the folks who are eligible for bulk disounts
	
	cout<<"db_read_cdrs"<<endl;
	gsm_connections->db_read_cdrs();

	cout<< " All database read ups are done "<<endl; 
	
	global_invoice_no=0;
	
	cout<<" Billing start "<<endl;
	connection_state *ac;
	
	int run_id=0, total_bills_generated=0;
	int bills_pending_insert=0, bill_items_pending_insert=0;
	int current_account_no=0;

#ifdef INTERIM_TABLES
	gsm_connections->db_truncate_tables();
#endif

	// create bill for each client
	gsm_connections->start();  // set current to start of list
	do 
	{
		current_account_no = gsm_connections->get_current_ac_no();
		ac = gsm_connections->current;
//		cout<<"ACCOUNT NO "<<current_account_no<<endl;
		
		total_bills_generated++;
		global_invoice_no++;
		//		gsm_full_bill_summary->init(gsm_connections->current->corporate_bill_code); // for corporate billing.
		
		string tmp_dte;
		
		// set if rentals are to be paid
		if(ac->connection.connection_status == "T")
		{
			ac->charge.charge_rental=gsm_temporary_termination->is_rent_chargeable(current_account_no, bill_start_date);
		}
		// if permenantly disconnected dont charge rental
		if(ac->connection.connection_status == "D")
		{
			ac->charge.charge_rental=false;
		}
		
		
		// call call_charge with contract charge > contract charge ignore, 
		// less add differeance then rental, discount and tax
		if(ac->connection.contract_end_date > bill_start_date)
			ac->set_contract_charge();
		
		// if value plus plus is applicable then no one for one
		// if payment has been timely and in VPP group then discount
		float vpp=0;
		if(ac->connection.value_plus_plus == "Y")
		{
			if(ac->charge.vpp_payment)
			{
				//	cout<<" v pp -"<<gsm_connections->current->value_plus_plus<<endl;
				vpp = ac->charge.discounts = ac->call.vpp_discount;
			}
		}
		
		// dont give bulk discounts to calls that have been used for value plus plus
		if(vpp !=0)
		{
			ac->blk_discount.mark_value_pp();
		}
#ifndef INTERIM		
		ac->charge.bulk_discounts=ac->blk_discount.compute_bulk_discount();
#endif
		// compute 1 for 1 cases where no vpp and not home cell packages
		if(vpp == 0 && !(ac->connection.package_code.substr(0,2) == "HC" ||
			ac->connection.package_code == "L100" ||
			ac->connection.package_code == "L101"))
		{
			if(ac->charge.bulk_discounts != 0) // seperate compute proc here
			{
				ac->charge.discounts=ac->blk_discount.compute_one_for_one();  // marked cdr one for one
			}
			else
			{
				ac->charge.discounts = ac->call.ofo_discount;	// regular one for one
			}
			// no value plus plus so wipe the flag
			ac->charge.vpp_payment = false; // dont bill on value pp
		}
		
		// populate bill items for easy referance of linguistic vars
		gsm_connections->populate_useage(); 
		
		gsm_other_charges->totalise(current_account_no); // data structure built for account no
		// set value list for bill summary and total charge
		ac->charge.other_charges = gsm_other_charges->get_total_charge(gsm_connections->summary); 
		ac->charge.other_charges_taxable = gsm_other_charges->get_total_taxable_value();

		// cap discounts to max value of local call charges
		ac->charge.package_discounts += gsm_package_discount->apply_discount(ac->connection.package_code, gsm_connections->summary);
	
		gsm_taxes->simple_tax_compute(ac);
		
		//  summary total set up
		ac->total_current_charge(); // set the proper charge befor charity comp
		ac->get_total_due();		// compute total amount due
		
		gsm_connections->populate_taxes_discounts_charges(); // populate bill summary items files
		gsm_bill_block[bills_pending_insert].set_bill_block(ac);
		gsm_connections->summary.db_arrary_populate(bill_items_pending_insert, gsm_bill_item_block);
		
		bills_pending_insert++;
		if (BILL_BLOCK_SIZE == bills_pending_insert)
		{
			gsm_connections->db_insert_bill_block(bills_pending_insert, gsm_bill_block);
			gsm_connections->db_insert_bill_items_block(bill_items_pending_insert, gsm_bill_item_block);
			
			if( !(total_bills_generated%500))
				cout<<" Bills inserted "<<total_bills_generated<<endl;
			
			bills_pending_insert = 0;
			bill_items_pending_insert = 0; // incremented in function
		}
		else if (bills_pending_insert > BILL_BLOCK_SIZE )
		{
			cout<<"ERROR insert array size over flow "<<total_bills_generated<<endl;
		}
	} while(gsm_connections->next()); // till all connections are done
	
	if(bills_pending_insert > 0)
	{
		gsm_connections->db_insert_bill_block(bills_pending_insert, gsm_bill_block);
		gsm_connections->db_insert_bill_items_block(bill_items_pending_insert, gsm_bill_item_block);
	}

#ifndef INTERIM
	gsm_connections->db_insert_bulk_discount_usage();
	gsm_bill_cycle->db_post_bill(total_bills_generated); // the commit is here
#endif

	time( &end_time );

#ifdef INTERIM_TABLES
	gsm_connections->db_create_indexes();
#endif

	db_disconnect_cust_care();		// be gentle with the data base, exit with grace
	db_disconnect_rating();			// be gentle with the data base, exit with grace
	
	cout<<" Bill generation done in "<<difftime(end_time,start_time)<<" secs"<<endl;
	cout<<" for "<<total_bills_generated<<endl;
	cout<<" Generation rate "<<difftime(end_time,start_time)/ (total_bills_generated+.01) <<" secs/bill"<< endl;
}

