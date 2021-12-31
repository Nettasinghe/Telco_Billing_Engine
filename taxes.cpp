

//////////////////////////////////////////////////////////////////////
//
// taxes.cpp: implementation of the taxes class.
// Telco Billing Engine
// developer - Chandika Nettasinghe
// development - 1998-2000
//
//////////////////////////////////////////////////////////////////////



#include "db_data_containers.h"
#include <math.h>
#include <stdlib.h>


bool tax_key::operator < (const tax_key &s) const 
{
	if(group < s.group)
		return true;
	else if ((group == s.group) && (priority < s.priority))
		return true;
	else if ((group == s.group) && (priority == s.priority) && (type < s.type))
		return true;
	else if ((group == s.group) && (priority == s.priority) && (type == s.type) && (slab < s.slab))
		return true;
	return false;
}


bool taxes::insert(tax_key &c, float value)
{
    taxation_rules[c]=value;
	return true;
}


void taxes::print()
{
	for(TAX_DEF::iterator i=taxation_rules.begin(); i!=taxation_rules.end(); i++)
		cout<<"{"<<(*i).first<<" -> "<<(*i).second<<"}"<<endl;
}


float taxes::simple_tax_compute(connection_state *c_s)
{
	TAX_DEF::iterator i;
	float taxable_value, tax; 
	float gst_taxable_value=0, nsl_taxable_value=0;

	tax_key current_tax_band;

	// initial conditions 
	bool initial = true;
	computed_taxes.clear(); // init

	string t_grp = c_s->connection.tax_group;

	gst_taxable_value = c_s->get_gst_taxable_value(); // get from bill
	nsl_taxable_value = c_s->get_nsl_taxable_value(); // get from bill

	for(i = taxation_rules.begin(); i != taxation_rules.end(); i++)
	{
		if( (*i).first.group == t_grp)	
		{
			current_tax_band = (*i).first; // debugger friendly assignment

			if(current_tax_band.type == "GST")
				taxable_value = gst_taxable_value;
			else if (current_tax_band.type == "NSL")
				taxable_value = nsl_taxable_value+c_s->charge.gst;

			tax = (*i).second * floor(taxable_value) / 100;
			tax = floor((tax+.5));

			if(current_tax_band.type == "GST")
			{
				//c_s->charge.gst = (tax>0?tax:0);
				c_s->charge.gst = tax;
			}
			else if (current_tax_band.type == "NSL")
			{
				//c_s->charge.nsl = (tax>0?tax:0);
				c_s->charge.nsl = tax;
			}

//			computed_taxes[current_tax_band.type] = (tax>0?tax:0);
			computed_taxes[current_tax_band.type] = tax;
//			c_s->charge.tax += (tax>0?tax:0);
			c_s->charge.tax += tax;
		}
	}
	return c_s->charge.tax; 
}


void tax_key::init()
{
	group = "";
	priority = -1;
	slab = -1;
	type = "";
}


ostream& operator<<(ostream& out, tax_key x)
{
	out<<
	x.group<<", "<<
	x.priority<<", "<<
	x.type<<", "<<
	x.slab;

	return out;
}



float taxes::total()
{
	float tax=0;
	for(map<string, float>::iterator i=computed_taxes.begin(); i!=computed_taxes.end(); i++)
		tax += (*i).second;
	return tax;
}

