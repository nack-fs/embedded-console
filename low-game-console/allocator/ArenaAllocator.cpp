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
		size_t alignedOffset = (_offset + BUS_WIDTH - 1) & ~(BUS_WIDTH - 1);
		if (alignedOffset + request > _capacity) {
			throw std::runtime_error("The Arena has not free space...");
		}

		void* ptr = (void*)&_buffer[alignedOffset];
		_offset = alignedOffset + request;

		return ptr;
	}

	void ArenaAllocator::reset() {
		_offset = 0;
	}
}