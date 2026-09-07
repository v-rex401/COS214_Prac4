#ifndef CONTAINEDSTATE_H
#define CONTAINEDSTATE_H

#include "UnitState.h"
#include "ResponderComponent.h"
#include <string>

class ContainedState : public UnitState
{

public:
	void handleStateChange(ResponderComponent *context);

	std::string getStateName();
};

#endif
