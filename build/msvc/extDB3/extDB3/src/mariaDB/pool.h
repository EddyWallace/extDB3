/*
 * extDB3
 * © 2016 Declan Ireland <https://bitbucket.org/torndeco/extdb3>
 */

#pragma once

#include <list>
#include <memory>
#include <mutex>
#include <unordered_map>

#include <boost/asio.hpp>
#include <mariadb/mysql.h>

#include "connector.h"
#include "query.h"
#include "statement.h"

#include "../db/abstract_pool.h"

class MariaDBPool : public db::AbstractPool
{
public:
	MariaDBPool();
	~MariaDBPool();

	void init(std::string& host, unsigned int& port, std::string& user, std::string& password, std::string& db) override;
	std::unique_ptr<db::AbstractPool::SQL_SESSION> get() override;
	void putBack(std::unique_ptr<db::AbstractPool::SQL_SESSION> mariadb_session) override;
	void idleCleanup() override;

private:
	struct login_data_struct
	{
		std::string host;
		std::string user;
		std::string password;
		std::string db;
		unsigned int port;
	};
	login_data_struct login_data;

	std::list<std::unique_ptr<db::AbstractPool::SQL_SESSION>> mariadb_session_pool;
	std::mutex mariadb_session_pool_mutex;
};
