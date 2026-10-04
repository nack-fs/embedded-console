#pragma once
#include <iostream>

class DieHard {
private:
	static constexpr int WIDTH = 14;
	static constexpr int HEIGHT = 7;

	int playerX = 0, playerY = 0;
	int exitX = 0, exitY = 0;

public:
	void initializeDie();
	void checkDieFinished();
	void renderDie() const;
	void reset();
};