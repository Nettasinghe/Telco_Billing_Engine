


//////////////////////////////////////////////////////////////////////
//
// temporary_termination.cpp: 
// Implements the rent charge logic during tempoary terminations 
// connection start == "T"
// Telco Billing Engine
// developer - Chandika Nettasinghe
// development - 1998-2000
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"

/*
typedef map<int, string, less<int> > H_TEMP_TERM_DEF;

class temporary_termination
{
public:
	H_TEMP_TERM_DEF h_temp_term;
	bool insert(int d, string dte);
	bool is_rent_chargeable(int ac, string dte);
	void db_read();
	void print();
};
*/


// keep the latest day for the temporary termination
bool temporary_termination::insert(int d, string dte)
{
	pair<H_TEMP_TERM_DEF::iterator, bool> p=h_temp_term.insert(make_pair(d, dte));
	bool valid=true;
	if (p.second==false)
	{
		if ((*p.first).second < dte)
			(*p.first).second = dte;
	}
	return valid;
}

// if connection type == "T" (Temporay disconnected)
// if no entry do not charge rent (RBS load up)
// if entry and after bill_start disconnect charge rental
// if entry and before bill start disconnect no charge
bool temporary_termination::is_rent_chargeable(int ac, string bill_start_date)
{
	H_TEMP_TERM_DEF::iterator i;
	string p;

	i=h_temp_term.find(ac);

	if(i != h_temp_term.end())				// found
	{
		if((*i).second >= bill_start_date)	// terminated after bill start
			return true;
		else
			return false;					// terminated before bill start
	}

	return false; // no entry a uploaded terminated state (do not charge)
}


void temporary_termination::print()
{
	cout<<" Tempory disconnections "<<h_temp_term.size()<<endl;
	for(H_TEMP_TERM_DEF::iterator i=h_temp_term.begin(); i != h_temp_term.end(); i++)
	{
		cout<<"{"<<(*i).first<<"}, {"<<(*i).second<<"}"<<endl;
	}
}

