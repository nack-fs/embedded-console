#include "MenuAdapter.h"

MenuAdapter::MenuAdapter(LowGameConsole::LGC& console) : _API(console) {}

void MenuAdapter::buttonUp(){
	if (_API._selectedGame > 0) {
		_API._selectedGame--;
	}
}

void MenuAdapter::buttonDown(){
	if (_API._selectedGame < _API.N_REGISTRED - 1) {
		_API._selectedGame++;
	}
}

void MenuAdapter::buttonLeft(){}

void MenuAdapter::buttonRight(){
	_API._console.setScreen(_API._registredGames[_API._selectedGame].screenID);
}

void MenuAdapter::buttonBack(){
	if (dynamic_cast<MenuAdapter*>(_API._console.getScreen()) != nullptr) {
		_API._console.setExit(LowGameConsole::GameState::Default_Exit);
	}
	else {
		_API._console.setScreen(LowGameConsole::ScreenID::Menu);
	}
}

void MenuAdapter::render(){
	_API.renderMenu();
}

void MenuAdapter::reset(){}
