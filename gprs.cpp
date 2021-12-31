

/*
The database table which contains GPRS rated session records is R_RATED_GPRS_CDR.
  
 The following colums of the above table are useful for billing.
  
 (1) IMSI			- to identify subscriber
 (2) charge			- to add up to bill value -(should show in the detailed bill)
 (3) units			- to show in the detailed bill
 (4) call_time		- ( format - YYYYMMDDHHMISS) - to show in the detailed bill
 (5) access_point_name - to show in the detailed bill
 (6) account_no
  
  
 According to Asela,     charge, units, call_time and access_point_name are sufficient to show in the detailed bill.
*/  