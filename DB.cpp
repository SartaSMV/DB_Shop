#include "DB.h"

DB::DB()
{
	// Получаем дескриптор соединения
	conn = mysql_init(NULL);
	if (conn == NULL)
	{
		// Если дескриптор не получен – выводим сообщение об ошибке
		fprintf(stderr, "Error: can'tcreate MySQL-descriptor\n");
		//exit(1); //Если используется оконное приложение
	}
	if (!mysql_real_connect(conn, host, login, password, db, NULL, NULL, 0))
	{
		// Если нет возможности установить соединение с сервером
		// базы данных выводим сообщение об ошибке
		fprintf(stderr, "Error: can'tconnecttodatabase %s\n", mysql_error(conn));
	}
	else
	{
		// Если соединение успешно установлено выводим фразу - "Success!"
		fprintf(stdout, "Success!\n");
	}
	mysql_set_character_set(conn, "utf8");
}

void DB::query(string query)
{
	//Делаем запрос к таблице
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