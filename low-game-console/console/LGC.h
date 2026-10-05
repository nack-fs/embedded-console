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
		uint8_t _exit;

	public:
		LGC() {createScenes();}

		void createScenes();

		// --- Console Buttons ---
		void upClick();
		void downClick();
		void leftClick();
		void rightClick();
		void backClick();

		// --- Console methods ---
		lgc_screen::IScreen* getScreen() const;

		void setScreen(std::string screenName) {
			auto screen = _screens.find(screenName);
			if (screen != _screens.end()) {
				_currentScreen = screen->second.get();
				restart();
			}
		}

		std::map<std::string, std::unique_ptr<lgc_screen::IScreen>>& getScreens() const;

		void setExit(uint8_t exit) {
			_exit = exit;
		}

		uint8_t exit() const;

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