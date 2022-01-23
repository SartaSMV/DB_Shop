#include<iostream>

#include "Shop.h"

using namespace std;

Shop shop;

void makeOrder()
{
	int n;
	pair<int, int> product;
	vector < pair<int, int>> order;

	cout << "Size order: ";
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cout << "Id product = ";
		cin >> product.first;

		cout << "Count product = ";
		cin >> product.second;

		order.push_back(product);
	}

	shop.makeOrder(order);

	system("pause");
}

void giveOrder()
{
	bool ok = shop.giveOrder();

	if(ok)
	{
		cout << "Complete!\n";
	}
	else
	{
		cout << "Sorry, we order goods from storage.\n";
	}

	system("pause");
}

void shopInterface()
{
	bool ok = true;
	int n;

	while(ok)
	{
		system("cls");
		cout << "1-Make order\n2-Give orde\n3-Exite\nInpute: ";

		cin >> n;

		switch (n)
		{
		case 1:
			makeOrder();
			break;
		case 2:
			giveOrder();
			break;
		default:
			ok = false;
			break;
		}
	}
}


int main(int argc, char** argv[])
{
	shopInterface();
	return 0;
}