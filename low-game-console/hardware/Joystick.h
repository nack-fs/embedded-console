#pragma once
#include <cstdint>
#include <iostream>

namespace hardware {

	class Joystick {
	private:
		uint16_t _axisX; // 12 bits [0 - 4095]
		uint16_t _axisY; // 12 bits [0 - 4095]
		// Needs to be packed in 3 bytes
	public:
		void pack(const uint16_t x, const uint16_t y, uint8_t* output_buffer);

		// TEST
		void bin(uint8_t value);
		void test();
	};
}