

//////////////////////////////////////////////////////////////////////
//
// value_list.cpp: 
// Any item value pair that has to be processed to make the bill
// Telco Billing Engine
// developer - Chandika Nettasinghe
// development - 1998-2000
//
//////////////////////////////////////////////////////////////////////

#include "db_data_containers.h"


void value_list::set_id(string i)
{
	id=i;
}


double value_list::sum()
{
	VALUE_LIST_DEF::iterator i;
	double sum=0;
	for(i=v_list.begin(); i!=v_list.end(); i++)
	{
		sum += (*i).second;
	}
	return sum;
}


bool value_list::add(string item, double value)
{
	VALUE_LIST_DEF::iterator i;

	pair<VALUE_LIST_DEF::iterator, bool> p;
	p=v_list.insert(make_pair(item, value));

	bool err_free = true;
	if (p.second==false)
	{
		cout<<"ERR: duplicate {"<<item<<"} in {"<<id<<"} value list"<<endl;
		err_free=false;
	}
	return err_free;
}


bool value_list::append(value_list a)
{
	VALUE_LIST_DEF::iterator i;
	pair<VALUE_LIST_DEF::iterator, bool> p;
	bool err_free = true;

	for(i=a.v_list.begin(); i!=a.v_list.end(); i++)
	{
		p=v_list.insert(make_pair((*i).first, (*i).second));
		if (p.second==false)
		{
			cout<<"ERR: duplicate "<<(*i).first<<" in {"<<id<<"} value list"<<endl;
			err_free=false;
		}
	}
	return err_free;
}


void value_list::print()
{
	VALUE_LIST_DEF::iterator i;
	for(i=v_list.begin(); i!=v_list.end(); i++)
	{
		cout<<"{"<<(*i).first<<","<<(*i).second<<"}"<<endl;
	}
}


void value_list::clear()
{
	v_list.clear();
}


double& value_list::operator[](string a)
{
	pair<VALUE_LIST_DEF::iterator, bool> p;
	bool err_free = true;

	p=v_list.insert(make_pair(a, 0));
	if (p.second==false)
	{
		cout<<"ERR: duplicate {"<<a<<"} in {"<<id<<"} value list"<<endl;
		exit(1);
		err_free=false;
	}
	return ((*p.first).second);
}


void value_list::db_arrary_populate(int &item, bill_item_block *b)
{
	char buf[50];

	VALUE_LIST_DEF::iterator i;
	for(i=v_list.begin(); i!=v_list.end(); i++)
	{
		strcpy(b[item].bill_no,get_invoice_no(buf));
		strcpy(b[item].item_code, (*i).first.c_str());
		b[item].value = floor((*i).second)/100;
		item++;
	}
}

double value_list::get_value(string &item)
{
	VALUE_LIST_DEF::iterator i;
	double val;

	i=v_list.find(item);
	if( i != v_list.end())
	{
		val= (*i).second;
		return val;
	}
	return 0;
}
