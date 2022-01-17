#include "ShopDB.h"

ShopDB::ShopDB(DB* _db) :
	_db(_db)
{

}

bool ShopDB::checkBuy(vector <pair<int, int>> ids)
{
    string query;
    MYSQL_RES* res;
    MYSQL_ROW row;
    map <int, int> buy, count;

    for (int i = 0; i < ids.size(); i++)
    {
        query = "SELECT count, Is_complicated FROM goods_storage WHERE ID_GS = " + std::to_string(ids[i].first);
        _db->query(query);

        res = _db->result();
        row = mysql_fetch_row(res);

        if(atoi(row[1]) == 0)
        {
            count[ids[i].first] = atoi(row[0]);
            buy[ids[i].first] += ids[i].second;
        }
        else
        {
            query = "SELECT ID_P, count FROM recipe WHERE ID_C = " + std::to_string(ids[i].first);

            _db->query(query);

            res = _db->result();

            MYSQL_RES* res2;
            MYSQL_ROW row2;
            while (row = mysql_fetch_row(res))
            {
                query = "SELECT count FROM goods_storage WHERE ID_GS = " + string(row[0]);
                _db->query(query);

                res2 = _db->result();
                row2 = mysql_fetch_row(res2);

                count[atoi(row[0])] = atoi(row2[0]);
                buy[atoi(row[0])] += ids[i].second * atoi(row[1]);
            }
        }

    }

    for (auto i:count)
    {
        if (buy[i.first] > i.second) return false;
    }

    return true;
}


ShopDB::~ShopDB()
{
	delete _db;
	_db = nullptr;
}
