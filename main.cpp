#include<iostream>

#include<mysql.h>

#include "DB.h"

using namespace std;

int main(int argc, char** argv[])
{

	system("cls");

	DB db;
	MYSQL_RES* res;
	MYSQL_ROW row;

	int i = 0;

	db.query("SELECT Name FROM goods_storage");

	res = db.result();
	while (row = mysql_fetch_row(res)) {
		for (i = 0; i < mysql_num_fields(res); i++) {
			std::cout << row[i] << "\n"; //¬ыводим все что есть в базе через цикл
		}
	}

	return 0;
}