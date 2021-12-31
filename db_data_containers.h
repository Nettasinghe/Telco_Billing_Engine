

//////////////////////////////////////////////////////////////////////
//
// db_data_containers.h: class definitions.
// Telco Billing Engine
// developer - Chandika Nettasinghe
// development - 1998-2000
//
//////////////////////////////////////////////////////////////////////


#pragma warning(disable:4786)

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <set>
#include <stdio.h>
#include <math.h>

using namespace std;

class result_list;

#define GSM_MIN_YEAR 1949
#define GSM_MAX_YEAR 2051
#define CENTS 100

// interim bill comversion
// a) use ora precompler on db_talk_interim
// b) #define INTERIM
// c) recompile

#define INTERIM

#ifdef INTERIM
	#define INTERIM_TABLES  // comment if you dont want table trunc and index creation
#endif

// Forward reference; no definition
class value_list;
class cdr_data;
class bill_block;
class bill_item_block;
class bulk_discount_call;
class bulk_call_credits;
class bulk_discount;
class bill_cycle;  


/*
const char* VPP="VPP";
const char* 1FOR1="1FOR1";
*/

typedef enum
{
	NATIONAL_CALL				= 0x0,
	INTERNATIONAL_CALL			= 0x1,
	MANUAL_NATIONAL_CALL		= 0x2,
	MANUAL_INTERNATIONAL_CALL	= 0x3,
	INDICATOR_NOT_APPLICABLE	= 0xf
} e_origin_of_call_indicator;

typedef enum
{
	ORIGINATING_CALL_RADIO					= 0x0,
	TERMINATING_CALL_RADIO					= 0x1,
	MSC_FORWARDED_TERMINATING_CALL			= 0x2,
	REROUTED_TERMINATING_CALL				= 0x4,
	GMSC_FORWARDED_TERMINATING_CALL			= 0x6,
	ORIGINATING_CALL_RADIO_WITH_HOT_BILLING = 0xd,
	TERMINATING_CALL_WITH_HOT_BILLING		= 0xe,
	MSC_FORWARDED_TERMINATING_CALL_RADIO_WITH_HOT_BILLING=0xf,
	TC_ANY									= 0x7	// defined for bulk mins
} e_type_of_call;

typedef enum
{
	MSC				= 0x0,
	GMSC			= 0x1,
	IWGMSC			= 0x3
} e_type_of_msc;

typedef enum
{
	TELEPHONY		= 0x11,
	EMERGENCY_CALLS	= 0x12,
	SMS_MT_PP		= 0x21,
	SMS_MO_PP		= 0x22,
	FAX_G3_SPEECH	= 0x61,
	AUTO_FAX_G3		= 0x62,
	VOICE_MAIL		= 0x77,
	NOT_USED		= 0xff
} e_required_teleservice;

typedef enum
{
	CPE_NATIONAL		= 0xa0, // 160
	CPE_INTERNATIONAL	= 0x90  // 144
} e_call_partner_ext; 

typedef enum
{
	PEAK		= 0x0,
	OFF_PEAK	= 0x1,
	TB_ANY		= 0x2	// defined for discounting
} e_time_band;

typedef map<string, double> VALUE_LIST_DEF;

// list of values that go into a bill
class value_list
{
	string id;
	VALUE_LIST_DEF v_list;
public:
	double sum();					// the total in a value list
	bool append(value_list a);		// appends a value list
	bool add(string item, double value);
	void print();
	void clear();
	double get_value(string &item);
	double& operator[](string a);	// use only for setting values.
	void set_id(string i);			// helps the de bug process to locate what type it is
	void db_arrary_populate(int &item, bill_item_block *b);
};


// Connections -- begin -------------------------------------------------------
class connection_detail
{
public:
	int		account_no;
	float	contract_charge;
	string	package_code;
	string  contract_end_date;
	string	tax_group;
	string  corporate_bill_code;
	string	value_plus_plus;		// are people eligbile for value plus plus
	string	connection_status;
	bool	bulk_discount;			// are folks eligible for bulk discount
	void	init();
};


