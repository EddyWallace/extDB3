/*
 * extDB3
 * © 2016 Declan Ireland <https://bitbucket.org/torndeco/extdb3>
 */

#pragma once

#include <string>
#include <vector>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <mariadb/mysql.h>

#include "../db/abstract.h"
#include "../db/abstract_query.h"
#include "connector.h"

class MariaDBQuery : public db::AbstractQuery
{
public:
	MariaDBQuery();
	~MariaDBQuery();

	void init(db::AbstractConnector& connector) override;
	void send(std::string& sql_query) override;
	void get(int& check_dataType_string, bool& check_dataType_null, std::string& insertID, std::vector<std::vector<std::string>>& result_vec) override;
	void get(std::vector<db::SQL_OPTION>& output_options, std::string& strip_chars, int& strip_chars_mode, std::string& insertID, std::vector<std::vector<std::string>>& result_vec) override;

private:
	MariaDBConnector* connector_ptr;
	std::locale loc_date;
	std::locale loc_datetime;
	std::locale loc_time;
	boost::posix_time::time_facet* facet;
};
