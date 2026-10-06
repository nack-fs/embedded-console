#include "LGC.h"

#include "../screen/die-hard/DieHardAdapter.h"
#include "../screen/forza-horizon/ForzaHorizonAdapter.h"
#include "../screen/ship-wars/ShipWarsAdapter.h"
#include "../screen/menu/MenuAdapter.h"

namespace LowGameConsole {

	void LGC::createScenes() {
		_screens["Die Hard"] = std::make_unique<DieHardAdapter>(*this);
		_screens["Forza Horizon"] = std::make_unique<ForzaHorizonAdapter>(*this);
		_screens["Ship Wars"] = std::make_unique<ShipWarsAdapter>(*this);

		_screens["menu"] = std::make_unique<MenuAdapter>(*this);

		setScreen("menu");
	}

	lgc_screen::IScreen* LGC::getScreen() const {
		return _currentScreen;
	}

	const std::map<std::string, std::unique_ptr<lgc_screen::IScreen>>& LGC::getScreens() const{
		return _screens;
	}

	const GameState LGC::exit() const {
		return _exit;
	}
}