#pragma once

#include <memory>

#include "abstract_pool.h"

namespace db {
	class AbstractSession {
	public:
		virtual ~AbstractSession() = 0;

		virtual void resetSession() = 0;

		std::unique_ptr<AbstractPool::SQL_SESSION> data;
	};
}