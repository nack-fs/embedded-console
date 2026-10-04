#pragma once
#include <iostream>
#include "../../console/LGC.h"

class DieHard {
	friend class DieHardAdapter;

private:
	static constexpr int WIDTH = 14;
	static constexpr int HEIGHT = 7;

	int _playerX = 0, _playerY = 0;
	int _exitX = 0, _exitY = 0;

	LowGameConsole::LGC& _game;

public:
	DieHard(LowGameConsole::LGC& game) : _game(game) {}

	void initializeDie();
	void checkDieFinished();
	void renderDie() const;
	void reset();
};