#pragma once

#include <map>
#include <string>
#include <memory>
#include <cstdint>

#include "../screen/IScreen.h"
#include "../allocator/ArenaAllocator.h"

namespace LowGameConsole {

	enum class ScreenID : uint8_t {
		Menu,
		DieHard,
		ForzaHorizon,
		ShipWars
	};
	
	enum class GameState : uint8_t {
		OK,
		Default_Exit,
		Error_Screen_Fault,
		Error_Illegal_State,
		Abort_Game
	};


	class LGC {
	private:
		static constexpr size_t RAM_SIZE = 2 * 1024;
		uint8_t _RAM[RAM_SIZE];

		allocator::ArenaAllocator _allocator;
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

		void setScreen(ScreenID screenID);

		void setExit(GameState state) {
			_exit = state;
		}

		const GameState exit() const;

		void render() const{
			_currentScreen->render();
		}

		void gameFinished() {
			render();
			setScreen(ScreenID::Menu);
		}

		void restart() const{
			_currentScreen->reset();
		}
	};

}