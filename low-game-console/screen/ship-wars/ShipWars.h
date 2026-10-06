#pragma once

#include <vector>
#include <array>
#include <cstdint>

#include "../../console/LGC.h"

class ShipWars {
private:
	int _shipX = 0;

	enum class RedTeam : uint8_t{
		EMPTY, ENEMY
	};

	std::vector<RedTeam> _rivals;
	std::vector<int> _obstacles;

	const std::array<const char*, 4> _typeObstacles = { " ","▒","▓","█" };

	LowGameConsole::LGC& _console;

public:
	ShipWars(LowGameConsole::LGC& _console);

	void initializeShipWars();
	void fire();
	void renderShipWars();
	void renderLine(int size);
	void reset();
};