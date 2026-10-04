#pragma once
#include <iostream>

class DieHard {
private:
	static constexpr int WIDTH = 14;
	static constexpr int HEIGHT = 7;

	int _playerX = 0, _playerY = 0;
	int _exitX = 0, _exitY = 0;

public:
	void initializeDie();
	void checkDieFinished();
	void renderDie() const;
	void reset();
};