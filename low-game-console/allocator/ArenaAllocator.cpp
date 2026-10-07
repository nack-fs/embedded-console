#include "ArenaAllocator.h"
#include <stdexcept>

#define BUS_WIDTH 8

namespace allocator {
	void ArenaAllocator::init_arena(uint8_t* backing_buffer, size_t buffer_size){
		_buffer = backing_buffer;
		_capacity = buffer_size;
		_offset = 0;
	}

	void* ArenaAllocator::alloc(size_t request) {
		if (_offset + request > _capacity) {
			throw std::exception("The Arena has not free space...");
		}

		size_t newOffset = _offset + request;
		newOffset = (newOffset + BUS_WIDTH - 1) & ~(BUS_WIDTH - 1);
		_offset = newOffset;

		void* ptr = (void*)_buffer[_offset];
		return ptr;
	}

	void ArenaAllocator::reset() {
		_offset = 0;
	}
}