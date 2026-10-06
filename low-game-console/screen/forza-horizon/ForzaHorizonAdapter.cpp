#include "ForzaHorizonAdapter.h"
#include "../../console/LGC.h"

ForzaHorizonAdapter::ForzaHorizonAdapter(LowGameConsole::LGC& game) : _API(game) {}

void ForzaHorizonAdapter::buttonUp() {}

void ForzaHorizonAdapter::buttonDown() {}

void ForzaHorizonAdapter::buttonLeft() {
	_API._carX--;
	_API._carY--;
	_API.checkPos();
}

void ForzaHorizonAdapter::buttonRight() {
	_API._carX++;
	_API._carY--;
	_API.checkPos();
}

void ForzaHorizonAdapter::buttonBack() {}

void ForzaHorizonAdapter::render() {
	_API.renderCar();
}

void ForzaHorizonAdapter::reset() {
	_API.reset();
}