#include "ShipWars.h"

#include <string>
#include <iostream>
#include <algorithm>

ShipWars::ShipWars(LowGameConsole::LGC& console) : _console(console) {}

void ShipWars::initializeShipWars() {
	_rivals = {
		RedTeam::EMPTY,
		RedTeam::EMPTY,
		RedTeam::EMPTY,
		RedTeam::EMPTY,
		RedTeam::EMPTY,
		RedTeam::EMPTY,
		RedTeam::EMPTY,
		RedTeam::EMPTY,
		RedTeam::EMPTY,
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
			std::cout << "Well done!! There are no enemies in sight.";
		}
	}
}

void ShipWars::renderShipWars() {
	std::cout << "\n";

	int screenSize = static_cast<int>(_rivals.size());

	std::cout << "┌";
	for (int i = 0; i < screenSize; i++) std::cout << "─";
	std::cout << "┐\n";

	std::cout << "|";
	for (const auto r : _rivals) {
		std::cout << (r == RedTeam::EMPTY? " " : "¥");
	}
	std::cout << "|\n";
	renderLine(screenSize);

	std::cout << "|";
	for (const auto o : _obstacles) {
		std::cout << _typeObstacles[o];
	}
	std::cout << "|\n";
	renderLine(screenSize);

	std::cout << "│"
		<< std::string(_shipX, ' ')
		<< '^'
		<< std::string(screenSize - _shipX - 1, ' ')
		<< "│\n";

	std::cout << "└";
	for (int i = 0; i < screenSize; i++) std::cout << "─";
	std::cout << "┘\n";
}

void ShipWars::renderLine(int size) {
	std::cout << "|"
		<< std::string(size, ' ')
		<< "|\n";
}

void ShipWars::reset() {
	std::cout << "----------------------------\n";
	std::cout << "Ship Wars!\n";
	std::cout << "[W -> shoot. A/D -> left/right]\n";
	std::cout << "[C -> menu]\n";

	initializeShipWars();
}