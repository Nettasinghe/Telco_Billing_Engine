

//////////////////////////////////////////////////////////////////////
//
// package_discount.cpp: implementation of the package_discount class.
// discounts on a tiered scale for a package any number of bill items
// Telco Billing Engine
// developer - Chandika Nettasinghe
// development - 1998-2000
//
//////////////////////////////////////////////////////////////////////

#include "db_data_containers.h"
#include <math.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

package_discount::package_discount(string br_date)
{
	bill_date = br_date;
}


//////////////////////////////////////////////////////////////////////
// compute methods
//////////////////////////////////////////////////////////////////////


pkg_discount_data::pkg_discount_data()
{
	discount_percent=0;
}

// keep in a ordered data structure.
bool pkg_discount_key::operator < (const  pkg_discount_key &s)  const
{
	if(package_code < s.package_code)
		return true;
	else if	((package_code == s.package_code) && (bill_item < s.bill_item))
		return true;
	else if	((package_code == s.package_code) && (bill_item == s.bill_item) && (limit < s.limit))
		return true;

	return false;
}

ostream& operator<<(ostream& out, pkg_discount_key x)
{
	out<<x.package_code<<", "<<x.bill_item<<", "<<x.bill_item;
	return(out);
}


pkg_discount_key::pkg_discount_key()
{
	package_code = "";
	bill_item = "";
	limit=0;
}


bool package_discount::compute_package_discount(string &package, string &bill_item, double value, double &discount)
{
  PKG_DISCOUNT_DEF::iterator i;

  pkg_discount_key k;
  pkg_discount_data d;

  k.package_code = package;
  k.bill_item = bill_item;
  k.limit = value;

  i=discounts.upper_bound(k);

  if( i==discounts.end())
  { 
	  //cout<<" No discounts applicable "<<endl;
	  discount=0;
	  return false;
  }
  else
  {
	  // money is kept in cents, so remove fractional parts
	 discount=(-1)*floor(value*(*i).second.discount_percent)/100.0;
  }
	return true;
}


bool package_discount::insert(pkg_discount_key &k, pkg_discount_data &d  )
{
	pair<PKG_DISCOUNT_DEF::iterator, bool> p;
	p=discounts.insert(make_pair(k, d));

	bool err_free = true;
	if (p.second==false)
	{
		cout<<"ERR: duplicate package discount "<<k<<endl;
		err_free=false;
	}
	return err_free;
}


// temp artifact to help in removing some data duplicates
class key 
{
public:
	string package_code;
	string bill_item;
	bool operator < (const key &s) const
	{
		if(package_code < s.package_code)
			return true;
		else if	((package_code == s.package_code) && (bill_item < s.bill_item))
			return true;
		return false;
	}
};

// in a very crude way constructs a quick look up index to
// find which bulk discounts are applicable to a package
// it a bit tortorus but faster to write than custom code
// a) inset in unique set, if insert fails it is a duplicate, then dont do (b)
// b) make a multipmap so all discountable bill items for a package can be iterated through.
// called in db load to make it transparent.
bool package_discount::make_short_index()
{
	// data structure to weed out the duplicates
	typedef set<key> PKG_DISCOUNT_CONSTRAIN_DEF;
	pair<PKG_DISCOUNT_CONSTRAIN_DEF::iterator, bool> p;

	PKG_DISCOUNT_CONSTRAIN_DEF constrain;

	key k;

	// weed out the duplicates that arrive from the multiple limits
	for(PKG_DISCOUNT_DEF::iterator i=discounts.begin(); i!=discounts.end(); i++)
	{
		k.package_code	= (*i).first.package_code;
		k.bill_item		= (*i).first.bill_item;

		p=constrain.insert(k);
		// if insert sucessfull p.second==true
		// put in only unique pagkage and bill_item pairs
		// multimap allows iteration for a package so all discounts can be found
		if(p.second==true) 
		{
			pkg_index.insert(make_pair(k.package_code,k.bill_item));
		}
	}
	return true;
}

// applies the discounts applicable for the package.
// and returns a list of discounted values.
// finds the bill items and computes the discount and enters it to bill items

// all package discounts are prefixed with PD_
// discountable items are all the items in the bill that can be discounted.
double package_discount::apply_discount(string &package, value_list &discountable_items )
{
	// find if package is applicable for discounts
	PKG_DISCOUNT_INDX_DEF::iterator i;
	string discount_type, bill_item;
	double discount=0, total_discount=0;

	//discounts.clear();  // get rid of any previous data
	for(i=pkg_index.equal_range(package).first; i!=pkg_index.equal_range(package).second; i++)
	{
		bill_item=(*i).second;
		
		compute_package_discount(package, bill_item, discountable_items.get_value(bill_item), discount);
		
		if(discount)
		{
			discount_type = "PD_"+ bill_item;	   // PD_ Package_Discount
			discountable_items[discount_type] = discount;
			total_discount += discount;
		}
	}
	return discount;
}




