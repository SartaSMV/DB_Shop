#pragma once

#include <utility>
#include <vector>
#include <string>
#include <map>

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
	ShopDB();
	ShopDB(DB* _db);

	bool checkBuy(vector <pair<int, int>> ids);


	~ShopDB();
};

