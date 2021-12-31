
/*

11-jan-2000 ver 0.0.03
merged all exsisting processes to one
	a)	tax server.
	b)	discount server.
	c)	message packer.

12-jan-2000 ver 0.0.04
	a)	TIBCO Rv out 
	b)	out-put changed to XML from troff coded version.

14-jan-2000 ver 0.0.05
	a)	discount computation restructured.

15-jan-2000 ver 0.0.06
	a)	Tax computation redone.

16-jan-2000 ver 0.0.07
	a)	tax put to multimaps with fast search.

26-jan-2000 ver 0.0.13
	a)	array reads for cdr's.

27-jan-2000 ver 0.0.14
	a)	XML format changed to remove with all tag hard codes.

02-feb-2000 ver 0.0.3
	a)	discount limits to put caps on max discounts.

05-feb-2000 ver 0.0.4
	a)	value added services stored proc with prorated rental useage.

06-feb-2000 ver 0.0.5
	a)	conversion factor to convert service useage to discounted units.

20-feb-2000 ver 0.0.6
	a)	out bound tap files read.
	b)	zero rated entries removed from detail and put in bill.

21-feb-2000 ver 0.0.7
	a)	bill run concept added.

24-feb-2000 ver 0.0.8
	a)	fixed un initalised cdr buffer causesing repeted cdrs in bill.

01-mar-2000 ver 0.0.9
	a)	balance update included.
	b)	file names changed on .pc's to be less verbose.

06-mar-2000 ver 0.0.10
	a)	re-routed international -  generated cdr's into bill.

07-mar-2000 ver 0.0.11
	a)	bug in category picking fixed by reading ms_location identity.

11-apr-2000 ver 0.0.12
	a)	multiple database support added.

14-apr-2000 ver 0.0.13
	a)	write to bill summary summary file.

17-apr-2000 ver 0.0.14
	a)	cdr table patitioned.

18-apr-2000 ver 0.0.15
	a)	stored proc to find .
		1)	SMS cost.
		2)	zero rated call units.
		3)	couple phone bug on rental.

05-May-2000 ver 0.0.16
	a)	XML slung out Oracle report writer to produce output

05-May-2000 ver 0.0.17
	a)	write to bill tables grouped to one place looks bad !

12-aug-2000 0.0.21
	a)	company code in bill_master.

14-aug-2000 0.0.22
	a)	value plus plus discount enabled.

15-aug-2000 0.0.23
	a)	speed ehancements (1 sec less per bill in 27 secs).

16-aug-2000 0.0.25
	a)	pro rate fixed.

17-aug-2000 0.0.26,27
	a)	interest added to dis_surcharges.
	b)	discounts put in.


19-aug-2000 1.0.1
	a)	full in memory processing: gut and change.
		speed up from 37 secs per bill to 0.4 sec per bill.
		Production quality at last!!

21-aug-2000 1.0.2
	a)	array inserts takes speed to 30 bills/sec on 500Mhz PIII & SUN E250 Oracle 8i.

22-aug-2000 1.0.3
	a)	selctive account capability.

16-sep-2000 1.0.4
	a)	1 for 1 discount.

8-oct-2000 1.0.5
	a)	enabled negative taxes.

08-dec-2000 1.0.6
	a)	points local and international charges totals (connections.cpp).

15-jan-2001 1.0.7
	a)	Permenent disconnect dont charge rental.

25-feb-2001 1.0.8
	a)	one for one over written as value plus plus when payment eleigible but not
		useage eligible fixed

02-feb-2002 1.0.9
	a)	package rental bill item added
	b)	two character bill prefix (use will be "V0" for single char case)

05-apr-2002 1.0.10
	a)	Gprs added

10-apr-2002 1.0.11
	a)	Other charges eg for pizza hut payment on bill added.

18-apr-2002 1.0.13
	a)	Simple package discounts
	b)	Iterator loops through the connections for billing without start end ac number to
		prevent case of hard limits disrupting bill generation.

28-apr-2002 1.0.14
	a)	bulk mins  

26-may-2002 1.0.15
	a) changed sysdate to bill_period end date for the trx_date in BD_TRX_RAW

27-may-2002 1.0.16
	a) One for one with bulk free mins interaction fixed
	b) Table insert faiulre on bulk free mins accounts fixed

28-may-2002 1.0.17
	a) Interim bill new views added

12-jul-2002 1.0.18
	a) Interim bill date fixed

12-jul-2002 1.0.19
	a) Interim bill date #ifndef made #ifdef

12-jul-2002 1.0.20
	a) Interim bill date format made 8 char	  YYYYMMDD

02-Apr-2003 1.0.21
	a) Interim bill cdr read progess indication made more compact


*/