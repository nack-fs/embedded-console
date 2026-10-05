#pragma once
#include <iostream>
#include "../../console/LGC.h"

class HotWheels {
private:
	static constexpr char GOAL = 'X';
	static constexpr char PATH = '*';

	static constexpr int ROAD_WIDTH = 6;
	static constexpr int ROWS_ABOVE = 6;
	static constexpr int ROWS_BELOW = 2;

	int _carX = 0, _carY = 0;


};