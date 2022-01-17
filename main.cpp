#include<iostream>

#include<mysql.h>

#include "DB.h"
#include "ShopDB.h"

using namespace std;

int main(int argc, char** argv[])
{

	system("cls");

	DB *db = new DB;
	ShopDB shDB(db);

	vector<pair <int, int>> zzz;

	zzz.push_back(pair<int, int>(4, 1));
	zzz.push_back(pair<int, int>(1, 2));

	cout << shDB.checkBuy(zzz);

	return 0;
}