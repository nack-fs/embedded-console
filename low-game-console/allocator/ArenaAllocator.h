#pragma once
#include <cstdint>

namespace allocator {
	class ArenaAllocator {
	private:
		uint8_t* _buffer;
		size_t _capacity;
		size_t _offset;
	public:
		void init_arena(uint8_t* backing_buffer, size_t buffer_size);
		void* alloc(size_t request);
		void reset();
	};
}