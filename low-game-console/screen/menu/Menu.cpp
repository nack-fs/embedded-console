#include "Menu.h"
#include <iostream>

Menu::Menu(LowGameConsole::LGC& console) : 
	_console(console), _selectedGame(0) 
{
	for (const auto& [name, screen] : _console.getScreens()) {
		if (name != "menu") { _games.push_back(name); }
	}
}

void Menu::renderMenu() {
	std::cout << "\n--------------------";
	std::cout << "Select a game: [W/S -> up/down. D -> play game]";
	for (int i = 0; i < _games.size(); i++) {
		std::cout << (i == _selectedGame) ? " >> " : "    ";
		std::cout << _games[i];
	}
	std::cout << "[C -> turn off]";
}
