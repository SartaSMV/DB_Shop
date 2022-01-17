#include "DB.h"

DB::DB(string _host, string _login, string _password, string _db)
{
	_conn = mysql_init(NULL);
	if (_conn == NULL) exit(1);
	if (!mysql_real_connect(_conn, _host.c_str(), _login.c_str(), _password.c_str(), _db.c_str(), NULL, NULL, 0))
	{
		cout << "Error: can'tconnecttodatabase " << mysql_error(_conn) << endl;
		exit(2);
	}
	mysql_set_character_set(_conn, "utf8");
}

void DB::query(string query)
{
	if(mysql_query(_conn, query.c_str()))
	{
		cout << mysql_error(_conn) << endl;
	}
}

MYSQL_RES* DB::result()
{
	return mysql_store_result(_conn);
}

DB::~DB()
{
	mysql_close(_conn);
}