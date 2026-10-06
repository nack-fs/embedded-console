#pragma once

#include <map>
#include <string>
#include <memory>
#include <cstdint>

#include "../screen/IScreen.h"

namespace LowGameConsole {
	
	enum class GameState : uint8_t {
		OK,
		Default_Exit,
		Error_Screen_Fault,
		Error_Illegal_State,
		Abort_Game
	};


	class LGC {
	private:
		std::map<std::string, std::unique_ptr<lgc_screen::IScreen>> _screens;
		lgc_screen::IScreen* _currentScreen = nullptr;
		GameState _exit;

	public:
		LGC() {createScenes();}

		void createScenes();

		// --- Console Buttons ---
		void upClick() { _currentScreen->buttonUp(); }
		void downClick() { _currentScreen->buttonDown(); }
		void leftClick() { _currentScreen->buttonLeft(); }
		void rightClick() { _currentScreen->buttonRight(); }
		void backClick() { _currentScreen->buttonBack(); }

		// --- Console methods ---
		lgc_screen::IScreen* getScreen() const;

		void setScreen(std::string screenName) {
			auto screen = _screens.find(screenName);
			if (screen != _screens.end()) {
				_currentScreen = screen->second.get();
				restart();
			}
		}

		const std::map<std::string, std::unique_ptr<lgc_screen::IScreen>>& getScreens() const;

		void setExit(GameState state) {
			_exit = state;
		}

		const GameState exit() const;

		void render() const{
			_currentScreen->render();
		}

		void gameFinished() {
			render();
			setScreen("menu");
		}

		void restart() const{
			_currentScreen->reset();
		}
	};

}