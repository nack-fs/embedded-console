#include "LGC.h"

namespace LowGameConsole {

	void LGC::addScreen(const std::string& name, std::unique_ptr<lgc_screen::IScreen> screen) {
		_screens[name] = std::move(screen);
	}

	void LGC::setScreen(const std::string& name) {
		auto screen = _screens.find(name);
		if (screen != _screens.end()) {
			_currentScreen = screen->second.get();
			_currentScreen->reset();
		}
	}

	void LGC::render() const {
		if (_currentScreen != nullptr) {
			_currentScreen->render();
		}
	}
}