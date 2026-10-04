#include "DieHardAdapter.h"
#include "../../console/LGC.h"

DieHardAdapter::DieHardAdapter(LowGameConsole::LGC& game) 
	: _API(game) {}

void DieHardAdapter::buttonUp() {
	if (_API._playerY > 1) {
		_API._playerY--;
		_API.checkDieFinished();
	}
}

void DieHardAdapter::buttonDown() {
	if (_API._playerY < DieHard::HEIGHT - 2) {
		_API._playerY++;
		_API.checkDieFinished();
	}
}

void DieHardAdapter::buttonLeft() {
	if (_API._playerX > 1) {
		_API._playerX++;
		_API.checkDieFinished();
	}
}

void DieHardAdapter::buttonRight() {
	if (_API._playerX < DieHard::WIDTH - 2) {
		_API._playerX++;
		_API.checkDieFinished();
	}
}

void DieHardAdapter::buttonBack() {}

void DieHardAdapter::render() {
	_API.renderDie();
}

void DieHardAdapter::reset() {
	_API.reset();
}