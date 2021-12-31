

//////////////////////////////////////////////////////////////////////
//
// holiday_day_types.cpp: implementation of the holiday_day_types class.
// Telco Billing Engine
// developer - Chandika Nettasinghe
// development - 1998-2000
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"


// keep the highest day type for a date so to keep the holidays
// weekdays are weighted the least holidays are the heighest
bool holiday_day_types::insert(int d, string day_type)
{
	pair<H_DAY_TYPE_DEF::iterator, bool> p=h_day_type.insert(make_pair(d, day_type));
	bool valid=true;
	if (p.second==false)
	{
		if ((*p.first).second < day_type)
			(*p.first).second = day_type;
//		cout<<"ERR: Duplicate holiday day "<<d<<endl;
//		valid=false;
	}
	return valid;
}



string holiday_day_types::get_day_type(string &dte)
{
	H_DAY_TYPE_DEF::iterator i;
	string p;

	i=h_day_type.find(atoi(dte.substr(0,4+2+2).c_str()));
	
	bool found;
	found = (i != h_day_type.end());

	if(found)
	{
		p = (*i).second;
	}
	else
	{
		p = "0";		// week day type
	}

	return p;
}


void holiday_day_types::print()
{
	cout<<" holiday priorities size "<<h_day_type.size()<<endl;
	for(H_DAY_TYPE_DEF::iterator i=h_day_type.begin(); i != h_day_type.end(); i++)
	{
		cout<<"{"<<(*i).first<<"}, {"<<(*i).second<<"}"<<endl;
	}
}

