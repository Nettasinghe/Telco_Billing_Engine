
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned long magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[37];
};
static const struct sqlcxp sqlfpn =
{
    36,
    "d:\\src\\turbo_bill\\db_talk_interim.pc"
};


static unsigned long sqlctx = 1781505517;


static struct sqlexd {
   unsigned int   sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
            void  *sqhstv[16];
   unsigned int   sqhstl[16];
            int   sqhsts[16];
            void  *sqindv[16];
            int   sqinds[16];
   unsigned int   sqharm[16];
   unsigned int   *sqharc[16];
   unsigned short  sqadto[16];
   unsigned short  sqtdso[16];
} sqlstm = {10,16};

// Prototypes
extern "C" {
  void sqlcxt (void **, unsigned long *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlcx2t(void **, unsigned long *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlbuft(void **, char *);
  void sqlgs2t(void **, char *);
  void sqlorat(void **, unsigned long *, void *);
}

// Forms Interface
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern "C" { void sqliem(char *, int *); }

 static const char *sq0008 = 
"select ACCOUNT_NO ,TERMINATION_TYPE ,UNITS ,CHARGE ,CALL_PARTNER_ID ,DURATIO\
N ,CALL_TIME ,CALL_TYPE_ID ,NETWORK_ID ,SERVICE_TYPE_ID ,LOCALE_ID ,MS_LOCATIO\
N ,CHARGED_UNITS  from BULK_BILL_INTERIM_RATED_CDR_V where (CALL_TIME>=:b0 and\
 CALL_TIME<=(:b1||'235959'))           ";

 static const char *sq0009 = 
"select ACCOUNT_NO ,CHARGE  from bill_fast_gprs_cdrs_v where (CALL_TIME>=:b0 \
and CALL_TIME<=(:b1||'235959'))           ";

 static const char *sq0010 = 
"select ACCOUNT_NO ,CHARGE  from bill_fast_tap_cdrs_v where (RATED_TIME>=:b0 \
and RATED_TIME<=(:b1||'235959'))           ";

 static const char *sq0011 = 
"select ACCOUNT_NO ,CHARGE  from bill_fast_anyware_charges_v where (CALL_TIME\
>=:b0 and CALL_TIME<=(:b1||'235959'))           ";

 static const char *sq0012 = 
"select ACCOUNT_NO ,PACKAGE_CODE ,CONTRACT_CHARGE ,CONTRACT_END_DATE ,TAX_GRO\
UP ,CORPORATE_BILL_CODE ,VALUE_PLUS_PLUS ,CONNECTION_STATUS  from BILL_INTERIM\
_CONNECTIONS_V where  not (CONNECTION_STATUS='D' and NVL(DISCONNECTED_DATE,TO_\
DATE('20100101','YYYYMMDD'))<TO_DATE(:b0,'YYYYMMDD'))           ";

 static const char *sq0013 = 
"select ACCOUNT_NO ,RENTAL  from bill_fast_package_rental_v            ";

 static const char *sq0014 = 
"select ACCOUNT_NO ,RENTAL ,(SERVICE_CODE||'_RENT')  from bill_fast_value_add\
_rental_v where (RENTAL_ACTIVATION_DATE<to_date(:b0,'YYYYMMDD') or TRUNC(RENTA\
L_ACTIVATION_DATE) between to_date(:b1,'YYYYMMDD') and to_date(:b0,'YYYYMMDD')\
)           ";

 static const char *sq0015 = 
"select ACCOUNT_NO ,PAYMENT ,BALANCE_BF  from bill_interim_payments_v        \
    ";

 static const char *sq0016 = 
"select ACCOUNT_NO ,INTEREST  from bill_fast_interest_v where INTEREST_DATE b\
etween to_date(:b0,'YYYYMMDD') and to_date(:b1,'YYYYMMDD')           ";

 static const char *sq0017 = 
"select ACCOUNT_NO ,TIME_BAND ,CALL_TYPE_ID ,BALANCE  from bd_minute_balance \
           ";

 static const char *sq0019 = 
"select ACCOUNT_NO ,ADJUSTMENT  from bill_fast_account_adj_v where TRUNC(APPR\
OVED_DATE) between to_date(:b0,'YYYYMMDD') and to_date(:b1,'YYYYMMDD')        \
   ";

 static const char *sq0020 = 
"select ACCOUNT_NO ,pro_rate  from bill_fast_pro_rate_v where TRUNC(APPROVED_\
DATE) between to_date(:b0,'YYYYMMDD') and to_date(:b1,'YYYYMMDD')           ";

 static const char *sq0021 = 
"select ACCOUNT_NO ,(pro_rate* 100)  from bill_fast_contract_pro_rate_v where\
 START_DATE between :b0 and :b1           ";

 static const char *sq0022 = 
"select ACCOUNT_NO  from bill_fast_value_plus_paid_v where TRUNC(bill_date) b\
etween to_date(:b0,'YYYYMMDD') and to_date(:b1,'YYYYMMDD')           ";

 static const char *sq0023 = 
"select HOLIDAY_DATE ,DAY_ID  from R_HOLIDAYS_V            ";

 static const char *sq0024 = 
"select CONN_ACCOUNT_NO ,to_char(DISCONNECTION_DATE,'YYYYMMDD')  from DISCONN\
ECTION_HISTORY where DISCONNECTION_TYPE='T'           ";

 static const char *sq0025 = 
"select package_code ,bill_item ,limit ,discount_percent  from bill_fast_disc\
ount_packages_v where (start_date<=:b0 and end_date>=:b0)           ";

 static const char *sq0026 = 
"select account_no ,item_code ,amount ,operator_fee ,taxable_op_fee  from bil\
l_fast_other_charge_v where payment_date between :b0 and :b1           ";

 static const char *sq0027 = 
"select GROUP_ID ,DAY_ID  from r_d_holiday_group_days            ";

 static const char *sq0028 = 
"select NVL(TAX_TYPE,'*') ,NVL(RATE,0) ,NVL(SLAB,0) ,TAX_GROUP ,PRIORITY  fro\
m R_TAX_DEFS_V            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{10,4146,0,0,0,
5,0,0,1,0,0,32,57,0,0,0,0,0,1,0,
20,0,0,2,0,0,27,71,0,0,4,4,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,1,5,0,
0,1,10,0,0,1,10,0,0,1,10,0,0,
64,0,0,3,0,0,27,83,0,0,4,4,0,3,6,82,65,84,73,78,71,1,5,0,0,1,10,0,0,1,10,0,0,1,
10,0,0,
101,0,0,4,0,0,30,90,0,0,0,0,0,3,6,82,65,84,73,78,71,
122,0,0,5,0,0,30,99,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
150,0,0,6,127,0,6,118,0,0,7,7,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,3,
5,0,0,3,5,0,0,3,5,0,0,3,3,0,0,3,5,0,0,3,5,0,0,3,5,0,0,
206,0,0,7,64,0,6,158,0,0,2,2,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,3,5,
0,0,3,3,0,0,
242,0,0,8,271,0,9,241,0,0,2,2,0,3,6,82,65,84,73,78,71,1,5,0,0,1,5,0,0,
271,0,0,8,0,0,13,246,0,0,13,0,0,3,6,82,65,84,73,78,71,2,3,0,0,2,3,0,0,2,3,0,0,
2,4,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,3,0,
0,
344,0,0,8,0,0,15,292,0,0,0,0,0,3,6,82,65,84,73,78,71,
365,0,0,9,118,0,9,335,0,0,2,2,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,1,
5,0,0,1,5,0,0,
401,0,0,9,0,0,13,341,0,0,2,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,3,
0,0,2,4,0,0,
437,0,0,9,0,0,15,356,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
465,0,0,10,119,0,9,401,0,0,2,2,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,1,
5,0,0,1,5,0,0,
501,0,0,10,0,0,13,407,0,0,2,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
3,0,0,2,4,0,0,
537,0,0,10,0,0,15,423,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
565,0,0,11,124,0,9,470,0,0,2,2,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,1,
5,0,0,1,5,0,0,
601,0,0,11,0,0,13,476,0,0,2,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
3,0,0,2,4,0,0,
637,0,0,11,0,0,15,490,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
665,0,0,12,296,0,9,558,0,0,1,1,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,1,
5,0,0,
697,0,0,12,0,0,13,566,0,0,8,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
3,0,0,2,5,0,0,2,4,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,
757,0,0,12,0,0,15,587,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
785,0,0,13,70,0,9,623,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
813,0,0,13,0,0,13,628,0,0,2,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
3,0,0,2,4,0,0,
849,0,0,13,0,0,15,644,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
877,0,0,14,244,0,9,693,0,0,3,3,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,1,
5,0,0,1,5,0,0,1,5,0,0,
917,0,0,14,0,0,13,699,0,0,3,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
3,0,0,2,4,0,0,2,5,0,0,
957,0,0,14,0,0,15,716,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
985,0,0,15,80,0,9,755,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1013,0,0,15,0,0,13,761,0,0,3,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
3,0,0,2,4,0,0,2,4,0,0,
1053,0,0,15,0,0,15,778,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1081,0,0,16,145,0,9,820,0,0,2,2,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1,5,0,0,1,5,0,0,
1117,0,0,16,0,0,13,826,0,0,2,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
3,0,0,2,4,0,0,
1153,0,0,16,0,0,15,841,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1181,0,0,17,87,0,9,882,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1209,0,0,17,0,0,13,888,0,0,4,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,2,
3,0,0,2,5,0,0,2,5,0,0,2,4,0,0,
1253,0,0,17,0,0,15,905,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1281,0,0,18,242,0,6,957,0,0,6,6,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
3,5,0,0,3,5,0,0,3,4,0,0,3,3,0,0,3,5,0,0,3,5,0,0,
1333,0,0,19,157,0,9,1008,0,0,2,2,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1,5,0,0,1,5,0,0,
1369,0,0,19,0,0,13,1014,0,0,2,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,3,0,0,2,4,0,0,
1405,0,0,19,0,0,15,1029,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1433,0,0,20,152,0,9,1072,0,0,2,2,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1,5,0,0,1,5,0,0,
1469,0,0,20,0,0,13,1078,0,0,2,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,3,0,0,2,4,0,0,
1505,0,0,20,0,0,15,1093,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1533,0,0,21,118,0,9,1139,0,0,2,2,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1,5,0,0,1,5,0,0,
1569,0,0,21,0,0,13,1145,0,0,2,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,3,0,0,2,4,0,0,
1605,0,0,21,0,0,15,1160,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1633,0,0,22,145,0,9,1202,0,0,2,2,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1,5,0,0,1,5,0,0,
1669,0,0,22,0,0,13,1208,0,0,1,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,3,0,0,
1701,0,0,22,0,0,15,1223,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1729,0,0,23,58,0,9,1247,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1757,0,0,23,0,0,13,1254,0,0,2,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,5,0,0,2,5,0,0,
1793,0,0,23,0,0,15,1258,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1821,0,0,24,130,0,9,1296,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1849,0,0,24,0,0,13,1302,0,0,2,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,3,0,0,2,5,0,0,
1885,0,0,24,0,0,15,1314,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1913,0,0,25,144,0,9,1359,0,0,2,2,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1,5,0,0,1,5,0,0,
1949,0,0,25,0,0,13,1368,0,0,4,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,5,0,0,2,5,0,0,2,4,0,0,2,4,0,0,
1993,0,0,25,0,0,15,1383,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2021,0,0,26,147,0,9,1434,0,0,2,2,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1,5,0,0,1,5,0,0,
2057,0,0,26,0,0,13,1442,0,0,5,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,3,0,0,2,5,0,0,2,4,0,0,2,4,0,0,2,5,0,0,
2105,0,0,26,0,0,15,1457,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2133,0,0,27,64,0,9,1481,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2161,0,0,27,0,0,13,1488,0,0,2,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,5,0,0,2,5,0,0,
2197,0,0,27,0,0,15,1497,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2225,0,0,28,102,0,9,1525,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2253,0,0,28,0,0,13,1531,0,0,5,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,5,0,0,2,4,0,0,2,4,0,0,2,5,0,0,2,3,0,0,
2301,0,0,28,0,0,15,1542,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2329,0,0,29,122,0,3,1626,0,0,16,16,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,
69,1,5,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,4,0,0,1,4,0,0,1,4,
0,0,1,5,0,0,1,4,0,0,1,3,0,0,1,5,0,0,1,5,0,0,1,3,0,0,
2421,0,0,30,0,0,29,1634,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2449,0,0,31,57,0,3,1670,0,0,3,3,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
1,5,0,0,1,5,0,0,1,4,0,0,
2489,0,0,32,0,0,29,1677,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2517,0,0,33,55,0,4,1690,0,0,1,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2,5,0,0,
2549,0,0,34,25,0,1,1719,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2577,0,0,35,29,0,1,1724,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2605,0,0,36,28,0,1,1729,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2633,0,0,37,35,0,1,1734,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,69,
2661,0,0,38,132,0,44,1745,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,
69,
2689,0,0,39,132,0,44,1753,0,0,0,0,0,2,13,67,85,83,84,79,77,69,82,95,67,65,82,
69,
};



// used by the intrim bill

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <oraca.h>
#include <sqlcpr.h>

#include <sqlda.h>
#include <sqlca.h>

/* EXEC SQL DECLARE CUSTOMER_CARE DATABASE; */ 
 
/* EXEC SQL DECLARE rating DATABASE; */ 
 

#ifndef ORA_PROC
	#include "db.h"
	#include "db_data_containers.h"
	extern int			global_invoice_no;
	extern bill_cycle	*gsm_bill_cycle;
	#define BILL_BLOCK_SIZE 100
#endif


#define BUF_LEN		50
#define FETCH_SIZE  10
//#define CDR_FETCH_SIZE 5000
#define CDR_FETCH_SIZE 1000
#define CLIENT_FETCH_SIZE 1000

 
/* EXEC SQL BEGIN DECLARE SECTION; */ 

char *login_cust_care;
char *login_rating;
/* EXEC SQL END DECLARE SECTION; */ 



/* EXEC SQL INCLUDE sqlda;
 */ 
/*
 * $Header: sqlda.h 31-jul-99.19:34:41 apopat Exp $ sqlda.h 
 */

/***************************************************************
*      The SQLDA descriptor definition                         *
*--------------------------------------------------------------*
*      VAX/3B Version                                          *
*                                                              *
*  Copyright (c) 1987, 1997, 1998, 1999 by Oracle Corporation                    *
***************************************************************/


/* NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************
*/

/*  MODIFIED
    apopat     07/31/99 -  [707588] TAB to blanks for OCCS
    lvbcheng   10/27/98 -  change long to int for sqlda
    lvbcheng   08/15/97 -  Move sqlda protos to sqlcpr.h
    lvbcheng   06/25/97 -  Move sqlda protos to this file
    jbasu      01/29/95 -  correct typo
    jbasu      01/27/95 -  correct comment - ub2->sb2
    jbasu      12/12/94 - Bug 217878: note this is an SOSD file
    Morse      12/01/87 - undef L and S for v6 include files
    Richey     07/13/87 - change int defs to long 
    Clare      09/13/84 - Port: Ch types to match SQLLIB structs
    Clare      10/02/86 - Add ifndef SQLDA
*/

#ifndef SQLDA_
#define SQLDA_ 1
 
#ifdef T
# undef T
#endif
#ifdef F
# undef F
#endif

#ifdef S
# undef S
#endif
#ifdef L
# undef L
#endif
 
struct SQLDA {
  /* ub4    */ int        N; /* Descriptor size in number of entries        */
  /* text** */ char     **V; /* Ptr to Arr of addresses of main variables   */
  /* ub4*   */ int       *L; /* Ptr to Arr of lengths of buffers            */
  /* sb2*   */ short     *T; /* Ptr to Arr of types of buffers              */
  /* sb2**  */ short    **I; /* Ptr to Arr of addresses of indicator vars   */
  /* sb4    */ int        F; /* Number of variables found by DESCRIBE       */
  /* text** */ char     **S; /* Ptr to Arr of variable name pointers        */
  /* ub2*   */ short     *M; /* Ptr to Arr of max lengths of var. names     */
  /* ub2*   */ short     *C; /* Ptr to Arr of current lengths of var. names */
  /* text** */ char     **X; /* Ptr to Arr of ind. var. name pointers       */
  /* ub2*   */ short     *Y; /* Ptr to Arr of max lengths of ind. var. names */
  /* ub2*   */ short     *Z; /* Ptr to Arr of cur lengths of ind. var. names */
  };
 
typedef struct SQLDA SQLDA;
 
#endif

/* ----------------- */
/* defines for sqlda */
/* ----------------- */

#define SQLSQLDAAlloc(arg1, arg2, arg3, arg4) sqlaldt(arg1, arg2, arg3, arg4) 

#define SQLSQLDAFree(arg1, arg2) sqlclut(arg1, arg2) 



/* EXEC SQL INCLUDE sqlca;
 */ 
/*
 * $Header: sqlca.h,v 1.3 1994/12/12 19:27:27 jbasu Exp $ sqlca.h 
 */

/* Copyright (c) 1985,1986, 1998 by Oracle Corporation. */
 
/*
NAME
  SQLCA : SQL Communications Area.
FUNCTION
  Contains no code. Oracle fills in the SQLCA with status info
  during the execution of a SQL stmt.
NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************

  If the symbol SQLCA_STORAGE_CLASS is defined, then the SQLCA
  will be defined to have this storage class. For example:
 
    #define SQLCA_STORAGE_CLASS extern
 
  will define the SQLCA as an extern.
 
  If the symbol SQLCA_INIT is defined, then the SQLCA will be
  statically initialized. Although this is not necessary in order
  to use the SQLCA, it is a good pgming practice not to have
  unitialized variables. However, some C compilers/OS's don't
  allow automatic variables to be init'd in this manner. Therefore,
  if you are INCLUDE'ing the SQLCA in a place where it would be
  an automatic AND your C compiler/OS doesn't allow this style
  of initialization, then SQLCA_INIT should be left undefined --
  all others can define SQLCA_INIT if they wish.

  If the symbol SQLCA_NONE is defined, then the SQLCA variable will
  not be defined at all.  The symbol SQLCA_NONE should not be defined
  in source modules that have embedded SQL.  However, source modules
  that have no embedded SQL, but need to manipulate a sqlca struct
  passed in as a parameter, can set the SQLCA_NONE symbol to avoid
  creation of an extraneous sqlca variable.
 
MODIFIED
    lvbcheng   07/31/98 -  long to int
    jbasu      12/12/94 -  Bug 217878: note this is an SOSD file
    losborne   08/11/92 -  No sqlca var if SQLCA_NONE macro set 
  Clare      12/06/84 - Ch SQLCA to not be an extern.
  Clare      10/21/85 - Add initialization.
  Bradbury   01/05/86 - Only initialize when SQLCA_INIT set
  Clare      06/12/86 - Add SQLCA_STORAGE_CLASS option.
*/
 
#ifndef SQLCA
#define SQLCA 1
 
struct   sqlca
         {
         /* ub1 */ char    sqlcaid[8];
         /* b4  */ int     sqlabc;
         /* b4  */ int     sqlcode;
         struct
           {
           /* ub2 */ unsigned short sqlerrml;
           /* ub1 */ char           sqlerrmc[70];
           } sqlerrm;
         /* ub1 */ char    sqlerrp[8];
         /* b4  */ int     sqlerrd[6];
         /* ub1 */ char    sqlwarn[8];
         /* ub1 */ char    sqlext[8];
         };

#ifndef SQLCA_NONE 
#ifdef   SQLCA_STORAGE_CLASS
SQLCA_STORAGE_CLASS struct sqlca sqlca
#else
         struct sqlca sqlca
#endif
 
#ifdef  SQLCA_INIT
         = {
         {'S', 'Q', 'L', 'C', 'A', ' ', ' ', ' '},
         sizeof(struct sqlca),
         0,
         { 0, {0}},
         {'N', 'O', 'T', ' ', 'S', 'E', 'T', ' '},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}
         }
