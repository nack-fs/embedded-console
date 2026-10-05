#include "LGC.h"

#include "../screen/die-hard/DieHardAdapter.h"

namespace LowGameConsole {

	void LGC::createScenes() {
		_screens["die-hard"] = std::make_unique<DieHardAdapter>(*this);

		setScreen("die-hard");
	}
}