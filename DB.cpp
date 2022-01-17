#include "DB.h"

DB::DB()
{
	// �������� ���������� ����������
	_conn = mysql_init(NULL);
	if (_conn == NULL)
	{
		// ���� ���������� �� ������� � ������� ��������� �� ������
		fprintf(stderr, "Error: can'tcreate MySQL-descriptor\n");
		//exit(1); //���� ������������ ������� ����������
	}
	if (!mysql_real_connect(_conn, host, login, password, db, NULL, NULL, 0))
	{
		// ���� ��� ����������� ���������� ���������� � ��������
		// ���� ������ ������� ��������� �� ������
		fprintf(stderr, "Error: can'tconnecttodatabase %s\n", mysql_error(_conn));
	}
	else
	{
		// ���� ���������� ������� ����������� ������� ����� - "Success!"
		fprintf(stdout, "Success!\n");
	}
	mysql_set_character_set(_conn, "utf8");
}

void DB::query(string query)
{
	//������ ������ � �������
	if(mysql_query(_conn, query.c_str()))
	{
		fprintf(stderr, "%s\n", mysql_error(_conn));
	}
}

MYSQL_RES* DB::result()
{
	return mysql_store_result(_conn);
}

DB::~DB()
{
	mysql_close(_conn);
}