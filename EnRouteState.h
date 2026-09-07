#ifndef ENROUTESTATE_H
#define ENROUTESTATE_H

#include "UnitState.h"
#include "ResponderComponent.h"
#include <string>

class EnRouteState : public UnitState
{

public:
	void handleStateChange(ResponderComponent *context);

	std::string getStateName();
};

#endif
