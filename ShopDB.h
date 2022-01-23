#pragma once

#include <utility>
#include <vector>
#include <string>
#include <map>

#include<mysql.h>

#include "DB.h"


using std::vector;
using std::string;
using std::pair;
using std::map;

class ShopDB
{
private:
	DB *_db;
	
public:
	ShopDB(DB* _db);

	vector <pair<int, int>> buy(vector <pair<int, int>> ids);
	void update(vector <pair<int, int>> ids);
	

	~ShopDB();
};