class call_summary
{
public:
	float air;				// automatic international ROAMING
	float out_d_d;			// out going dialog to dialog
	float out_d_nd;			// out going dialog to non dialog
	float in_f_d;			// incomming from non dialog
	float in_f_nd;			// in comming from non dialog
	float re_r_int;			// re routed internaltional
	float international;	// idd calls
	float sms;				// sms charges
	float oth;				// un_classified
	float anyware;			// anyware
	float call_charges;		// total telphony charges
	float ofo_out_units;	// one for one outgoing units
	float ofo_incomming;	// one for one incomming value
	float ofo_discount;
	float vpp_outgoing;		// value plus plus
	float vpp_incomming;	// value plus plus
	float vpp_idd;			// value plus plus
	float vpp_discount;
	float gprs;				// total of gprs calls

	void  add_to_summary();
	void  init();
	void  classify_calls(cdr_data *cdr);
	float one_for_one_classify(cdr_data *cdr);
	float value_p_p_classify(cdr_data *cdr);
};


class charge_summary
{
public:
	float brought_forward;		// B_F
	float payments;				// PAY
	float total_previous_month; // TOT_PM
	float misc_charges;			// MSC_CHG
	float contract_charges;		// CON_CHG
	float discount_surcharge;	// DISSUR_CHG  discounts+interest;	
	float taxable_value;
	float gst;
	float nsl;
	float tax;					// GOVTAX_TOT tax	
	float total_charges;		// CUR_CHG	total_current_charge()
	float total_due;			// AMT_DUE
	float total_monthly_rental;	// monthly pakage rental + value added services
	float charity;
	float rental_pro_rate;		// PRO_RATE  for the within bill cycle services
	float package_rental;		// PKG_RENTAL for the month
	float interest;				// INT_LATE late payment interest
	float adjustment;

	float discounts;			// DISCOUNT 1FOR1, value plus plus
	float package_discounts;	// For percentage discounts on packages
	float bulk_discounts;		// Bulk discounts
	float sms;					// SMS_VAS	 value added SMS
	bool  vpp_payment; 
	bool  charge_rental;		// cases where disconnections has occured and there is outstanding
								// so bills have to be generated and printed.
	value_list rent_breakup;
	float other_charges;		 // externally billable items
	float other_charges_taxable; // taxable component of other charges
	float get_discounts();


	void init();
	void add_to_summary();
	charge_summary();
	float get_rental();
	float get_contract_charge();
};

class bulk_discount_call
{
public:
	string			call_time;		// for one second only one call hence no multi map
	e_type_of_call	call_type_id;	// (in, out, any) 
	e_time_band		time_band;		// (pk, opk,any)
	bool			dialog;
	int				charged_units;
	int				units;
	float			charge;			// in cents
	bool			available;		// has not been used in discounting.
	bool operator < (const bulk_discount_call  &t) const;
	bulk_discount_call();
//	bool assign_call(cdr_data *cdr);
};

//typedef multimap<string, bulk_discount_rule> BULK_DISCOUNT_DEF;


// units available for discounting.
class bulk_min_balance
{
public:
	e_time_band			time_band;
	e_type_of_call  	call_type_id;
	float				balance;
	float				used;	// units that have been discounted
	float				discount;    
	inline bool match_tb(e_time_band t);
	inline bool match_tc(e_type_of_call t);
	bulk_min_balance();
};

// load filter
// a) local calls.	=  NATIONAL_CALL
// b) type of call =  TELPHONY

typedef multiset<bulk_discount_call> DISCOUNTABLE_CALLS_DEF;
typedef list<bulk_min_balance> BULK_CREDITS_DEF;


class bulk_discount
{
public:
	DISCOUNTABLE_CALLS_DEF	discountable_calls;
	BULK_CREDITS_DEF		min_balance;
	float	total_discount_value;
	float compute_bulk_discount();
	bool insert_cdr(cdr_data *cdr);
	bool insert_balance(char* tb, char* ctid, float bal);
	void mark_value_pp();
	float compute_one_for_one();
};

class pkg_discount_data
{
public:
	double discount_percent;
	pkg_discount_data();
};

class pkg_discount_key
{
public:
	string package_code;
	string bill_item;
	double limit;
	bool operator < (const pkg_discount_key &s) const;
	pkg_discount_key();
};

ostream& operator<<(ostream& out, pkg_discount_key x);

typedef map<pkg_discount_key , pkg_discount_data > PKG_DISCOUNT_DEF;
typedef multimap<string, string> PKG_DISCOUNT_INDX_DEF;

