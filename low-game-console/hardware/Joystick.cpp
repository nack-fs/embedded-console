#include "Joystick.h"

namespace hardware {
	#define BYTE2BIT 8

	void Joystick::bin(uint8_t value) {
		uint8_t size = sizeof(uint8_t) * BYTE2BIT;
		printf("\n0b");
		for (int x = size - 1; x >= 0; x--) {
			uint8_t bit = (value >> x) & 1U;
			printf("%u", bit);

			if (x % 8 == 0) {
				printf(" ");
			}
		}
		printf("\n");
	}

	void Joystick::pack(const uint16_t x, const uint16_t y, uint8_t* output_buffer) {
		size_t idx = 0;

		// x11-x4 
		output_buffer[idx++] = (uint8_t)(x >> 4);
		// x4-x0 + y11-y8
		output_buffer[idx++] = (uint8_t)(((x & 0xF) << 4) | ((y >> 8) & 0xF)); 
		// y7-y0
		output_buffer[idx++] = (uint8_t)(y & 0xFF);
	}

	void Joystick::test() {
		// --- TEST ---
		uint16_t test[] = { 0x123, 0x456 };
		// x) 0b0000-0001 0010-0011  1 2 3
		// y) 0b0000-0100 0101-0110  4 5 6
		uint8_t out[3] = { 0 };
		pack(test[0], test[1], out);
		// 0x12, 0x34, 0x56
		printf("Test: 0x%02X 0x%02X 0x%02X\n", out[0], out[1], out[2]);
	}
}