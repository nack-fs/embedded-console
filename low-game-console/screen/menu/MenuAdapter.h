#pragma once
#include "../IScreen.h"
#include "../../console/LGC.h"
#include "Menu.h"

class MenuAdapter : public lgc_screen::IScreen {
private:
	Menu _API;
public:
	MenuAdapter(LowGameConsole::LGC& game);
	~MenuAdapter() override = default;

	void buttonUp() override;
	void buttonDown() override;
	void buttonLeft() override;
	void buttonRight() override;
	void buttonBack() override;
	void render() override;
	void reset() override;
};