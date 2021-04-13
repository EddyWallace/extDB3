/*
 * extDB3
 * © 2016 Declan Ireland <https://bitbucket.org/torndeco/extdb3>
 */

#pragma once

#include "pool.h"
#include "../db/abstract_session.h"

class MariaDBSession : db::AbstractSession
{
public:
	MariaDBSession(MariaDBPool* database_pool);
	~MariaDBSession();

	void resetSession() override;

private:
	MariaDBPool* database_pool_ptr;
};
