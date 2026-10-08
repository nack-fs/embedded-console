#include "LGC.h"

#include "../screen/die-hard/DieHardAdapter.h"
#include "../screen/forza-horizon/ForzaHorizonAdapter.h"
#include "../screen/ship-wars/ShipWarsAdapter.h"
#include "../screen/menu/MenuAdapter.h"

namespace LowGameConsole {

	void LGC::createScenes() {
		_allocator.init_arena(_RAM, RAM_SIZE);
		setScreen(LowGameConsole::ScreenID::Menu);
	}

	void LGC::setScreen(ScreenID screenID) {
		if (_currentScreen != nullptr) {
			_currentScreen->~IScreen();
			_currentScreen = nullptr;
		}
		_allocator.reset();

		switch (screenID) {
			case ScreenID::Menu: {
				void* memory = _allocator.alloc(sizeof(MenuAdapter));
				_currentScreen = new (memory) MenuAdapter(*this);
				break;
			}
			case ScreenID::DieHard: {
				void* memory = _allocator.alloc(sizeof(DieHardAdapter));
				_currentScreen = new (memory) DieHardAdapter(*this);
				break;
			}
			case ScreenID::ForzaHorizon: {
				void* memory = _allocator.alloc(sizeof(ForzaHorizonAdapter));
				_currentScreen = new (memory) ForzaHorizonAdapter(*this);
				break;
			}
			case ScreenID::ShipWars: {
				void* memory = _allocator.alloc(sizeof(ShipWarsAdapter));
				_currentScreen = new (memory) ShipWarsAdapter(*this);
				break;
			}
		}

		restart();
	}

	lgc_screen::IScreen* LGC::getScreen() const {
		return _currentScreen;
	}

	const GameState LGC::exit() const {
		return _exit;
	}
}