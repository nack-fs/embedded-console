#include "LGC.h"

#include "../screen/die-hard/DieHard.h"

namespace LowGameConsole {

	void LGC::createScenes() {
		_screens["die-hard"] = std::make_unique<DieHard>(*this);

		setScreen("menu");
	}
}