class package_discount  
{
	string bill_date;
	PKG_DISCOUNT_DEF discounts;
	PKG_DISCOUNT_INDX_DEF pkg_index;
public:
	package_discount(string br_date);
	bool insert(pkg_discount_key &k, pkg_discount_data &d); 
	bool compute_package_discount(string &package, string &bill_item, double value, double &discount);
	bool make_short_index();
	void db_read();
	bool apply_discount(string &package);
	double apply_discount(string &package, value_list &discountable_items);
};


class connection_state
{
public:
	connection_detail connection;
	call_summary call;
	charge_summary charge;
	bulk_discount blk_discount;

	add_to_summary();

	float set_contract_charge();
	float get_nsl_taxable_value();
	float get_gst_taxable_value();
	float total_current_charge();
	float get_charity_amount();
	float get_total_due();
	float get_total_previous_month();
	float compute_tax();
};


typedef map<int,connection_state> CONNECTION_DEF;
typedef map<string,double> BILL_SUMMARY_DEF;

class connections
{
public:
	string	start_date;
	string	end_date; 
	string	due_date;
	string  bill_date;
//	int start_ac_no;
//	int end_ac_no;

public:
	connection_state *current;
	CONNECTION_DEF::iterator i_current;

	CONNECTION_DEF conn;
	//static	BILL_SUMMARY_DEF summary;
	value_list summary;
	connections();

	void populate_taxes_discounts_charges();
	void populate_useage();


	void	print();

	void	db_read_connections();
	void	db_read_fixed_cost();
	int		db_update_balance();
	bool	db_external_remitance();
	bool	db_is_value_plus_plus(string bill_date, int due_days);
	void	prepare_db_log_state();
	float	db_log_state();

	void	insert(int account_no, connection_detail &c_d );
	int		get_current_ac_no();
	bool	set_current(int account_no);

	int		start();
	bool	next();
	connections(string start_dte, string end_dte);

	void	print_detail();

	// cal data records
	void	db_read_cdrs();
	void	db_read_tap();
	void	db_read_anyware();
	
	void	db_read_package_rental();
	void	db_read_value_add_rental();
	void	db_read_payments();
	void	db_read_interest();
	void	db_read_adjustments();
	void	db_read_pro_rates();
	void	db_read_value_pp();
	void	db_read_gprs();
	void	db_read_bulk_discount_get_balance();
	void	db_insert_bill_master();
	void	db_insert_bill_items();
	void    db_insert_bulk_discount_usage();

	void	db_insert_bill_block(int bills_pending_insert, bill_block *b);
//	void	db_arrary_populate(int &item, bill_item_block *b);
	void	db_insert_bill_items_block(int bill_items_pending_insert, bill_item_block *b);
	void	db_read_interim_bill_date();
	void	db_read_contract_charge_pro_rate();	 
	void    enable_bulk_discount_bill();

	void	db_truncate_tables();
	void	db_create_indexes();
};

ostream& operator<<(ostream& out, connection_detail x);

// Connections -- end ---------------------------------------------------------


// cdr -- start ---------------------------------------------------------------

class cdr_data
{
public:
	int		account_no;
	int		termination_type;
	int		units;
	int		charged_units;
	float	charge;
	string	call_partner_id;
	int		duration;
	string	call_time;
	string	ms_location;
	int		call_type_id;
	string	network_id;
	string	rate_rule_id;
	int		service_type_id;
	int		locale_id;
};
ostream& operator<<(ostream& out, cdr_data x);

// cdr -- end -----------------------------------------------------------------


// tax -- start ---------------------------------------------------------------
class tax_key
{
public:
	string	group;
	string	type;
	int		priority;
//	float	rate;			// the tax rate value
	float	slab;			// applicable to value and above
	bool operator < (const tax_key &s) const;
	void init();
};


typedef map<tax_key, float, less<tax_key> > TAX_DEF;
class taxes
{
public:
	TAX_DEF taxation_rules;
	map<string, float> computed_taxes;
	bool insert(tax_key &c, float rate);
	float simple_tax_compute(connection_state *c_s);

	void db_read();
	void print();
	float total();
};
ostream& operator<<(ostream& out, tax_key x);

