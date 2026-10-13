#pragma once

#include <map>
#include <string>
#include <memory>
#include <cstdint>

#include "../screen/IScreen.h"
#include "../allocator/ArenaAllocator.h"
#include "../hardware/KeypadChip.h"

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
		hardware::KeypadChip _keypadBuffer;

	public:
		LGC() {createScenes();}

		void establishAction(uint8_t action);
		void executeAction() {
			switch (_keypadBuffer.getState()) {
				case hardware::KeypadChip::UP_CLICK: _currentScreen->buttonUp(); break;
				case hardware::KeypadChip::DOWN_CLICK: _currentScreen->buttonDown(); break;
				case hardware::KeypadChip::LEFT_CLICK: _currentScreen->buttonLeft(); break;
				case hardware::KeypadChip::RIGHT_CLICK: _currentScreen->buttonRight(); break;
				case hardware::KeypadChip::BACK_CLICK: _currentScreen->buttonBack(); break;
				case hardware::KeypadChip::SAFETY_MODE: reset();
			}
		}

		void createScenes();

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

		void reset() {
			printf("<<<<<	RESET	>>>>>\n");
			_keypadBuffer.reset();
			restart();
		}
	};

}