#pragma once

#include <list>
#include <memory>
#include <mutex>
#include <unordered_map>

#include <boost/asio.hpp>

#include "abstract_connector.h"
#include "abstract_query.h"
#include "abstract_statement.h"

namespace db {
	class AbstractPool {
	public:
		virtual ~AbstractPool() = 0;

		struct SQL_SESSION
		{
			boost::posix_time::ptime last_used;
			AbstractConnector* connector;
			AbstractQuery* query;
			std::unordered_map<std::string, std::vector<AbstractStatement> > statements;
		};

		virtual void init(std::string& host, unsigned int& port, std::string& user, std::string& password, std::string& db) = 0;
		virtual std::unique_ptr<SQL_SESSION> get() = 0;
		virtual void putBack(std::unique_ptr<SQL_SESSION> sql_session) = 0;
		virtual void idleCleanup() = 0;
	};
}