#pragma once

#include <string>
#include <vector>

namespace db {
	class AbstractBinder
	{
	public:
		virtual ~AbstractBinder() {};

		virtual void bind(std::size_t pos) = 0;
		virtual void bind(std::size_t pos, const std::string& str) = 0;

		virtual void binder(std::size_t& pos, int type, const void* buffer, int length) = 0;

		virtual void clear() = 0;
	};
}