#endif
         ;
#endif
 
#endif
 
/* end SQLCA */

/* EXEC ORACLE OPTION (ORACA=YES); */ 




void sql_error(char *msg)
{
	cout << endl << msg << endl;
	sqlca.sqlerrm.sqlerrmc[sqlca.sqlerrm.sqlerrml] = '\0';
	oraca.orastxt.orastxtc[oraca.orastxt.orastxtl] = '\0';
	oraca.orasfnm.orasfnmc[oraca.orasfnm.orasfnml] = '\0';
	cout << sqlca.sqlerrm.sqlerrmc << endl;
	cout << "in " << oraca.orastxt.orastxtc << endl;
	cout << "on line " << oraca.oraslnr << " of " << oraca.orasfnm.orasfnmc
		 << endl << endl;

	//-- Roll back any pending changes and disconnect from Oracle.

	/* EXEC SQL ROLLBACK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 0;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	exit(1);
}


// Connect to ORACLE. 
void db_connect_cust_care(char *in_login)
{
	login_cust_care = in_login;  // a pointer assignment, in_login has the space acclocation

	/* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error--"); */ 

//	printf("\nConnecting to ORACLE as    : %s\n", login_cust_care); 
	printf("\nConnecting to ORACLE Cust Care\n"); 
 
	/* EXEC SQL CONNECT :login_cust_care AT CUSTOMER_CARE; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )10;
 sqlstm.offset = (unsigned int  )20;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)login_cust_care;
 sqlstm.sqhstl[0] = (unsigned int  )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


}


void db_connect_rating(char *in_login)
{
	login_rating = in_login;  // a pointer assignment, in_login has the space acclocation

	/* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error--"); */ 

//	printf("\nConnecting to ORACLE as    : %s\n", login_rating); 
	printf("\nConnecting to ORACLE as Rating \n"); 
 
	/* EXEC SQL CONNECT :login_rating AT rating; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )10;
 sqlstm.offset = (unsigned int  )64;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)login_rating;
 sqlstm.sqhstl[0] = (unsigned int  )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


}

//-- exit with grace
void db_disconnect_rating()
{
	printf("\nDisconnect from ORACLE as  : %s\n", login_rating);
	/* EXEC SQL AT rating COMMIT WORK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )101;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	//exit(EXIT_SUCCESS);	
}


//- exit with grace
void db_disconnect_cust_care()
{
	printf("\nDisconnect from ORACLE as  : %s\n", login_cust_care);
   /* EXEC SQL AT CUSTOMER_CARE COMMIT WORK RELEASE; */ 

{
   struct sqlexd sqlstm;
   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 10;
   sqlstm.arrsiz = 4;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )122;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 

	//exit(EXIT_SUCCESS);	
}	




