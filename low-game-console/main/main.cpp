#include <iostream>
#include <cctype>
#include <string>
#include <stdexcept>
#include <windows.h>

#include "../console/LGC.h"
#include "../hardware/Joystick.h"

static char getKey() {
	const std::string validKeys = "WASDC";
	char nextChar;

	do {
		std::cin >> nextChar;
		nextChar = static_cast<char>(std::toupper(nextChar));
	} while (validKeys.find(nextChar) == std::string::npos);

	return nextChar;
}

static void test(LowGameConsole::LGC& console) {
	do {
		console.render();
		char key = getKey();

		switch (key) {
		case 'W': console.upClick(); break;
		case 'S': console.downClick(); break;
		case 'A': console.leftClick(); break;
		case 'D': console.rightClick(); break;
		case 'C': console.backClick(); break;
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