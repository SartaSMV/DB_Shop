#pragma once

#include <queue> 
#include <utility>
#include <vector>

#include "DB.h"
#include "ShopDB.h"
#include "option.h"

using std::queue;
using std::pair;
using std::vector;

class Shop
{
private:
	ShopDB *shDB;

	queue <vector <pair<int, int>>> _orders;
	queue <pair<int, int>> _ordersStorage;
public:
	Shop();

	void makeOrder(const vector < pair<int, int>> ids);
	bool giveOrder();

	~Shop();
};

