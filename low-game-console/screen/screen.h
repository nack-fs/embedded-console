#pragma once

namespace lgc_screen {
	
	class IScreen {
	public:
		virtual ~IScreen() = default;

		virtual void buttonUp() const = 0;
		virtual void buttonDown() const = 0;
		virtual void buttonLeft() const = 0;
		virtual void buttonRight() const = 0;
		virtual void buttonBack() const = 0;
		virtual void render() const = 0;
		virtual void reset() const = 0;
	};

}