#include "Menu.h"
#include <iostream>

Menu::Menu(LowGameConsole::LGC& console) :
	_console(console), _selectedGame(0) {}

void Menu::renderMenu() {
	std::cout << std::string(60, '/') << std::endl;
	std::cout << "Select a game: [W/S -> up/down. D -> play game]\n";
	for (int i = 0; i < _registredGames.size(); i++) {
		std::cout << ((i == _selectedGame) ? " >> " : "    ");
		std::cout << _registredGames[i].name << "\n";
	}
	std::cout << "[C -> turn off]\n";
	std::cout << std::string(60, '/') << std::endl;
}
