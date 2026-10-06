#pragma once
#include <string>
#include <array>

#include "../../console/LGC.h"

class ForzaHorizon {
    friend class ForzaHorizonAdapter;

private:
	static constexpr const char* GOAL = "X";
	static constexpr const char* PATH = "*";

	static constexpr int ROAD_WIDTH = 6;
	static constexpr int ROWS_ABOVE = 6;
	static constexpr int ROWS_BELOW = 2;

	int _carX = 0, _carY = 0;

	std::array<std::string, 11> _road = {
        std::string("  ") + GOAL,
        std::string("  ") + PATH,
        std::string("    ") + PATH,
        std::string("     ") + PATH,
        std::string("      ") + PATH,
        std::string("      ") + PATH,
        std::string("      ") + PATH,
        std::string("    ") + PATH,
        std::string("  ") + PATH,
        std::string(" ") + PATH,
        std::string(" ") + PATH
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