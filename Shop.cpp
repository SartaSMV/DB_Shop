#include "Shop.h"

Shop::Shop()
{
	shDB = new ShopDB(new DB(host, login, password, db));
}

void Shop::makeOrder(const vector < pair<int, int>> ids)
{
	_orders.push(ids);
}

bool Shop::giveOrder()
{
	vector <pair<int, int>> order = _orders.back();

	order = shDB->buy(order);

	bool ok = true;
	for(int i = 0; i < order.size(); i++)
	{
		if(order[i].second < 0)
		{
			ok = false;
			_ordersStorage.push(order[i]);
		}
	}

	if (ok)
	{
		shDB->update(order);
		_orders.pop();
	}

	return ok;
}

Shop::~Shop()
{
	delete shDB;
	shDB = nullptr;
}

