#pragma once

#include <string>
#include <vector>

#include "abstract.h"
#include "abstract_connector.h"

namespace db {
	class AbstractQuery {
	public:
		virtual ~AbstractQuery() = 0;

		virtual void init(AbstractConnector& connector) = 0;
		virtual void send(std::string& sql_query) = 0;
		virtual void get(int& check_dataType_string, bool& check_dataType_null, std::string& insertID, std::vector<std::vector<std::string>>& result_vec) = 0;
		virtual void get(std::vector<db::SQL_OPTION>& output_options, std::string& strip_chars, int& strip_chars_mode, std::string& insertID, std::vector<std::vector<std::string>>& result_vec) = 0;
	};
}