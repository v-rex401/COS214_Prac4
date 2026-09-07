#ifndef DISPATCHEDSTATE_H
#define DISPATCHEDSTATE_H

#include "UnitState.h"
#include "ResponderComponent.h"
#include <string>

class DispatchedState : public UnitState
{

public:
	void handleStateChange(ResponderComponent *context);

	std::string getStateName();
};

#endif
