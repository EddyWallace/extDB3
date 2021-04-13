/*
 * extDB3
 * © 2016 Declan Ireland <https://bitbucket.org/torndeco/extdb3>
 */

#pragma once

#include <string>

#include <mariadb/mysql.h>

#include "../db/abstract_connector.h"

class MariaDBConnector : public db::AbstractConnector
{
public:
	MariaDBConnector();
	~MariaDBConnector();

	void init(std::string &host, unsigned int &port, std::string &user, std::string &password, std::string &db) override;
	void connect() override;
	unsigned long long getInsertId() override;
	int ping() override;

	MYSQL *mysql_ptr;

private:
	bool connected = false;

	struct login_data_struct
	{
		std::string host;
		std::string user;
		std::string password;
		std::string db;
		unsigned int port;
	};
	login_data_struct login_data;

	std::string escapeString(std::string &input_str);
};
