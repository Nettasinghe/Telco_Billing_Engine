

//////////////////////////////////////////////////////////////////////
//
// db.h: methods for database interaction.
// Telco Billing Engine
// developer - Chandika Nettasinghe
// development - 1998-2000
//
//////////////////////////////////////////////////////////////////////



class discount_definition;

void	db_connect(); 
void	db_disconnect(); 
void	db_connect_cust_care(char *a);		// establish connection to database
void 	db_connect_rating(char *a);		// establish connection to database

void	db_fetch_connections();

void	db_fetch_rates();
void	db_fetch_cdrs(int ac_no);
//void	db_fetch_discount_definitions();
void    db_fetch_discount_definitions(discount_definition *gsm_discount_definition);

void db_disconnect_cust_care(void);
void db_disconnect_rating(void);


