#include "ShipWars.h"

#include <string>
#include <iostream>
#include <algorithm>
#include <print>

ShipWars::ShipWars(LowGameConsole::LGC& console) : _console(console) {}

void ShipWars::initializeShipWars() {
	_rivals = {
		RedTeam::EMPTY,
		RedTeam::EMPTY,
		RedTeam::ENEMY,
		RedTeam::EMPTY,
		RedTeam::EMPTY,
		RedTeam::ENEMY,
		RedTeam::EMPTY,
		RedTeam::EMPTY,
		RedTeam::ENEMY,
	};

	_obstacles.clear();
	for (const auto& r : _rivals) {
		_obstacles.push_back(r == RedTeam::ENEMY ? _typeObstacles.size() -1 : 0);
	}
	_shipX = 4;
}

void ShipWars::fire() {
	if (_obstacles[_shipX] > 0) {
		_obstacles[_shipX]--;
		return;
	}
	if (_rivals[_shipX] == RedTeam::ENEMY) {
		_rivals[_shipX] = RedTeam::EMPTY;

		bool noRivals = std::none_of(_rivals.begin(), _rivals.end(),
			[](RedTeam rival) {
				return rival == RedTeam::ENEMY;
			});

		if (noRivals) {
			_console.gameFinished();
			std::println("Well done!! There are no enemies in sight.");
		}
	}
}

void ShipWars::renderShipWars() {
	std::println();

	int screenSize = static_cast<int>(_rivals.size());

	std::print("┌");
	for (int i = 0; i < screenSize; i++) { std::print("─"); }
	std::println("┐");

	std::print("|");
	for (const auto r : _rivals) {
		std::print("{}", r == RedTeam::EMPTY ? " " : "¥");
	}
	std::println("|");
	renderLine(screenSize);

	std::print("|");
	for (const auto o : _obstacles) {
		std::print("{}", _typeObstacles[o]);
	}
	std::println("|");
	renderLine(screenSize);

	std::println("|{}{}{}|", 
		std::string(_shipX, ' '), 
		'^', 
		std::string(screenSize - _shipX - 1, ' '));

	std::print("└");
	for (int i = 0; i < screenSize; i++) { std::print("─"); }
	std::println("┘");
}

void ShipWars::renderLine(int size) {
	std::println("|{}|",std::string(size, ' '));
}

void ShipWars::reset() {
	std::println("----------------------------");
	std::println("Ship Wars!");
	std::println("[W -> shoot. A/D -> left/right]");
	std::println("[C -> menu]");

	initializeShipWars();
}