#pragma once

#include <vector>
#include <string>
#include <memory>

#include "abstract.h"
#include "abstract_connector.h"

namespace db {
	class AbstractStatement {
	public:
		virtual ~AbstractStatement() = 0;

		virtual void init(AbstractConnector& connector) = 0;
		virtual void create() = 0;
		virtual void prepare(std::string& sql_query) = 0;
		virtual unsigned long getParamsCount() = 0;
		virtual void bindParams(std::vector<db::SQL_BIND_PARAMS>& params) = 0;
		virtual void execute(std::vector<db::SQL_OPTION>& output_options, std::string& strip_chars, int& strip_chars_mode, std::string& insertID, std::vector<std::vector<std::string>>& result_vec) = 0;
		virtual bool errorCheck() = 0;
	};
}