/*
 * extDB3
 * © 2016 Declan Ireland <https://bitbucket.org/torndeco/extdb3>
 */

#pragma once

 //Lazy Method to prevent circular dependency issue between SQL_CUSTOM & MariaDBStatement Classes
namespace db {
	struct SQL_OPTION
	{
		bool beguidConvert = false;

		bool boolConvert = false;
		bool nullConvert = false;
		bool timeConvert = false;

		bool stringify = false;
		bool stringify2 = false;

		bool string_add_escape_quotes = false;
		bool string_remove_escape_quotes = false;
		bool string_remove_quotes = false;

		bool mysql_escape = false;

		bool strip = false;

		int value_number = -1;
	};

	struct SQL_TIME {
		unsigned int year, month, day, hour, minute, second;
		unsigned long second_part;
		char neg;
		int time_type;
	};

	struct SQL_BIND_PARAMS {
		int type;
		std::string buffer;
		std::unique_ptr<char[]> buffer_c;
		std::size_t length = 0;
		bool is_unsigned = false;
		SQL_TIME time_buffer;
	};
}
