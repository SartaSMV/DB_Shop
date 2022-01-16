#pragma once

#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string>

#include <mysql.h>

#include "option.h"

using std::string;

class DB
{
private:
	MYSQL* conn;

public:
	DB();

	void query(string query);
	MYSQL_RES *result();

	~DB();
};

