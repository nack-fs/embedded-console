#pragma once
#include <string>
#include <vector>
#include "../../console/LGC.h"

class Menu {
	friend class MenuAdapter;
private:
	std::vector<std::string> _games;
	int _selectedGame;
	LowGameConsole::LGC& _console;

public:
	Menu(LowGameConsole::LGC& console);

	void renderMenu();
};