/*
// computed taxes 
class result_list
{
	class result_type
	{
	public:
		string result_code;
		float result_value;
	};
public:
	list<result_type> results;
	list<result_type>::iterator current;
	insert(string result_code, float result_value);
	rewind();
	erase();
	print();
	bool get_next(string &result_code, float result_value);
};
*/

// Termination -- start -----------------------------------------------------
typedef map<int, string, less<int> > H_TEMP_TERM_DEF;

class temporary_termination
{
public:
	H_TEMP_TERM_DEF h_temp_term;
	bool insert(int d, string bill_start_date);
	bool is_rent_chargeable(int ac, string dte);
	void db_read();
	void print();
};
// Termination -- end ---------------------------------------------------------



// double stores date as 20001201595959 YYYYMMDDHHMISS
// time_t is too complicated
// Holiday priorities -- start ------------------------------------------------
typedef map<int, string, less<int> > H_DAY_TYPE_DEF;

class holiday_day_types
{
public:
	H_DAY_TYPE_DEF h_day_type;
	bool insert(int d, string type);
	string get_day_type(string &dte);
	void db_read();
	void print();
};
// Holiday priorties -- end ---------------------------------------------------


// Holiday groups -- start ----------------------------------------------------
class holiday_group_data
{
public:
	string group;
	string day_id;
	bool operator < (const holiday_group_data  &s) const;
};

typedef set<holiday_group_data, less<holiday_group_data> > H_GROUP_DEF;

class holiday_groups
{
public:
	H_GROUP_DEF h_group;
	bool insert(holiday_group_data d);
	bool is_in_group(string group, string day_id);
	void db_read();
	void print();
};



typedef set<int> ACC_DEF;
// keeps the account numbers for bill generation management
class bill_cycle
{
public:
	string first_cdr_date;
	string last_cdr_date;
	string pay_date;      // payment due on
	string bill_cycle_code;
	string bill_on_date;  // bill date
	int run_no;
	
	ACC_DEF account_numbers;
	ACC_DEF::iterator current;

	bill_cycle(string b_r_c);
	string get_bill_cycle_code();
	bool get_current_move_next(int &a);
	int  reset();	// set current to start
//	insert(int ac_no);
	void db_read();
	void db_read_account_no_range(int start, int end);
	void print();
	void print_dates();
	get_cycle_info(string &t_bill_date, int &t_run_id, string &t_pay_date, string &t_first_cdr, string &t_last_cdr);
	int db_pre_bill();
	int db_post_bill(int bills);
};

class bill_block
{
public:
	char  bill_no[50];	
	char  client_code[50];
 	int   account_no;
	char  bill_date[50];
	char  start_date[50];
	char  end_date[50];
	char  due_date[50];
	float balance_bf;
	float bill_payments;
	char  br_code[50];	
	float total_bill_value;	
	float balance_cf;
	int	  run_no;	
	char  corporate_bill_code[50];
	float idd;
	void set_bill_block(connection_state *c);
};


class bill_item_block
{
public:
	char	bill_no[20];
	char	item_code[20];
	float	value;	
	void set_bill_item_blocks();
};

// misc helper functions to be subsequently grouped

char* get_invoice_no(char *buf);

class bulk_discount_rule
{
public:
	e_time_band			time_band;
	e_type_of_call  	type_of_call;
	bool				one_for_one;
	bool				value_pp;
};

class oth_chg_data
{
public:
	double amount;
	double operator_fee;
	bool   taxable;
	string bill_item;
	oth_chg_data();
};

typedef multimap<int, oth_chg_data> OTH_CHG_DEF;


class tot_oth_chg_key
{
public:
	int account_no;
	string bill_item;
	bool operator < (const tot_oth_chg_key  &t) const;
};

typedef map<tot_oth_chg_key, oth_chg_data> TOT_OTH_CHG_DEF;


class other_charges
{
	string start_date;
	string end_date;
	OTH_CHG_DEF  other_chg;
	TOT_OTH_CHG_DEF temp_totals;
public:
	void db_read();						// read in the suuff
	double get_total_taxable_value();	// just to compute taxes
	double get_total_charge(value_list &v);
	bool totalise(int ac_no);			// collect only a account numbers data;
	bool insert(int ac_no, oth_chg_data d);
	other_charges(string start, string end);
};





