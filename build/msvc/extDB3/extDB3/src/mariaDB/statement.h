/*
 * extDB3
 * © 2016 Declan Ireland <https://bitbucket.org/torndeco/extdb3>
 */

#pragma once

#include <memory>
#include <vector>

#include <mariadb/mysql.h>

#include "binder.h"
#include "connector.h"

#include "../db/abstract_statement.h"

class MariaDBStatement : public db::AbstractStatement
{
public:
	MariaDBStatement();
	~MariaDBStatement();

	struct mysql_bind_param
	{
		enum_field_types type = MYSQL_TYPE_NULL;
		std::string buffer;
		std::unique_ptr<char[]> buffer_c;
		std::size_t length = 0;
		bool is_unsigned = false;
		MYSQL_TIME time_buffer;
	};

	void init(db::AbstractConnector &connector) override;
	void create() override;
	void prepare(std::string & sql_query) override;
	unsigned long getParamsCount() override;
	void bindParams(std::vector<db::SQL_BIND_PARAMS> &params) override;
	void execute(std::vector<db::SQL_OPTION> &output_options, std::string &strip_chars, int &strip_chars_mode, std::string &insertID, std::vector<std::vector<std::string>> &result_vec) override;
	bool errorCheck() override;

private:
	bool prepared = false;
	MariaDBConnector *connector_ptr;

	MYSQL_RES *mysql_stmt_result_metadata_ptr = NULL;
	MYSQL_STMT *mysql_stmt_ptr = NULL;

	MYSQL_BIND *mysql_bind_params = NULL;
	MYSQL_BIND *mysql_bind_result = NULL;
	MYSQL_FIELD *fields = NULL;

	unsigned int num_fields;

	struct mysql_bind_field
	{
		unsigned long      length;
		my_bool            isNull;
		my_bool            error;
		//enum_field_types   type;

		std::vector<char>  buffer;
		short int          buffer_short;
		int                buffer_long;
		long long int      buffer_longlong;
		float              buffer_float;
		double             buffer_double;
		
		MYSQL_TIME         buffer_mysql_time;
	};
	std::vector<mysql_bind_field> bind_data;
};
