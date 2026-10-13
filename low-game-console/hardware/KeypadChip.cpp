#include "KeypadChip.h"

namespace hardware {

	void KeypadChip::establishOnlyState(uint8_t state) {
		if (state == 0 || ((state & (state - 1)) != 0)) {
			KeypadChip::securityMode();
			return;
		}
		KeypadChip::reset();
		_bufferState |= state;
	}

	void KeypadChip::securityMode() {
		KeypadChip::reset();
		_bufferState |= SAFETY_MODE;
	}

	void KeypadChip::reset() {
		_bufferState &= 0x00;
	}
}