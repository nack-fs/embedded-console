#pragma once

#include <map>
#include <string>
#include <memory>
#include <cstdint>

#include "../screen/IScreen.h"

namespace LowGameConsole {

	class LGC {
	private:
		std::map<std::string, std::unique_ptr<lgc_screen::IScreen>> _screens;
		lgc_screen::IScreen* _currentScreen = nullptr;

	public:
		LGC() = default;
	};

}