int bill_cycle::db_pre_bill()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	char t_bill_date[50], t_pay_date[50], t_br_code[50], t_return[256], t_first[256], t_last[256];
	int t_run_no;
	/* EXEC SQL END DECLARE SECTION; */ 


	strcpy(t_br_code, bill_cycle_code.c_str());

	/* EXEC SQL WHENEVER NOT FOUND GOTO notfound; */ 


	/* EXEC SQL AT CUSTOMER_CARE EXECUTE
	begin
 		:t_return := bill_gen.pre_bill_run(:t_br_code, :t_bill_date, :t_run_no, :t_pay_date, :t_first, :t_last);
	end;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :t_return := bill_gen . pre_bill_run ( :t_br_code , :t\
_bill_date , :t_run_no , :t_pay_date , :t_first , :t_last ) ; end ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )150;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)t_return;
 sqlstm.sqhstl[0] = (unsigned int  )256;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)t_br_code;
 sqlstm.sqhstl[1] = (unsigned int  )50;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)t_bill_date;
 sqlstm.sqhstl[2] = (unsigned int  )50;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)&t_run_no;
 sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         void  *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)t_pay_date;
 sqlstm.sqhstl[4] = (unsigned int  )50;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         void  *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)t_first;
 sqlstm.sqhstl[5] = (unsigned int  )256;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         void  *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)t_last;
 sqlstm.sqhstl[6] = (unsigned int  )256;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         void  *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned int  )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode == 1403) goto notfound;
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	if(strcmp(t_return, "OK"))
	{
		printf("<ERROR> db_pre_bill  %s\n",t_return);
		exit(0);
	}

	bill_on_date	= t_bill_date;
	run_no			= t_run_no;
	pay_date		= t_pay_date;
	first_cdr_date	= t_first;
	last_cdr_date	= t_last;

	printf("\n\n bill=%s pay=%s, first=%s, last=%s\n", t_bill_date, t_pay_date, t_first, t_last);

	return 1;

notfound:
	printf("<ERROR> bill run code not found for %s \n",bill_cycle_code.c_str());
	return 0;
}



int bill_cycle::db_post_bill(int bills)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	int t_bills;
	char t_return[256];
	/* EXEC SQL END DECLARE SECTION; */ 


	t_bills = bills;

	/* EXEC SQL WHENEVER NOT FOUND GOTO notfound; */ 


	/* EXEC SQL AT CUSTOMER_CARE EXECUTE
	begin
 		:t_return := bill_gen.post_bill_run(:t_bills);
	end;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :t_return := bill_gen . post_bill_run ( :t_bills ) ; e\
nd ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )206;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)t_return;
 sqlstm.sqhstl[0] = (unsigned int  )256;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)&t_bills;
 sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode == 1403) goto notfound;
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	if(strcmp(t_return, "OK"))
	{
		printf("<ERROR> db_post_bill  %s\n",t_return);
		exit(0);
	}
	return 1;

notfound:
//	printf("<ERROR> bill run code not found for %s \n",bill_run_code);
	return 0;
}



void connections::db_read_cdrs()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct cdr_t
	{ 
		int account_no;					// number
		int termination_type;			// number(3)
		int	units;						// number
		float charge;					// number(11,2)
		char call_partner_id[BUF_LEN];	// varchar2(20)		-> 2 char missing
		int duration;					// number
		char call_time[BUF_LEN];		// varchar2(14)
		int  call_type_id;				// number(3)
		char network_id[BUF_LEN];		// varchar2(5)
		int  service_type_id;			// number(3)
		int  locale_id;					// number(3)
		char ms_location[BUF_LEN];
		int  charged_units;
	} *a;

	char t_start_date[20], t_end_date[20];
	int rows_to_fetch, rows_before, rows_this_time;

/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	strcpy(t_start_date,start_date.c_str());
	strcpy(t_end_date, end_date.c_str());
 
 	cdr_data cd;

	rows_to_fetch = CDR_FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = CDR_FETCH_SIZE; 

	if((a = new cdr_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for cdr fetch"<<endl;
		exit(0);
	}

 
	/* EXEC SQL 
	AT rating 
	DECLARE  c_cdr CURSOR FOR 
	SELECT	ACCOUNT_NO,
			TERMINATION_TYPE, 
			UNITS, 
			CHARGE,
			CALL_PARTNER_ID, 
			DURATION, 
			CALL_TIME,
			CALL_TYPE_ID,
			NETWORK_ID,
			SERVICE_TYPE_ID,
			LOCALE_ID, 
			MS_LOCATION,
			CHARGED_UNITS
//	FROM	BULK_BILL_RATED_CDR_V 
	FROM	BULK_BILL_INTERIM_RATED_CDR_V  
	WHERE	CALL_TIME >= :t_start_date  AND CALL_TIME <= :t_end_date||'235959'; */ 
 
 
	/* EXEC SQL AT rating  OPEN c_cdr; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0008;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )242;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)t_start_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)t_end_date;
 sqlstm.sqhstl[1] = (unsigned int  )20;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT rating FOR :rows_to_fetch FETCH c_cdr INTO :a; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )271;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&a->account_no;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct cdr_t);
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->termination_type;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct cdr_t);
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&a->units;
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(struct cdr_t);
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)&a->charge;
  sqlstm.sqhstl[3] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[3] = (         int  )sizeof(struct cdr_t);
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)a->call_partner_id;
  sqlstm.sqhstl[4] = (unsigned int  )50;
  sqlstm.sqhsts[4] = (         int  )sizeof(struct cdr_t);
  sqlstm.sqindv[4] = (         void  *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)&a->duration;
  sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(struct cdr_t);
  sqlstm.sqindv[5] = (         void  *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)a->call_time;
  sqlstm.sqhstl[6] = (unsigned int  )50;
  sqlstm.sqhsts[6] = (         int  )sizeof(struct cdr_t);
  sqlstm.sqindv[6] = (         void  *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)&a->call_type_id;
  sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(struct cdr_t);
  sqlstm.sqindv[7] = (         void  *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (         void  *)a->network_id;
  sqlstm.sqhstl[8] = (unsigned int  )50;
  sqlstm.sqhsts[8] = (         int  )sizeof(struct cdr_t);
  sqlstm.sqindv[8] = (         void  *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned int  )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (         void  *)&a->service_type_id;
  sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(struct cdr_t);
  sqlstm.sqindv[9] = (         void  *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned int  )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (         void  *)&a->locale_id;
  sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(struct cdr_t);
  sqlstm.sqindv[10] = (         void  *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned int  )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (         void  *)a->ms_location;
  sqlstm.sqhstl[11] = (unsigned int  )50;
  sqlstm.sqhsts[11] = (         int  )sizeof(struct cdr_t);
  sqlstm.sqindv[11] = (         void  *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned int  )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (         void  *)&a->charged_units;
  sqlstm.sqhstl[12] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(struct cdr_t);
  sqlstm.sqindv[12] = (         void  *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned int  )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		
		if(rows_before%50000 == 0)
		{
			printf(" cdr=%d \n", rows_before);
		}
		else
		{
			printf(".");
		
		}


		for(i=0; i<rows_this_time; i++)
		{
			cd.account_no		= a[i].account_no;					
			cd.termination_type = a[i].termination_type;	
			cd.units			= a[i].units;						
			cd.charge			= a[i].charge;						
			cd.call_partner_id	= a[i].call_partner_id;	
			cd.duration			= a[i].duration;					
			cd.call_time		= a[i].call_time;		
			cd.call_type_id		= a[i].call_type_id;		
			cd.network_id		= a[i].network_id; 
			cd.rate_rule_id		= ""; //-- for telephony		
			cd.service_type_id	= a[i].service_type_id;	
			cd.locale_id		= a[i].locale_id;
			cd.ms_location		= a[i].ms_location;
			cd.charged_units	= a[i].charged_units;
									
			if(set_current(cd.account_no))
			{
				current->call.classify_calls(&cd);
				//-- if eligible to bulk discount then add to call list
				if(current->connection.bulk_discount==true)
				{
					current->blk_discount.insert_cdr(&cd);
				}
			}
		}
	} 

	/* EXEC SQL AT rating CLOSE c_cdr; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )344;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  cdrs read.\n\n",rows_before);
}


void connections::db_read_gprs()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct gprs_t
	{
		int		account_no;
		float	charge;
	} *b;
	char t_start_date[20], t_end_date[20];
	int rows_to_fetch, rows_before, rows_this_time; 

/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	strcpy(t_start_date,start_date.c_str());
	strcpy(t_end_date, end_date.c_str());

	rows_to_fetch = CDR_FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;					// previous value of sqlerrd[2]   
	rows_this_time = CDR_FETCH_SIZE; 

	if((b = new gprs_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memory for gprs fetch"<<endl;
		exit(0);
	}


	/* EXEC SQL 
	AT CUSTOMER_CARE 
	DECLARE c_gprs CURSOR FOR 
	SELECT	ACCOUNT_NO,
			CHARGE  
	FROM	bill_fast_gprs_cdrs_v
	WHERE	CALL_TIME >= :t_start_date  AND CALL_TIME <= :t_end_date ||'235959'; */ 
 

	/* EXEC SQL AT CUSTOMER_CARE OPEN c_gprs; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0009;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )365;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)t_start_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)t_end_date;
 sqlstm.sqhstl[1] = (unsigned int  )20;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT CUSTOMER_CARE FOR :rows_to_fetch FETCH c_gprs INTO :b; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )401;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&b->account_no;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct gprs_t);
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&b->charge;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct gprs_t);
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
				 
		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			if(set_current(b[i].account_no))
			{
				current->call.gprs += b[i].charge;
			}
		}
	}

	/* EXEC SQL AT CUSTOMER_CARE CLOSE c_gprs; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )437;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete b;

	printf("%d gprs records loaded.\n\n",rows_before);
}


//-- tap file records
void connections::db_read_tap()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct tap_t
	{
		int		account_no;
		float	charge;
	} *b;
	char t_start_date[20], t_end_date[20];
	int rows_to_fetch, rows_before, rows_this_time; 

/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	strcpy(t_start_date,start_date.c_str());
	strcpy(t_end_date, end_date.c_str());

	rows_to_fetch = CDR_FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				// previous value of sqlerrd[2]   
	rows_this_time = CDR_FETCH_SIZE; 

	if((b = new tap_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memory for tap fetch"<<endl;
		exit(0);
	}


	/* EXEC SQL 
	AT CUSTOMER_CARE 
	DECLARE c_tap CURSOR FOR 
	SELECT	ACCOUNT_NO,
			CHARGE  
	FROM	bill_fast_tap_cdrs_v
	WHERE	RATED_TIME >= :t_start_date  AND RATED_TIME <= :t_end_date ||'235959'; */ 
 

	/* EXEC SQL AT CUSTOMER_CARE OPEN c_tap; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0010;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )465;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)t_start_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)t_end_date;
 sqlstm.sqhstl[1] = (unsigned int  )20;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT CUSTOMER_CARE FOR :rows_to_fetch FETCH c_tap INTO :b; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )501;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&b->account_no;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct tap_t);
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&b->charge;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct tap_t);
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
				 
		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		printf(" tap=%d \n", rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			if(set_current(b[i].account_no))
			{
				current->call.air += b[i].charge;
			}
		}
	}

	/* EXEC SQL AT CUSTOMER_CARE CLOSE c_tap; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )537;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete b;

	printf("%d tap records loaded.\n\n",rows_before);
}


//-- evolution charges
void connections::db_read_anyware()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct anyware
	{
		int		account_no;					//-- NUMBER(10)    NOT NULL, 
		float	charge;						//-- NUMBER(7,2)   NOT NULL, 
	} *b;

	char t_start_date[20], t_end_date[20];
	int rows_to_fetch, rows_before, rows_this_time; 

/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	strcpy(t_start_date,start_date.c_str());
	strcpy(t_end_date, end_date.c_str());
	cdr_data cd;

	rows_to_fetch = CDR_FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				// previous value of sqlerrd[2]   
	rows_this_time = CDR_FETCH_SIZE; 

	if((b = new anyware[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memory for anyware fetch"<<endl;
		exit(0);
	}


	/* EXEC SQL 
	AT CUSTOMER_CARE 
	DECLARE c_anyware CURSOR FOR 
	SELECT	ACCOUNT_NO,
			CHARGE 
	FROM	bill_fast_anyware_charges_v
	WHERE	CALL_TIME >= :t_start_date  AND CALL_TIME <= :t_end_date ||'235959'; */ 
 

	/* EXEC SQL AT CUSTOMER_CARE OPEN c_anyware; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0011;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )565;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)t_start_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)t_end_date;
 sqlstm.sqhstl[1] = (unsigned int  )20;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT CUSTOMER_CARE FOR :rows_to_fetch FETCH c_anyware INTO :b; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )601;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&b->account_no;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct anyware);
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&b->charge;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct anyware);
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
				 
		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		printf(" anyware=%d \n", rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			if(set_current(b[i].account_no))
				current->call.anyware += b[i].charge;
		}
	}

	/* EXEC SQL AT CUSTOMER_CARE CLOSE c_anyware; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )637;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete b;

	printf("%d anyware records loaded.\n\n",rows_before);
}


//-- connections
void connections::db_read_connections()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct connection
	{ 
		int		account_no;
		char	package_code[BUF_LEN];
		float	contract_charge;	
		char	contract_end_date[BUF_LEN];
		char	tax_group[BUF_LEN]; 
		char    corporate_bill_code[BUF_LEN];
		char	value_plus_plus[20];
		char	connection_status[10];
	} *a; 
	int i;

	int rows_to_fetch, rows_before, rows_this_time;
	char t_start_date[20],t_end_date[20];
	/* EXEC SQL END DECLARE SECTION; */ 


	strcpy(t_start_date,start_date.c_str());
	strcpy(t_end_date, end_date.c_str());

	rows_to_fetch = CLIENT_FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = CLIENT_FETCH_SIZE; 

	if((a = new connection[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for connections fetch"<<endl;
		exit(0);
	}

	/* EXEC SQL 
	AT CUSTOMER_CARE  
	DECLARE c_connection CURSOR FOR 
	SELECT	ACCOUNT_NO, 
			PACKAGE_CODE,
			CONTRACT_CHARGE, 
			CONTRACT_END_DATE, 
			TAX_GROUP,
			CORPORATE_BILL_CODE, 
			VALUE_PLUS_PLUS,
			CONNECTION_STATUS
//	FROM	BILL_FAST_CONNECTIONS_V 
//	WHERE	COMMENCEMENT_DATE <= :t_end_date AND
//			NOT 
//			  (
//				CONNECTION_STATUS = 'D' AND 
//				TRUNC(CURRENT_STATUS_DATE) < :t_start_date
//			  );
	FROM	BILL_INTERIM_CONNECTIONS_V 
	WHERE	NOT 
			(CONNECTION_STATUS = 'D' AND 
			NVL(DISCONNECTED_DATE, TO_DATE('20100101','YYYYMMDD')) < TO_DATE(:t_start_date, 'YYYYMMDD')); */ 



//-- don't load any disconnected connections older than current bill cycles
	   
	/* EXEC SQL AT CUSTOMER_CARE OPEN c_connection; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0012;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )665;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)t_start_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	connection_detail c_d;

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT CUSTOMER_CARE FOR :rows_to_fetch FETCH c_connection INTO :a; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )697;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&a->account_no;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct connection);
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->package_code;
  sqlstm.sqhstl[1] = (unsigned int  )50;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct connection);
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&a->contract_charge;
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[2] = (         int  )sizeof(struct connection);
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)a->contract_end_date;
  sqlstm.sqhstl[3] = (unsigned int  )50;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct connection);
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)a->tax_group;
  sqlstm.sqhstl[4] = (unsigned int  )50;
  sqlstm.sqhsts[4] = (         int  )sizeof(struct connection);
  sqlstm.sqindv[4] = (         void  *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)a->corporate_bill_code;
  sqlstm.sqhstl[5] = (unsigned int  )50;
  sqlstm.sqhsts[5] = (         int  )sizeof(struct connection);
  sqlstm.sqindv[5] = (         void  *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)a->value_plus_plus;
  sqlstm.sqhstl[6] = (unsigned int  )20;
  sqlstm.sqhsts[6] = (         int  )sizeof(struct connection);
  sqlstm.sqindv[6] = (         void  *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)a->connection_status;
  sqlstm.sqhstl[7] = (unsigned int  )10;
  sqlstm.sqhsts[7] = (         int  )sizeof(struct connection);
  sqlstm.sqindv[7] = (         void  *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		printf(" connections=%d \n", rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			c_d.account_no			=   a[i].account_no;
			c_d.package_code		=	a[i].package_code; 
			c_d.contract_charge 	=	a[i].contract_charge*100;
			c_d.contract_end_date	=	a[i].contract_end_date;
			c_d.tax_group			=	a[i].tax_group;
			c_d.corporate_bill_code =	a[i].corporate_bill_code;
			c_d.value_plus_plus		=	a[i].value_plus_plus;
			c_d.connection_status   =	a[i].connection_status;
			insert(a[i].account_no, c_d); 
		}
	} 

	/* EXEC SQL AT CUSTOMER_CARE CLOSE c_connection; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )757;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 	delete a;

	printf("\n %d loaded connections \n\n",rows_before);
}


void connections::db_read_package_rental()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		struct package_rental
		{ 
			int		account_no;
			float	rental;	
		} *a; 
		int i;
		int rows_to_fetch, rows_before, rows_this_time;
	/* EXEC SQL END DECLARE SECTION; */ 


	rows_to_fetch = CLIENT_FETCH_SIZE;
	rows_before = 0;				
	rows_this_time = CLIENT_FETCH_SIZE; 

	if((a = new package_rental[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memory for package rental fetch"<<endl;
		exit(0);
	}

	/* EXEC SQL 
	AT CUSTOMER_CARE  
	DECLARE c_package_rental CURSOR FOR 
	SELECT	ACCOUNT_NO, 
			RENTAL
	FROM	bill_fast_package_rental_v; */ 

	   
	/* EXEC SQL AT CUSTOMER_CARE OPEN c_package_rental; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0013;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )785;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT CUSTOMER_CARE FOR :rows_to_fetch FETCH c_package_rental INTO :a; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )813;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&a->account_no;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct package_rental);
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->rental;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct package_rental);
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			if(set_current(a[i].account_no))
			{
				current->charge.total_monthly_rental += a[i].rental;
				current->charge.package_rental += a[i].rental;
			}
		}
	} 

	/* EXEC SQL AT CUSTOMER_CARE CLOSE c_package_rental; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )849;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 	delete a;

	printf("\n %d loaded package rentals \n\n",rows_before);
}


//-- vas, clip, sms
void connections::db_read_value_add_rental()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		struct value_add_rental
		{ 
			int		account_no;
			float	rental;	
			char	rent_code[50];
		} *a; 
		int i;
		int rows_to_fetch, rows_before, rows_this_time;
		char t_start_date[20], t_end_date[20];
	/* EXEC SQL END DECLARE SECTION; */ 


	strcpy(t_start_date,start_date.c_str());
	strcpy(t_end_date, end_date.c_str());

	rows_to_fetch = CLIENT_FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;						// previous value of sqlerrd[2]   
	rows_this_time = CLIENT_FETCH_SIZE; 

	if((a = new value_add_rental[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memory for value add rental fetch"<<endl;
		exit(0);
	}

	/* EXEC SQL 
	AT CUSTOMER_CARE  
	DECLARE c_value_add_rental CURSOR FOR 
	SELECT	ACCOUNT_NO, 
			RENTAL,
			SERVICE_CODE||'_RENT'
	FROM	bill_fast_value_add_rental_v 
	WHERE	(  
				RENTAL_ACTIVATION_DATE < to_date(:t_end_date, 'YYYYMMDD') 
				OR 
				TRUNC(RENTAL_ACTIVATION_DATE) BETWEEN 
				to_date(:t_start_date,'YYYYMMDD') AND to_date(:t_end_date, 'YYYYMMDD') 
			); */ 

	   
	/* EXEC SQL AT CUSTOMER_CARE OPEN c_value_add_rental; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0014;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )877;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)t_end_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)t_start_date;
 sqlstm.sqhstl[1] = (unsigned int  )20;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)t_end_date;
 sqlstm.sqhstl[2] = (unsigned int  )20;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT CUSTOMER_CARE FOR :rows_to_fetch FETCH c_value_add_rental INTO :a; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )917;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&a->account_no;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct value_add_rental);
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->rental;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct value_add_rental);
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->rent_code;
  sqlstm.sqhstl[2] = (unsigned int  )50;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct value_add_rental);
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		printf(" vas=%d \n", rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			if(set_current(a[i].account_no))
			{
				current->charge.total_monthly_rental += a[i].rental;
				current->charge.rent_breakup[a[i].rent_code]=a[i].rental;
			}
		}
	} 

	/* EXEC SQL AT CUSTOMER_CARE CLOSE c_value_add_rental; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )957;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 	delete a;

	printf("\n %d loaded value add rentals \n\n",rows_before);
}

// -- payments
void connections::db_read_payments()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		struct payments
		{ 
			int		account_no;
			float	payment;
			float	balance_bf;	
		} *a; 
		int i;
		int rows_to_fetch, rows_before, rows_this_time;
	/* EXEC SQL END DECLARE SECTION; */ 


	rows_to_fetch = CLIENT_FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;						// previous value of sqlerrd[2]   
	rows_this_time = CLIENT_FETCH_SIZE; 

	if((a = new payments[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memory for payment fetch"<<endl;
		exit(0);
	}

	/* EXEC SQL 
	AT CUSTOMER_CARE  
	DECLARE c_payments CURSOR FOR 
	SELECT	ACCOUNT_NO, 
			PAYMENT,
			BALANCE_BF
//	FROM	bill_fast_payments_v;
	FROM	bill_interim_payments_v; */ 

	   
	/* EXEC SQL AT CUSTOMER_CARE OPEN c_payments; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0015;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )985;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT CUSTOMER_CARE FOR :rows_to_fetch FETCH c_payments INTO :a; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )1013;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&a->account_no;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct payments);
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->payment;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct payments);
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&a->balance_bf;
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[2] = (         int  )sizeof(struct payments);
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);
		printf(" payments=%d \n", rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			if(set_current(a[i].account_no))
			{
				current->charge.payments += a[i].payment;
				current->charge.brought_forward += a[i].balance_bf;
			}
		}
	} 

	/* EXEC SQL AT CUSTOMER_CARE CLOSE c_payments; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1053;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 	delete a;

	printf("\n %d loaded payments \n\n",rows_before);
}

void connections::db_read_interest()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		struct s_interest
		{ 
			int		account_no;
			float	interest;
		} *a; 
		int i;
		char t_start_date[20], t_end_date[20];
		int rows_to_fetch, rows_before, rows_this_time;
	/* EXEC SQL END DECLARE SECTION; */ 


	strcpy(t_start_date,start_date.c_str());
	strcpy(t_end_date, end_date.c_str());


	rows_to_fetch = CLIENT_FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;						// previous value of sqlerrd[2]   
	rows_this_time = CLIENT_FETCH_SIZE; 

	if((a = new s_interest[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memory for interest fetch"<<endl;
		exit(0);
	}

	/* EXEC SQL 
	AT CUSTOMER_CARE  
	DECLARE c_interest CURSOR FOR 
	SELECT	ACCOUNT_NO, 
			INTEREST
	FROM	bill_fast_interest_v 
	WHERE	INTEREST_DATE between 
			to_date(:t_start_date,'YYYYMMDD') AND to_date(:t_end_date, 'YYYYMMDD'); */ 

	   
	/* EXEC SQL AT CUSTOMER_CARE OPEN c_interest; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0016;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1081;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)t_start_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)t_end_date;
 sqlstm.sqhstl[1] = (unsigned int  )20;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT CUSTOMER_CARE FOR :rows_to_fetch FETCH c_interest INTO :a; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )1117;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&a->account_no;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct s_interest);
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->interest;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct s_interest);
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			if(set_current(a[i].account_no))
			{
				current->charge.interest += a[i].interest;
			}
		}
	} 

	/* EXEC SQL AT CUSTOMER_CARE CLOSE c_interest; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1153;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 	delete a;

	printf("\n %d loaded interest \n\n",rows_before);
}


void connections::db_read_bulk_discount_get_balance()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		struct s_b_discount
		{ 
			int		account_no;
			char	time_band[10+1];
			char	call_type_id[10+1];
			float	balance;
		} *a; 
		int i;
		int rows_to_fetch, rows_before, rows_this_time;
	/* EXEC SQL END DECLARE SECTION; */ 



	rows_to_fetch = CLIENT_FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;						// previous value of sqlerrd[2]   
	rows_this_time = CLIENT_FETCH_SIZE; 

	if((a = new s_b_discount[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memory for bulk discount balance fetch"<<endl;
		exit(0);
	}

	/* EXEC SQL 
	AT CUSTOMER_CARE  
	DECLARE c_bulk_discount CURSOR FOR 
	SELECT	ACCOUNT_NO, 
			TIME_BAND,
			CALL_TYPE_ID,
			BALANCE
	FROM	bd_minute_balance; */ 
 
	   
	/* EXEC SQL AT CUSTOMER_CARE OPEN c_bulk_discount; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0017;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1181;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT CUSTOMER_CARE FOR :rows_to_fetch FETCH c_bulk_discount INTO :a; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )1209;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&a->account_no;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct s_b_discount);
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->time_band;
  sqlstm.sqhstl[1] = (unsigned int  )11;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct s_b_discount);
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->call_type_id;
  sqlstm.sqhstl[2] = (unsigned int  )11;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct s_b_discount);
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)&a->balance;
  sqlstm.sqhstl[3] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[3] = (         int  )sizeof(struct s_b_discount);
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			if(set_current(a[i].account_no))
			{
				current->blk_discount.insert_balance(a[i].time_band, 
				a[i].call_type_id, a[i].balance);
			}
//			cout<<" Bulk min "<<a[i].account_no<<endl;
		}
	} 

	/* EXEC SQL AT CUSTOMER_CARE CLOSE c_bulk_discount; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1253;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 	delete a;

	printf("\n %d loaded bulk min balance \n\n",rows_before);
}



void connections::db_insert_bulk_discount_usage()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	char t_call_type[50], t_time_band[50], t_client_code[50], t_date[50];
	int t_ac_no;
	float t_used;
	/* EXEC SQL END DECLARE SECTION; */ 



	/* EXEC SQL WHENEVER NOT FOUND GOTO notfound; */ 


	bulk_min_balance b;
	connection_state *c;
	strcpy(t_date, end_date.c_str());

	CONNECTION_DEF::iterator i;
	for(i=conn.begin(); i!=conn.end(); i++)
	{
		c= &(*i).second;
		if( c->connection.bulk_discount==false)
			continue;

		BULK_CREDITS_DEF::iterator j;
		for(j=c->blk_discount.min_balance.begin(); j!=c->blk_discount.min_balance.end(); j++)
		{

			b=(*j);

			if (b.used == 0)
				continue;
	
			if (b.time_band==PEAK) strcpy(t_time_band, "PK");
			else if (b.time_band==OFF_PEAK) strcpy(t_time_band,"OPK");
			else strcpy(t_time_band,"ANY");

			if (b.call_type_id==TERMINATING_CALL_RADIO) strcpy(t_call_type, "IN");
			else if (b.call_type_id==ORIGINATING_CALL_RADIO) strcpy(t_call_type,"OUT");
			else strcpy(t_call_type,"ANY");

			t_used = -b.used;
			t_ac_no = (*i).first;

			sprintf(t_client_code,"%d",t_ac_no);

			/* EXEC SQL AT CUSTOMER_CARE EXECUTE
			begin
				insert into bd_trx_raw(time_band, call_type, minutes, account_no, client_code, trx_type, trx_date) 
				values (:t_time_band,:t_call_type,:t_used, :t_ac_no, :t_client_code, 'USED',to_date(:t_date,'YYYYMMDD')); 		
			end;
			END-EXEC; */ 

{
   struct sqlexd sqlstm;
   sqlorat((void **)0, &sqlctx, &oraca);
   sqlstm.sqlvsn = 10;
   sqlstm.arrsiz = 13;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "begin insert into bd_trx_raw ( time_band , call_type , min\
utes , account_no , client_code , trx_type , trx_date ) values ( :t_time_band \
, :t_call_type , :t_used , :t_ac_no , :t_client_code , 'USED' , to_date ( :t_d\
ate , 'YYYYMMDD' ) ) ; end ;";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1281;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)256;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (         void  *)t_time_band;
   sqlstm.sqhstl[0] = (unsigned int  )50;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         void  *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned int  )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (         void  *)t_call_type;
   sqlstm.sqhstl[1] = (unsigned int  )50;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         void  *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned int  )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (         void  *)&t_used;
   sqlstm.sqhstl[2] = (unsigned int  )sizeof(float);
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         void  *)0;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned int  )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (         void  *)&t_ac_no;
   sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         void  *)0;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned int  )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (         void  *)t_client_code;
   sqlstm.sqhstl[4] = (unsigned int  )50;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         void  *)0;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned int  )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (         void  *)t_date;
   sqlstm.sqhstl[5] = (unsigned int  )50;
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         void  *)0;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned int  )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode == 1403) goto notfound;
   if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


//			cout<<" USED BALANCE "<<t_ac_no<<","<<t_used<<","<<t_time_band<<","<<t_call_type<<endl;
		 }
	}
	return;
notfound:
	printf("<ERROR> cant insert bulk minute balnce \n");
	return;
}

