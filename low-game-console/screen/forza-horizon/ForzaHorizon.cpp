#include "ForzaHorizon.h"
#include <iostream>
#include <print>

void ForzaHorizon::initializeForzaHorizon() {
	_carX = 5;
	_carY = _road.size() - 1;
}

void ForzaHorizon::checkPos() {
	if (_carY == 0) {
		_console.gameFinished();
		std::println("You have arrived to your destination!!");
		return;
	}

	auto row = _road[_carY];
	int leftlim = row.find(PATH);
	int rightlim = leftlim + ROAD_WIDTH + 1;

	if (_carX <= leftlim || _carX >= rightlim) {
		std::println("Pum! Smash!!");
		initializeForzaHorizon();
	}
}

void ForzaHorizon::renderCar() const{
	for (int row = _carY - ROWS_ABOVE; row <= _carY + ROWS_BELOW; row++) {
		renderRow(row);
	}
}

void ForzaHorizon::renderRow(int row) const{
	if (row < 0 || row >= _road.size()) {
		std::cout << std::endl;
		return;
	}

	std::string line = "";

	if (row == 0) {
		line += " ########";
	}
	else {
		int padding = _road[row].find(PATH);

		line += std::string(padding, ' ');

		char border = '|';
		if (row < static_cast<int>(_road.size()) - 1) {
			const auto& rowBellow = _road[row + 1];
			int paddingBelow = rowBellow.find(PATH);

			if (paddingBelow > padding) {
				border = '\\';
			}
			else if (paddingBelow < padding) {
				border = '/';
			}

			line += border;
			line += std::string(ROAD_WIDTH, ' ');
			line += border;

			if (_carY == row) {
				if (_carX < static_cast<int>(line.size())) {
					line.replace(_carX, 1, "█");
				}
			}

			std::println(line);
		}
	}
}

void ForzaHorizon::reset() {
	std::println("----------------------------");
	std::println("Forza Horizon");
	std::println("[A/D -> left/right]");
	std::println("[C -> menu]");
	initializeForzaHorizon();
}
