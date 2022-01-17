#pragma once

#include<iostream>
#include<string>

#include <mysql.h>

using std::cout;
using std::endl;
using std::string;

class DB
{
private:
	MYSQL* _conn;

public:
	DB(string _host, string _login, string _password, string _db);

	void query(string query);
	MYSQL_RES *result();

	~DB();
};