void connections::db_read_adjustments()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		struct s_adjust
		{ 
			int		account_no;
			float	adjustment;
		} *a; 
		int i;
		int rows_to_fetch, rows_before, rows_this_time;
		char t_start_date[20], t_end_date[20];
	/* EXEC SQL END DECLARE SECTION; */ 


	strcpy(t_start_date,start_date.c_str());
	strcpy(t_end_date, end_date.c_str());

	rows_to_fetch = CLIENT_FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;						// previous value of sqlerrd[2]   
	rows_this_time = CLIENT_FETCH_SIZE; 

	if((a = new s_adjust[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memory for adjustment fetch"<<endl;
		exit(0);
	}


	/* EXEC SQL 
	AT CUSTOMER_CARE  
	DECLARE c_adjust CURSOR FOR 
	SELECT	ACCOUNT_NO, 
			ADJUSTMENT
	FROM	bill_fast_account_adj_v 
	WHERE	TRUNC(APPROVED_DATE)  BETWEEN 
			to_date(:t_start_date,'YYYYMMDD') AND to_date(:t_end_date,'YYYYMMDD'); */ 

	   
	/* EXEC SQL AT CUSTOMER_CARE OPEN c_adjust; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0019;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1333;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)t_start_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)t_end_date;
 sqlstm.sqhstl[1] = (unsigned int  )20;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT CUSTOMER_CARE FOR :rows_to_fetch FETCH c_adjust INTO :a; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )1369;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&a->account_no;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct s_adjust);
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->adjustment;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct s_adjust);
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			if(set_current(a[i].account_no))
			{
				current->charge.misc_charges += a[i].adjustment;
			}
		}
	} 

	/* EXEC SQL AT CUSTOMER_CARE CLOSE c_adjust; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1405;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 	delete a;

	printf("\n %d loaded adjustments \n\n",rows_before);
}


void connections::db_read_pro_rates()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		struct s_pro_rate
		{ 
			int		account_no;
			float	pro_rate;
		} *a; 
		int i;
		int rows_to_fetch, rows_before, rows_this_time;
		char t_start_date[20], t_end_date[20];
	/* EXEC SQL END DECLARE SECTION; */ 


	strcpy(t_start_date,start_date.c_str());
	strcpy(t_end_date, end_date.c_str());

	rows_to_fetch = CLIENT_FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;						// previous value of sqlerrd[2]   
	rows_this_time = CLIENT_FETCH_SIZE; 

	if((a = new s_pro_rate[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memory for pro_rate fetch"<<endl;
		exit(0);
	}


	/* EXEC SQL 
	AT CUSTOMER_CARE  
	DECLARE c_pro_rate CURSOR FOR 
	SELECT	ACCOUNT_NO, 
			pro_rate
	FROM	bill_fast_pro_rate_v 
	WHERE	TRUNC(APPROVED_DATE)  BETWEEN 
			to_date(:t_start_date,'YYYYMMDD') AND to_date(:t_end_date,'YYYYMMDD'); */ 

	   
	/* EXEC SQL AT CUSTOMER_CARE OPEN c_pro_rate; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0020;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1433;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)t_start_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)t_end_date;
 sqlstm.sqhstl[1] = (unsigned int  )20;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT CUSTOMER_CARE FOR :rows_to_fetch FETCH c_pro_rate INTO :a; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )1469;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&a->account_no;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct s_pro_rate);
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->pro_rate;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct s_pro_rate);
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			if(set_current(a[i].account_no))
			{
				current->charge.rental_pro_rate += a[i].pro_rate;
			}
		}
	} 

	/* EXEC SQL AT CUSTOMER_CARE CLOSE c_pro_rate; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1505;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 	delete a;

	printf("\n %d loaded pro_rates \n\n",rows_before);
}



//-- when a contract is first made then pro rate it during the first month
//-- update the contrat charge with the prorated amount to achive result
void connections::db_read_contract_charge_pro_rate()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		struct s_pro_rate
		{ 
			int		account_no;
			float	pro_rate;
		} *a; 
		int i;
		int rows_to_fetch, rows_before, rows_this_time;
		char t_start_date[20], t_end_date[20];
	/* EXEC SQL END DECLARE SECTION; */ 


	strcpy(t_start_date,start_date.c_str());
	strcpy(t_end_date, end_date.c_str());

	rows_to_fetch = CLIENT_FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;						// previous value of sqlerrd[2]   
	rows_this_time = CLIENT_FETCH_SIZE; 

	if((a = new s_pro_rate[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memory for contract charge pro_rate fetch"<<endl;
		exit(0);
	}


	/* EXEC SQL 
	AT CUSTOMER_CARE  
	DECLARE c_cont_pro_rate CURSOR FOR 
	SELECT	ACCOUNT_NO, 
			pro_rate*100
	FROM	bill_fast_contract_pro_rate_v
	WHERE	START_DATE  BETWEEN 
			:t_start_date AND :t_end_date; */ 

	   
	/* EXEC SQL AT CUSTOMER_CARE OPEN c_cont_pro_rate; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0021;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1533;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)t_start_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)t_end_date;
 sqlstm.sqhstl[1] = (unsigned int  )20;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT CUSTOMER_CARE FOR :rows_to_fetch FETCH c_cont_pro_rate INTO :a; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )1569;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&a->account_no;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct s_pro_rate);
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->pro_rate;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct s_pro_rate);
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			if(set_current(a[i].account_no))
			{
				current->connection.contract_charge = a[i].pro_rate;
			}
		}
	} 

	/* EXEC SQL AT CUSTOMER_CARE CLOSE c_cont_pro_rate; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1605;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 	delete a;

	printf("\n %d loaded contract charge pro rates \n\n",rows_before);
}


// -- value_plus plus
void connections::db_read_value_pp()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		struct s_vpp
		{ 
			int		account_no;
		} *a; 
		int i;
		int rows_to_fetch, rows_before, rows_this_time;
		char t_start_date[20], t_end_date[20];
	/* EXEC SQL END DECLARE SECTION; */ 


	strcpy(t_start_date,start_date.c_str());
	strcpy(t_end_date, end_date.c_str());

	rows_to_fetch = CLIENT_FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;						// previous value of sqlerrd[2]   
	rows_this_time = CLIENT_FETCH_SIZE; 

	if((a = new s_vpp[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memory for value plus plus fetch"<<endl;
		exit(0);
	}


	/* EXEC SQL 
	AT CUSTOMER_CARE  
	DECLARE c_vpp_paid CURSOR FOR 
	SELECT	ACCOUNT_NO
	FROM	bill_fast_value_plus_paid_v 
	WHERE	TRUNC(bill_date)  BETWEEN 
			to_date(:t_start_date,'YYYYMMDD') AND to_date(:t_end_date,'YYYYMMDD'); */ 

 
	/* EXEC SQL AT CUSTOMER_CARE OPEN c_vpp_paid; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0022;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1633;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)t_start_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)t_end_date;
 sqlstm.sqhstl[1] = (unsigned int  )20;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT CUSTOMER_CARE FOR :rows_to_fetch FETCH c_vpp_paid INTO :a; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )1669;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&a->account_no;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct s_vpp);
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			if(set_current(a[i].account_no))
			{
				current->charge.vpp_payment = true;
			}
		}
	} 

	/* EXEC SQL AT CUSTOMER_CARE CLOSE c_vpp_paid; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1701;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 	delete a;

	printf("\n %d loaded value plus plus \n\n",rows_before);
}


void holiday_day_types::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct holiday_day_type
	{ 
		char	holiday_date[BUF_LEN]; 
		char	day_id[BUF_LEN];
	} a, *hdtp; 
	int i;
	/* EXEC SQL END DECLARE SECTION; */ 


	hdtp=&a;

	/* EXEC SQL AT CUSTOMER_CARE DECLARE c_holiday_day_type CURSOR FOR 
	SELECT HOLIDAY_DATE, DAY_ID
	FROM R_HOLIDAYS_V; */ 
 

	/* EXEC SQL AT CUSTOMER_CARE OPEN c_holiday_day_type; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0023;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1729;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 

	/* EXEC SQL WHENEVER NOT FOUND DO break; */ 
 


	for (i=0; ;i++) 
	{ 
		/* EXEC SQL AT CUSTOMER_CARE FETCH c_holiday_day_type INTO :hdtp; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1757;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)hdtp->holiday_date;
  sqlstm.sqhstl[0] = (unsigned int  )50;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)hdtp->day_id;
  sqlstm.sqhstl[1] = (unsigned int  )50;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
		insert(atoi(hdtp->holiday_date), hdtp->day_id);
	} 

	/* EXEC SQL AT CUSTOMER_CARE CLOSE c_holiday_day_type; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1793;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 
	printf("\n %d holiday day types loaded\n\n",i);
}



void temporary_termination::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		struct s_tt
		{ 
			int		account_no;
			char	disconnect_date[9];
		} *a; 
		int i;
		int rows_to_fetch, rows_before, rows_this_time;
	/* EXEC SQL END DECLARE SECTION; */ 


	rows_to_fetch = CLIENT_FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;						// previous value of sqlerrd[2]   
	rows_this_time = CLIENT_FETCH_SIZE; 

	if((a = new s_tt[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memory for disconection history fetch"<<endl;
		exit(0);
	}


	/* EXEC SQL 
	AT CUSTOMER_CARE  
	DECLARE c_disconnect CURSOR FOR 
	SELECT	CONN_ACCOUNT_NO,
			to_char(DISCONNECTION_DATE, 'YYYYMMDD')
	FROM	DISCONNECTION_HISTORY
			WHERE DISCONNECTION_TYPE = 'T'; */ 

	   
	/* EXEC SQL AT CUSTOMER_CARE OPEN c_disconnect; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0024;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1821;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT CUSTOMER_CARE FOR :rows_to_fetch FETCH c_disconnect INTO :a; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )1849;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&a->account_no;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct s_tt);
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->disconnect_date;
  sqlstm.sqhstl[1] = (unsigned int  )9;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct s_tt);
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
//		printf(" disconnect = %d \n", rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			insert(a[i].account_no, a[i].disconnect_date);
		}
	} 

	/* EXEC SQL AT CUSTOMER_CARE CLOSE c_disconnect; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1885;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;

	printf("\n %d loaded disconnection histories \n\n",rows_before);
}


void package_discount::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		struct s_tt
		{ 
			char package_code[5+1];
			char bill_item[10+1];
			double limit;
			double discount_percent;
		} *a; 
		int i;
		char t_bill_date[20];
		int rows_to_fetch, rows_before, rows_this_time;
	/* EXEC SQL END DECLARE SECTION; */ 


	strcpy(t_bill_date,bill_date.c_str());

	rows_to_fetch = CLIENT_FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;						// previous value of sqlerrd[2]   
	rows_this_time = CLIENT_FETCH_SIZE; 

	if((a = new s_tt[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memory for package discount fetch"<<endl;
		exit(0);
	}


	/* EXEC SQL 
	AT CUSTOMER_CARE  
	DECLARE c_pkg_discount CURSOR FOR 
	SELECT	package_code,
			bill_item,
			limit,
			discount_percent
	FROM	bill_fast_discount_packages_v
			WHERE start_date <= :t_bill_date and end_date >= :t_bill_date; */ 

 
 	/* EXEC SQL AT CUSTOMER_CARE OPEN c_pkg_discount; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0025;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1913;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)t_bill_date;
  sqlstm.sqhstl[0] = (unsigned int  )20;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)t_bill_date;
  sqlstm.sqhstl[1] = (unsigned int  )20;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	pkg_discount_key k;
	pkg_discount_data d;

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT CUSTOMER_CARE FOR :rows_to_fetch FETCH c_pkg_discount INTO :a; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )1949;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)a->package_code;
  sqlstm.sqhstl[0] = (unsigned int  )6;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct s_tt);
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->bill_item;
  sqlstm.sqhstl[1] = (unsigned int  )11;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct s_tt);
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&a->limit;
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )sizeof(struct s_tt);
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)&a->discount_percent;
  sqlstm.sqhstl[3] = (unsigned int  )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )sizeof(struct s_tt);
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 

		for(i=0; i<rows_this_time; i++)
		{
			k.bill_item = a[i].bill_item;
			k.limit = a[i].limit;
			k.package_code = a[i].package_code;
			d.discount_percent = a[i].discount_percent;
			insert(k, d);
		}
	} 

	/* EXEC SQL AT CUSTOMER_CARE CLOSE c_pkg_discount; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1993;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;

	// make the index for fast discount look up
	make_short_index();

	printf("\n %d loaded package discounts \n\n",rows_before);
}



void other_charges::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		struct s_o_c
		{ 
			int account_no;
			char item_code[10+1];
			double amount;
			double operator_fee;
			char  taxable_op_fee[1+1];
		} *a; 
		int i;
		char t_start_date[20], t_end_date[20];
		int rows_to_fetch, rows_before, rows_this_time;
	/* EXEC SQL END DECLARE SECTION; */ 


	strcpy(t_start_date, start_date.c_str());
	strcpy(t_end_date, end_date.c_str());

	rows_to_fetch = CLIENT_FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;						// previous value of sqlerrd[2]   
	rows_this_time = CLIENT_FETCH_SIZE; 

	if((a = new s_o_c[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memory for other charges fetch"<<endl;
		exit(0);
	}

	/* EXEC SQL 
	AT CUSTOMER_CARE  
	DECLARE c_oth_charges CURSOR FOR 
	SELECT	account_no,
			item_code,
			amount,
			operator_fee,
			taxable_op_fee	
	FROM	bill_fast_other_charge_v
			WHERE payment_date between :t_start_date AND :t_end_date; */ 

	   
	/* EXEC SQL AT CUSTOMER_CARE OPEN c_oth_charges; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0026;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2021;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)t_start_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)t_end_date;
 sqlstm.sqhstl[1] = (unsigned int  )20;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	oth_chg_data d;

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT CUSTOMER_CARE FOR :rows_to_fetch FETCH c_oth_charges INTO :a; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )2057;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&a->account_no;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct s_o_c);
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->item_code;
  sqlstm.sqhstl[1] = (unsigned int  )11;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct s_o_c);
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&a->amount;
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )sizeof(struct s_o_c);
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)&a->operator_fee;
  sqlstm.sqhstl[3] = (unsigned int  )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )sizeof(struct s_o_c);
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)a->taxable_op_fee;
  sqlstm.sqhstl[4] = (unsigned int  )2;
  sqlstm.sqhsts[4] = (         int  )sizeof(struct s_o_c);
  sqlstm.sqindv[4] = (         void  *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 

		for(i=0; i<rows_this_time; i++)
		{
			d.bill_item = a[i].item_code;
			d.amount = a[i].amount;
			d.operator_fee = a[i].operator_fee;
			d.taxable = (strcmp(a[i].taxable_op_fee,"Y")==0) ? true:false;
			insert(a[i].account_no, d);
		}
	} 

	/* EXEC SQL AT CUSTOMER_CARE CLOSE c_oth_charges; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2105;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;

	printf("\n %d other charges loaded \n\n",rows_before);
}

   
void holiday_groups::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct time_band 
	{ 
		char	group_id[BUF_LEN]; 
		char	day_id[BUF_LEN];
	} a, *hpp; 
	int i;
	/* EXEC SQL END DECLARE SECTION; */ 


	hpp = &a;

    /* EXEC SQL AT CUSTOMER_CARE DECLARE c_holiday_group CURSOR FOR 
        SELECT GROUP_ID, DAY_ID
            FROM r_d_holiday_group_days; */ 
 
       
    /* EXEC SQL AT CUSTOMER_CARE OPEN c_holiday_group; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0027;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2133;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 
    /* EXEC SQL WHENEVER NOT FOUND DO break; */ 
 


    for (i=0; ;i++) 
    { 
        /* EXEC SQL AT CUSTOMER_CARE FETCH c_holiday_group INTO :hpp; */ 

{
        struct sqlexd sqlstm;
        sqlorat((void **)0, &sqlctx, &oraca);
        sqlstm.sqlvsn = 10;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2161;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (         void  *)hpp->group_id;
        sqlstm.sqhstl[0] = (unsigned int  )50;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (         void  *)hpp->day_id;
        sqlstm.sqhstl[1] = (unsigned int  )50;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         void  *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned int  )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode == 1403) break;
        if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 

		holiday_group_data k;

		k.day_id = hpp->day_id;
		k.group  = hpp->group_id;
		insert(k);
    } 

    /* EXEC SQL AT CUSTOMER_CARE CLOSE c_holiday_group; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2197;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 
    printf("\n %d holiday groups loaded.\n\n",i);
}



void taxes::db_read()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct tax_s 
	{ 
		 char tax_type[BUF_LEN];	//	VARCHAR2(5)
		 float rate;				//	NUMBER(5,2)
		 float slab;				//	NUMBER(14,2)
		 char tax_group[BUF_LEN];	//  VARCHAR2(5)
		 int priority;				//  NUMBER(2)
	} a, *tp; 
	/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	tp = &a;
 
    /* EXEC SQL AT CUSTOMER_CARE DECLARE c_tax CURSOR FOR 
	SELECT	NVL(TAX_TYPE,'*'), NVL(RATE,0), 
			NVL(SLAB,0),  TAX_GROUP,  PRIORITY
	FROM	R_TAX_DEFS_V; */ 

       
    /* EXEC SQL AT CUSTOMER_CARE OPEN c_tax; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0028;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2225;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 
    /* EXEC SQL WHENEVER NOT FOUND DO break; */ 
 

    for (i=0; ;i++) 
    { 
        /* EXEC SQL AT CUSTOMER_CARE FETCH c_tax INTO :tp; */ 

{
        struct sqlexd sqlstm;
        sqlorat((void **)0, &sqlctx, &oraca);
        sqlstm.sqlvsn = 10;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2253;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (         void  *)tp->tax_type;
        sqlstm.sqhstl[0] = (unsigned int  )50;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (         void  *)&tp->rate;
        sqlstm.sqhstl[1] = (unsigned int  )sizeof(float);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         void  *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned int  )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (         void  *)&tp->slab;
        sqlstm.sqhstl[2] = (unsigned int  )sizeof(float);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         void  *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned int  )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (         void  *)tp->tax_group;
        sqlstm.sqhstl[3] = (unsigned int  )50;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         void  *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned int  )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (         void  *)&tp->priority;
        sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         void  *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned int  )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode == 1403) break;
        if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 

		tax_key tk;
		tk.type = tp->tax_type;
		tk.slab = tp->slab;
		tk.group = tp->tax_group;
		tk.priority = tp->priority;

		insert(tk, tp->rate);
    } 

    /* EXEC SQL AT CUSTOMER_CARE CLOSE c_tax; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2301;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 
    printf("\n %d  tax definitions loaded.\n\n",i);
}


void connections::db_insert_bill_block(int bills_pending_insert, bill_block *b)
{

/* EXEC SQL BEGIN DECLARE SECTION; */ 

struct bill
{
	char  b_client_code[50];	// varchar2(8)		not null,
 	int   b_account_no;			// number(10)		not null,
	char  b_bill_no[50];		// varchar2(10)		not null,
	char  b_due_date[50];		// date 			not null,
	char  b_bill_date[50];		// date				null,    	-- if null the bill is open.
	char  b_start_date[50];		// date 			not null,
	char  b_end_date[50];		// date				not null,
	float b_balance_bf;			// number(14,2)		not null,
	float b_total_bill_value;	// number(14,2)		not null,
	float b_balance_cf;			// number(14,2)		not null -- for next bill (bf-payments+bill_amount)
	char  b_br_code[50];		// varchar2(2)		not null,
	float b_bill_payments;		// number(14,2)		not null,
	int	  b_run_no;				// number(5)
	char  b_printed[2];			// varchar2(1)
	char  b_corporate_bill_code[50];
	int	  b_random_no;
} *a;
int rows_to_insert;
/* EXEC SQL END DECLARE SECTION; */ 


	rows_to_insert = bills_pending_insert;

	if((a = new bill[BILL_BLOCK_SIZE])==NULL)
	{
		cout<<" cant allocate memory for bill insert"<<endl;
		exit(0);
	}


	for(int i=0; i<bills_pending_insert; i++)
	{
		strcpy(a[i].b_client_code, b[i].client_code);
		a[i].b_account_no = b[i].account_no;
	
		strcpy(a[i].b_bill_no, b[i].bill_no);
		strcpy(a[i].b_br_code,gsm_bill_cycle->bill_cycle_code.c_str());
		a[i].b_total_bill_value = b[i].total_bill_value;
		strcpy(a[i].b_start_date, start_date.c_str());
		strcpy(a[i].b_end_date, end_date.c_str());
		strcpy(a[i].b_due_date, due_date.c_str());
		strcpy(a[i].b_bill_date, bill_date.c_str());
		a[i].b_balance_bf = b[i].balance_bf;
		a[i].b_balance_cf = b[i].balance_cf;
		a[i].b_bill_payments = b[i].bill_payments;
		a[i].b_run_no = gsm_bill_cycle->run_no;
		strcpy(a[i].b_printed,"N");
		strcpy(a[i].b_corporate_bill_code,b[i].corporate_bill_code);
		a[i].b_random_no = 0; //-- rand()/(int)(((unsigned)RAND_MAX + 1) / 10E6);
		

		/*
		cout
		<<" bill no		="<<a[i].b_bill_no<<endl
		<<" client_code	="<<a[i].b_client_code<<endl
		<<" account_no	="<<a[i].b_account_no<<endl
		<<" br_code		="<<a[i].b_br_code<<endl
		<<" bill_value	="<<a[i].b_total_bill_value<<endl
		<<" start_date	="<<a[i].b_start_date<<endl
		<<" end_date	="<<a[i].b_end_date<<endl
		<<" due_date	="<<a[i].b_due_date<<endl
		<<" bill_date	="<<a[i].b_bill_date<<endl
		<<" balance_bf	="<<a[i].b_balance_bf<<endl
		<<" balance cf	="<<a[i].b_balance_cf<<endl
		<<" payments	="<<a[i].b_bill_payments<<endl
		<<" corp_code	="<<a[i].b_corporate_bill_code<<endl;
		*/		


	}

	for(int j=0; j<1; j++) // precomplier bug ?
	{
		/* EXEC SQL 
		AT CUSTOMER_CARE  
//	FOR :rows_to_insert INSERT INTO BILL_MASTER_RAW VALUES (:a);
//--INTERIM
		FOR :rows_to_insert INSERT INTO BILL_MASTER_I VALUES (:a); */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "insert into BILL_MASTER_I  values (:s1 ,:s2 ,:s3 ,:s4 ,:s5 \
,:s6 ,:s7 ,:s8 ,:s9 ,:s10 ,:s11 ,:s12 ,:s13 ,:s14 ,:s15 ,:s16 )";
  sqlstm.iters = (unsigned int  )rows_to_insert;
  sqlstm.offset = (unsigned int  )2329;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)a->b_client_code;
  sqlstm.sqhstl[0] = (unsigned int  )50;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct bill);
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->b_account_no;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct bill);
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->b_bill_no;
  sqlstm.sqhstl[2] = (unsigned int  )50;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct bill);
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)a->b_due_date;
  sqlstm.sqhstl[3] = (unsigned int  )50;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct bill);
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)a->b_bill_date;
  sqlstm.sqhstl[4] = (unsigned int  )50;
  sqlstm.sqhsts[4] = (         int  )sizeof(struct bill);
  sqlstm.sqindv[4] = (         void  *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)a->b_start_date;
  sqlstm.sqhstl[5] = (unsigned int  )50;
  sqlstm.sqhsts[5] = (         int  )sizeof(struct bill);
  sqlstm.sqindv[5] = (         void  *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)a->b_end_date;
  sqlstm.sqhstl[6] = (unsigned int  )50;
  sqlstm.sqhsts[6] = (         int  )sizeof(struct bill);
  sqlstm.sqindv[6] = (         void  *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)&a->b_balance_bf;
  sqlstm.sqhstl[7] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[7] = (         int  )sizeof(struct bill);
  sqlstm.sqindv[7] = (         void  *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (         void  *)&a->b_total_bill_value;
  sqlstm.sqhstl[8] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[8] = (         int  )sizeof(struct bill);
  sqlstm.sqindv[8] = (         void  *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned int  )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (         void  *)&a->b_balance_cf;
  sqlstm.sqhstl[9] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[9] = (         int  )sizeof(struct bill);
  sqlstm.sqindv[9] = (         void  *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned int  )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (         void  *)a->b_br_code;
  sqlstm.sqhstl[10] = (unsigned int  )50;
  sqlstm.sqhsts[10] = (         int  )sizeof(struct bill);
  sqlstm.sqindv[10] = (         void  *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned int  )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (         void  *)&a->b_bill_payments;
  sqlstm.sqhstl[11] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[11] = (         int  )sizeof(struct bill);
  sqlstm.sqindv[11] = (         void  *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned int  )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (         void  *)&a->b_run_no;
  sqlstm.sqhstl[12] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(struct bill);
  sqlstm.sqindv[12] = (         void  *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned int  )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (         void  *)a->b_printed;
  sqlstm.sqhstl[13] = (unsigned int  )2;
  sqlstm.sqhsts[13] = (         int  )sizeof(struct bill);
  sqlstm.sqindv[13] = (         void  *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned int  )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (         void  *)a->b_corporate_bill_code;
  sqlstm.sqhstl[14] = (unsigned int  )50;
  sqlstm.sqhsts[14] = (         int  )sizeof(struct bill);
  sqlstm.sqindv[14] = (         void  *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned int  )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (         void  *)&a->b_random_no;
  sqlstm.sqhstl[15] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[15] = (         int  )sizeof(struct bill);
  sqlstm.sqindv[15] = (         void  *)0;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned int  )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


	}


	/* EXEC SQL AT CUSTOMER_CARE COMMIT; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2421;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 

	delete a;
}


void connections::db_insert_bill_items_block(int bill_items_pending_insert, bill_item_block *b)
{
/* EXEC SQL BEGIN DECLARE SECTION; */ 

struct bill_item{
  char	b_BILL_NO[20];			//	NUMBER(10)
  char	b_ITEM_CODE[20];		//	VARCHAR2(10)
  float	b_VALUE;				//	NUMBER(12,2)
  } *a;
  int rows_to_insert;
/* EXEC SQL END DECLARE SECTION; */ 


	// initalise account number & invoice number common for all items in bill summary
	rows_to_insert = bill_items_pending_insert;
	if((a = new bill_item[BILL_BLOCK_SIZE*50])==NULL)
	{
		cout<<" cant allocate memory for bill block"<<endl;
		exit(0);
	}

	for(int i=0; i<bill_items_pending_insert; i++)
	{
		strcpy(a[i].b_BILL_NO, b[i].bill_no);
		strcpy(a[i].b_ITEM_CODE, b[i].item_code);
		a[i].b_VALUE=b[i].value;
		//cout<<i<<" bill no = "<<a[i].b_BILL_NO<<" code = "<<a[i].b_ITEM_CODE<<" val = "<<a[i].b_VALUE<<endl;
	}


	for(int j=0; j<1; j++)	// precomplier bug ?
	{
		/* EXEC SQL 
		AT CUSTOMER_CARE 
//--INTERIM
	FOR :rows_to_insert INSERT INTO BILL_SUMMARY_ITEMS_I VALUES (:a); */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "insert into BILL_SUMMARY_ITEMS_I  values (:s1 ,:s2 ,:s3 )";
  sqlstm.iters = (unsigned int  )rows_to_insert;
  sqlstm.offset = (unsigned int  )2449;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)a->b_BILL_NO;
  sqlstm.sqhstl[0] = (unsigned int  )20;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct bill_item);
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->b_ITEM_CODE;
  sqlstm.sqhstl[1] = (unsigned int  )20;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct bill_item);
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&a->b_VALUE;
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[2] = (         int  )sizeof(struct bill_item);
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


//	FOR :rows_to_insert INSERT INTO BILL_SUMMARY_ITEMS_RAW VALUES (:a);
	}

	/* EXEC SQL AT CUSTOMER_CARE COMMIT; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2489;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 // remove when debug is done TODO
	delete a;
}

 
void connections::db_read_interim_bill_date()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		char b_date[BUF_LEN];
	/* EXEC SQL END DECLARE SECTION; */ 


    /* EXEC SQL WHENEVER NOT FOUND GOTO notfound_bill_date; */ 


	/* EXEC SQL
	AT CUSTOMER_CARE 
	SELECT to_char(sysdate,'YYYYMMDD')
    INTO :b_date
    FROM DUAL; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select to_char(sysdate,'YYYYMMDD') into :b0  from DUAL ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2517;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)b_date;
 sqlstm.sqhstl[0] = (unsigned int  )50;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode == 1403) goto notfound_bill_date;
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	bill_date = b_date; 
    printf("\n bill date = %s \n\n",b_date);
	return;

notfound_bill_date:
	printf("\n bill date not found");
	exit(0);

}


void connections::db_truncate_tables()
{
/*
	cout<<" Updating Anyware "<<endl;
	EXEC SQL
	AT CUSTOMER_CARE 
	insert into sms_charges (select * from sms_charges_v 
	where delivered_time > (select max(delivered_time) from sms_charges));
*/


	cout<<" Dropping summary index "<<endl;
	/* EXEC SQL
	AT CUSTOMER_CARE 
	DROP INDEX BILL_NO_INDX_I; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "drop INDEX BILL_NO_INDX_I";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2549;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	cout<<" Dropping bill master index "<<endl;
	/* EXEC SQL
	AT CUSTOMER_CARE 
	drop index INDX_BILL_MASTER_I; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "drop index INDX_BILL_MASTER_I";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2577;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	cout<<" Tuncating bill master interim"<<endl;
	/* EXEC SQL
	AT CUSTOMER_CARE 
	TRUNCATE TABLE BILL_MASTER_I; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "truncate TABLE BILL_MASTER_I";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2605;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	cout<<" Tuncating bill summary items interim"<<endl;
	/* EXEC SQL
	AT CUSTOMER_CARE 
	TRUNCATE TABLE BILL_SUMMARY_ITEMS_I; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "truncate TABLE BILL_SUMMARY_ITEMS_I";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2633;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	return;
}


void connections::db_create_indexes()
{
	cout<< " Creating index on BILL_MASTER_I "<<endl;
	/* EXEC SQL
	AT CUSTOMER_CARE 
	CREATE INDEX "INDX_BILL_MASTER_I" 
	ON "BILL_MASTER_I"("ACCOUNT_NO") 
	TABLESPACE "INDX" 
	STORAGE ( INITIAL 10M NEXT 10M) NOLOGGING; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "create INDEX \"INDX_BILL_MASTER_I\" ON \"BILL_MASTER_I\" ( \"\
ACCOUNT_NO\" ) TABLESPACE \"INDX\" STORAGE ( INITIAL 10 M NEXT 10 M ) NOLOGGIN\
G";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2661;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	cout<<" Creating index  on BILL_SUMMARY_ITEMS_I "<<endl;
	/* EXEC SQL
	AT CUSTOMER_CARE 
	CREATE INDEX "BILL_NO_INDX_I" 
	ON "BILL_SUMMARY_ITEMS_I"("BILL_NO") 
	TABLESPACE "INDX" 
	STORAGE ( INITIAL 10M NEXT 10M) NOLOGGING; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "create INDEX \"BILL_NO_INDX_I\" ON \"BILL_SUMMARY_ITEMS_I\" \
( \"BILL_NO\" ) TABLESPACE \"INDX\" STORAGE ( INITIAL 10 M NEXT 10 M ) NOLOGGI\
NG";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2689;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


}











