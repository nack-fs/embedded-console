#pragma once
#include "../IScreen.h"
#include "ForzaHorizon.h"
#include "../../console/LGC.h"

class ForzaHorizonAdapter : public lgc_screen::IScreen {
private:
	ForzaHorizon _API;
public:
	ForzaHorizonAdapter(LowGameConsole::LGC& game);
	~ForzaHorizonAdapter() override = default;

	void buttonUp() override;
	void buttonDown() override;
	void buttonLeft() override;
	void buttonRight() override;
	void buttonBack() override;
	void render() override;
	void reset() override;
};