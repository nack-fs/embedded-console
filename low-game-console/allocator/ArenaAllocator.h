#pragma once
#include <cstdint>

namespace allocator {
	class ArenaAllocator {
	private:
		uint8_t* _buffer;
		size_t _capacity;
		size_t _offset;
	};
}