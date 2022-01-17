#include "Shop.h"

Shop::Shop()
{
	shDB = new ShopDB(new DB(host, login, password, db));
}

Shop::~Shop()
{
	delete shDB;
	shDB = nullptr;
}
