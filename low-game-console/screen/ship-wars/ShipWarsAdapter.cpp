#include "ShipWarsAdapter.h"

ShipWarsAdapter::ShipWarsAdapter(LowGameConsole::LGC& game) : _API(game) {}

void ShipWarsAdapter::buttonUp() {
	_API.fire();
}

void ShipWarsAdapter::buttonDown() {}

void ShipWarsAdapter::buttonLeft() {
	if (_API._shipX > 0) {
		_API._shipX--;
	}
}

void ShipWarsAdapter::buttonRight() {
	if (_API._shipX < _API._rivals.size() -1) {
		_API._shipX++;
	}
}

void ShipWarsAdapter::buttonBack() {}

void ShipWarsAdapter::render() {
	_API.renderShipWars();
}

void ShipWarsAdapter::reset() {
	_API.reset();
}