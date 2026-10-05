#include "LGC.h"

#include "../screen/die-hard/DieHardAdapter.h"

namespace LowGameConsole {

	void LGC::createScenes() {
		_screens["die-hard"] = std::make_unique<DieHardAdapter>(*this);

		setScreen("die-hard");
	}

	lgc_screen::IScreen* LGC::getScreen() const {
		return _currentScreen;
	}

	const std::map<std::string, std::unique_ptr<lgc_screen::IScreen>>& LGC::getScreens() const{
		return _screens;
	}

	const uint8_t LGC::exit() const {
		return _exit;
	}
}