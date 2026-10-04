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

	void buttonUp() const override;
	void buttonDown() const override;
	void buttonLeft() const override;
	void buttonRight() const override;
	void buttonBack() const override;
	void render() const override;
	void reset() const override;
};