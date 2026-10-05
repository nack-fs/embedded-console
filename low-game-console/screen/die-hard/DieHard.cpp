#include "DieHard.h"
#include <iostream>

void DieHard::initializeDie() {
	_playerX = _playerY = 2;
	_exitX = _exitY = 4;
}

void DieHard::checkDieFinished() {
	if (_playerX == _exitX && _playerY == _exitY) {
		_game.gameFinished();
		std::cout << "You have WON!\n" << std::endl;
	}
}

void DieHard::renderDie() const{

	char map[HEIGHT][WIDTH];

	for (int i = 0; i < WIDTH; i++) {
		map[0][i] = '#';
		map[HEIGHT - 1][i] = '#';
	}

	for (int i = 1; i < HEIGHT - 1; i++) {
		map[i][0] = '#';
		map[i][WIDTH - 1] = '#';
		for (int j = 1; j < WIDTH - 1; j++) {
			map[i][j] = ' ';
		}
	}

	map[_exitY][_exitX] = 'X';
	map[_playerY][_playerX] = 'O';

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			std::cout << map[i][j];
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

void DieHard::reset() {
	std::cout << "----------------------------\n";
	std::cout << "Yipi Kai Yay!!!\n";
	std::cout << "[W/S -> up/down. A/D -> left/right]\n";
	std::cout << "[C -> menu]\n";

	initializeDie();
}