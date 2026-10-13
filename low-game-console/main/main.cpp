#include <iostream>
#include <cctype>
#include <string>
#include <stdexcept>
#include <windows.h>

#include "../console/LGC.h"
#include "../hardware/Joystick.h"

static char getKey() {
	const std::string validKeys = "WASDCO";
	char nextChar;

	do {
		std::cin >> nextChar;
		nextChar = static_cast<char>(std::toupper(nextChar));
	} while (!validKeys.contains(nextChar));

	return nextChar;
}

static void test(LowGameConsole::LGC& console) {
	do {
		console.render();
		char key = getKey();

		switch (key) {
		case 'W': console.establishAction(0x1); break;
		case 'S': console.establishAction(0x2); break;
		case 'A': console.establishAction(0x4); break;
		case 'D': console.establishAction(0x8); break;
		case 'C': console.establishAction(0x10); break;
		case 'O': console.establishAction(0x80); break; // Security mode
		default:
			throw std::invalid_argument("Invalid Key");
		}
	} while (!static_cast<uint8_t>(console.exit()));
}

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	hardware::Joystick joystick;
	joystick.test();
	LowGameConsole::LGC console;
	test(console);
	return 0;
}