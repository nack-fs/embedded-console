#pragma once
#include <string>
#include <array>

#include "../../console/LGC.h"

class ForzaHorizon {
private:
	static constexpr char GOAL = 'X';
	static constexpr char PATH = '*';

	static constexpr int ROAD_WIDTH = 6;
	static constexpr int ROWS_ABOVE = 6;
	static constexpr int ROWS_BELOW = 2;

	int _carX = 0, _carY = 0;

	std::array<std::string, 11> _road = {
        "  " + GOAL,
        "  " + PATH,
        "    " + PATH,
        "     " + PATH,
        "      " + PATH,
        "      " + PATH,
        "      " + PATH,
        "    " + PATH,
        "  " + PATH,
        " " + PATH,
        " " + PATH
	};

    LowGameConsole::LGC& _console;

public:
    ForzaHorizon(LowGameConsole::LGC& console) : _console(console) {}

    void initializeForzaHorizon();
    void checkPos();
    void renderCar() const;
    void renderRow(int row) const;
    void reset();
};