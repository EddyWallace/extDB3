#pragma once

#include <string>

namespace db {
	class AbstractConnector {
	public:
		virtual ~AbstractConnector() = 0;

		virtual void init(std::string& host, unsigned int& port, std::string& user, std::string& password, std::string& db) = 0;
		virtual void connect() = 0;
		virtual unsigned long long getInsertId() = 0;
		virtual int ping() = 0;
	};
}