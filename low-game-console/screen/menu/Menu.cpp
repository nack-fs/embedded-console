#include "Menu.h"
#include <iostream>
#include <print>

Menu::Menu(LowGameConsole::LGC& console) :
	_console(console), _selectedGame(0) {}

void Menu::renderMenu() {
	std::println("{}",std::string(60, '/'));
	std::println("Select a game: [W/S -> up/down. D -> play game]");
	for (int i = 0; i < _registredGames.size(); i++) {
		std::print("{}", (i == _selectedGame) ? " >> " : "    ");
		std::println("{}", _registredGames[i].name);
	}
	std::println("[C -> turn off]");
	std::println("{}", std::string(60, '/'));
}
