#include "MenuAdapter.h"

MenuAdapter::MenuAdapter(LowGameConsole::LGC& console) : _API(console) {}

void MenuAdapter::buttonUp(){
	if (_API._selectedGame > 0) {
		_API._selectedGame--;
	}
}

void MenuAdapter::buttonDown(){
	if (_API._selectedGame < _API._games.size() - 1) {
		_API._selectedGame++;
	}
}

void MenuAdapter::buttonLeft(){}

void MenuAdapter::buttonRight(){
	_API._console.setScreen(_API._games[_API._selectedGame]);
}

void MenuAdapter::buttonBack(){
	if (dynamic_cast<MenuAdapter*>(_API._console.getScreen()) != nullptr) {
		_API._console.setExit(LowGameConsole::GameState::Default_Exit);
	}
	else {
		_API._console.setScreen("menu");
	}
}

void MenuAdapter::render(){
	_API.renderMenu();
}

void MenuAdapter::reset(){}
