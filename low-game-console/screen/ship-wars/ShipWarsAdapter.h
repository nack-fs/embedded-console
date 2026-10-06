#pragma once
#include "../IScreen.h"
#include "ShipWars.h"
#include "../../console/LGC.h"

class ShipWarsAdapter : public lgc_screen::IScreen {
private:
	ShipWars _API;
public:
	ShipWarsAdapter(LowGameConsole::LGC& game);
	~ShipWarsAdapter() override = default;

	void buttonUp() override;
	void buttonDown() override;
	void buttonLeft() override;
	void buttonRight() override;
	void buttonBack() override;
	void render() override;
	void reset() override;
};