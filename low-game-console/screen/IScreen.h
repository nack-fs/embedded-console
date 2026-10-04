#pragma once

namespace lgc_screen {
	
	class IScreen {
	public:
		virtual ~IScreen() = default;

		virtual void buttonUp() = 0;
		virtual void buttonDown() = 0;
		virtual void buttonLeft() = 0;
		virtual void buttonRight() = 0;
		virtual void buttonBack() = 0;
		virtual void render() = 0;
		virtual void reset() = 0;
	};

}