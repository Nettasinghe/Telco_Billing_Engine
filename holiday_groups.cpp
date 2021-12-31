

//////////////////////////////////////////////////////////////////////
// 
// holiday_groups.cpp: implementation of the holiday_groups class.
// Telco Billing Engine
// developer - Chandika Nettasinghe
// development - 1998-2000
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"


bool holiday_group_data::operator < (const holiday_group_data &s) const 
{
	if((group < s.group))
		return true;
	else if	((group == s.group) && (day_id < s.day_id) )
		return true;
	return false;
}


ostream& operator<<(ostream& out, holiday_group_data x)
{
	out<<x.group<<", "<<x.day_id;
	return(out);
}


bool holiday_groups::insert(holiday_group_data a)
{
	h_group.insert(a);
/*
	pair<H_GROUP_DEF::iterator, bool> p=h_group.insert(make_pair(group, group));
	bool valid=true;
	if (p.second==false)
	{
		cout<<"ERR: Duplicate holiday group "<<k<<endl;
		valid=false;
	}
*/
	return true;
}



bool holiday_groups::is_in_group(string group, string day_id)
{
	H_GROUP_DEF::iterator i;

	holiday_group_data a;

	a.day_id = day_id;
	a.group  = group;

	i = h_group.find(a);
	
	bool found;
	found = (i != h_group.end());

	if(found)
	{
		return true;
	}
	return found;
}


void holiday_groups::print()
{
	for(H_GROUP_DEF::iterator i=h_group.begin(); i != h_group.end(); i++)
	{
		cout<<"{"<<(*i).group<<"}, {"<<(*i).day_id<<"}"<<endl;
	}
}

