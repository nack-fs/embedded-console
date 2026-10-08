#pragma once
#include <string>
#include <array>
#include "../../console/LGC.h"

struct MenuNode {
	const char* name;
	LowGameConsole::ScreenID screenID;
};

class Menu {
	friend class MenuAdapter;
private:
	static constexpr int N_REGISTRED = 3;

	static constexpr std::array<MenuNode, N_REGISTRED> _registredGames = { {
		{"Die Hard", LowGameConsole::ScreenID::DieHard},
		{"Forza Horizon", LowGameConsole::ScreenID::ForzaHorizon},
		{"Ship Wars", LowGameConsole::ScreenID::ShipWars}
	}};

	int _selectedGame;
	LowGameConsole::LGC& _console;

public:
	Menu(LowGameConsole::LGC& console);

	void renderMenu();
};