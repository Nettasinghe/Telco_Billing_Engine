

//////////////////////////////////////////////////////////////////////
//
// charge_summary.cpp: implementation of the charge_summary class.
// Telco Billing Engine
// developer - Chandika Nettasinghe
// development - 1998-2000
//
//////////////////////////////////////////////////////////////////////

#include "db_data_containers.h"

extern int global_invoice_no;


// as defined by kapila on 17-may-2000
void charge_summary::init()
{
	brought_forward			= 0;	// client.balance
	payments				= 0;	// recipting module. bill payment
	total_previous_month	= 0;	// TOT_PM	
	misc_charges			= 0;	// adjusments from bill_charge_adjustments
	contract_charges		= 0;	// differece between min charge and call charge3
	discount_surcharge		= 0;
	taxable_value			= 0;	// total amount liable for taxation
	gst						= 0;
	nsl						= 0;
	tax						= 0;	// computed tax amount
	total_charges			= 0;	// for this bill.
	total_due				= 0;	// bill and brought forward.
	total_monthly_rental	= 0;	// pakage and value aded services
	charity					= 0;
	rental_pro_rate			= 0;
	package_rental			= 0;
	interest				= 0;
	adjustment				= 0;	// adjustments

	discounts				= 0;
	package_discounts		= 0;// For percentage discounts on packages
	bulk_discounts			= 0;		// Bulk discounts

	sms						= 0;
	vpp_payment				= false;
	charge_rental			= true;

	rent_breakup.set_id("Rent breakup");
	other_charges			= 0;   // exteranlly billable items
	other_charges_taxable	= 0;	// taxable value of other charges
}


charge_summary::charge_summary()
{
	init();
}


ostream& operator<<(ostream& out, charge_summary x)
{
	out<<
	"b/f="<<x.brought_forward<<endl
	<<", pay="<<x.payments<<endl
//	<<", surv="<<x.monthly_services<<endl
//	<<", vas="<<x.value_added_services<<endl
//	<<", call="<<x.call_charges<<endl
	<<", misc="<<x.misc_charges<<endl
	<<", cont="<<x.contract_charges<<endl
	<<", discount="<<x.discounts<<endl
	<<", taxable_value="<<x.taxable_value<<endl
	<<", tax="<<x.tax<<endl
	<<", tot="<<x.total_charges<<endl
	<<", due="<<x.total_due<<endl
	<<", charity="<<x.charity<<endl
//	<<", due date="<<x.due_date<<endl
	<<", rent="<<x.get_rental()<<endl
	<<", interest="<<x.interest<<endl;

	return out;
}


float charge_summary::get_rental()
{
	if(charge_rental)
		return total_monthly_rental;

	return 0.0;
}


float charge_summary::get_contract_charge()
{
	if(charge_rental)
		return contract_charges;

	return 0.0;
}

float charge_summary::get_discounts()
{
	return discounts+package_discounts+bulk_discounts;
}




