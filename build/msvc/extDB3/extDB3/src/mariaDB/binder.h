/*
 * extDB3
 * © 2016 Declan Ireland <https://bitbucket.org/torndeco/extdb3>
 */

#pragma once

#include "../db/abstract_binder.h"

#include <string>
#include <vector>

#include <mariadb/mysql.h>


class MariaDBBinder : public db::AbstractBinder
{
public:
	MariaDBBinder(MYSQL* mysql_ptr, std::size_t size);
	~MariaDBBinder();

	void bind(std::size_t pos) override;
	void bind(std::size_t pos, const std::string& str) override;

	void binder(std::size_t& pos, int type, const void* buffer, int length) override;

	void clear() override;

private:
	MYSQL* mysql_ptr;
	MYSQL_BIND* mysql_binds = NULL;

	std::size_t size;

	std::vector<MYSQL_TIME*> mysql_times;
};
