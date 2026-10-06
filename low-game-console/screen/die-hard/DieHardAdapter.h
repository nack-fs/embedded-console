#pragma once
#include "../IScreen.h"
#include "DieHard.h"
#include "../../console/LGC.h"

class DieHardAdapter : public lgc_screen::IScreen {
private:
	DieHard _API;

public:
	DieHardAdapter(LowGameConsole::LGC& game);
	~DieHardAdapter() override = default;

	void buttonUp() override;
	void buttonDown() override;
	void buttonLeft() override;
	void buttonRight() override;
	void buttonBack() override;
	void render() override;
	void reset() override;
};