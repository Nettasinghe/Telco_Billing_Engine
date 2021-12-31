

//////////////////////////////////////////////////////////////////////
// 
// other_charges.cpp: implementation of the other_charges class.
// Telco Billing Engine
// developer - Chandika Nettasinghe
// development - 1998-2000
//
//////////////////////////////////////////////////////////////////////

#include "db_data_containers.h"


// Other charges.cpp
// Add to bill all other charges that need to go in
// e.g e~channeling, pizza hut.. 


other_charges::other_charges(string start, string end)
{
	start_date = start;
	end_date = end;
}
	 
oth_chg_data::oth_chg_data()
{
	amount=0;
	operator_fee=0;
	taxable=true;
	bill_item="";
}


bool tot_oth_chg_key::operator < (const tot_oth_chg_key &s) const 
{
	if((account_no < s.account_no))
		return true;
	else if	((account_no == s.account_no) && (bill_item < s.bill_item) )
		return true;
	return false;
}


bool other_charges::insert(int ac_no, oth_chg_data d)
{
	OTH_CHG_DEF::iterator i;
	i=other_chg.insert(make_pair(ac_no,d));
	if(i!=other_chg.end())
	{
		return true;
	}
	cout<<" Cant insert into other charges "<<endl;
	exit(1);
	return false; // keep compiler happy
}

// this is crude but works. 
// ideally it shoud be summarised to client at load up like in cdrs
// but volume is small so it works.
// totalise for a account number 
// and summarise a account by "bill item" sub totals
// note the [] operator in the map does the summarising.
bool other_charges::totalise(int ac_no)
{
	temp_totals.clear();
	OTH_CHG_DEF::iterator i;
	tot_oth_chg_key k;

	k.account_no = ac_no;
	oth_chg_data d;

	for(i=other_chg.equal_range(ac_no).first; i!=other_chg.equal_range(ac_no).second; i++)
	{
		d = (*i).second;
		k.bill_item = d.bill_item;
		temp_totals[k].amount += d.amount;
		temp_totals[k].operator_fee += d.operator_fee;
		temp_totals[k].taxable = d.taxable;
	} 
	return (temp_totals.size() > 0 ? true: false);
}

// if tax applicable only then do you add to
// taxable total
double other_charges::get_total_taxable_value()
{
	TOT_OTH_CHG_DEF::iterator i;

	double tax_total=0;
	oth_chg_data d;

	for(i=temp_totals.begin(); i!=temp_totals.end(); i++)
	{
		d=(*i).second;
		if(d.taxable==true)
		{
			tax_total += d.operator_fee;
		}
	}

	return tax_total;
}

// get value list to put in bill summary.
// generate
// a) summary per institution (created in totalise)
// b) total summary for all other charges
// "O_" for easy identifaction in bill summary items
double other_charges::get_total_charge(value_list &v)
{
	TOT_OTH_CHG_DEF::iterator i;

	double operator_fee_total=0, amount_total=0;
	oth_chg_data d;
	string b_item;

	for(i=temp_totals.begin(); i!=temp_totals.end(); i++)
	{
		d = (*i).second;
		b_item = (*i).first.bill_item;

		v["O_O_" + b_item] = d.operator_fee;		// O = Operator fee {summary page}
		v["O_I_" + b_item] = d.amount;			    // I = intitution fee {summary page} 
		operator_fee_total += d.operator_fee;
		amount_total += d.amount;
	}
	v["O_GI"] = amount_total;			// GI = Instittion grand total {front page}
	v["O_GO"] = operator_fee_total;		// GO = Operator fee Grand total {front page}

	return amount_total + operator_fee_total;
}

















