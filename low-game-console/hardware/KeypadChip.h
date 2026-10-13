#pragma once

#include <cstdint>

namespace hardware {
	
	class KeypadChip {
	private:
		uint8_t _bufferState;

	public:
		static constexpr uint8_t UP_CLICK = 1U << 0;
		static constexpr uint8_t DOWN_CLICK = 1U << 1;
		static constexpr uint8_t LEFT_CLICK = 1U << 2;
		static constexpr uint8_t RIGHT_CLICK = 1U << 3;
		static constexpr uint8_t BACK_CLICK = 1U << 4;

		static constexpr uint8_t SAFETY_MODE = 1U << 7; // Safety mode, resets

		void establishOnlyState(uint8_t state);
		void securityMode();
		void reset();
		uint8_t getState() const {return _bufferState;}
	};

}