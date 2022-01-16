#include "DB.h"

DB::DB()
{
	// �������� ���������� ����������
	conn = mysql_init(NULL);
	if (conn == NULL)
	{
		// ���� ���������� �� ������� � ������� ��������� �� ������
		fprintf(stderr, "Error: can'tcreate MySQL-descriptor\n");
		//exit(1); //���� ������������ ������� ����������
	}
	if (!mysql_real_connect(conn, host, login, password, db, NULL, NULL, 0))
	{
		// ���� ��� ����������� ���������� ���������� � ��������
		// ���� ������ ������� ��������� �� ������
		fprintf(stderr, "Error: can'tconnecttodatabase %s\n", mysql_error(conn));
	}
	else
	{
		// ���� ���������� ������� ����������� ������� ����� - "Success!"
		fprintf(stdout, "Success!\n");
	}
	mysql_set_character_set(conn, "utf8");
}

void DB::query(string query)
{
	//������ ������ � �������
	if(mysql_query(conn, query.c_str()))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
	}
}

MYSQL_RES* DB::result()
{
	return mysql_store_result(conn);
}

DB::~DB()
{
	mysql_close(conn);
}