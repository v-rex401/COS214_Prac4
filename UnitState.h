#ifndef UNITSTATE_H
#define UNITSTATE_H

#include "ResponderComponent.h"
#include <string>
#include <iostream>

class ResponderComponent; // forward declaration - only used as a pointer below

class UnitState
{

public:
	virtual void handleStateChange(ResponderComponent *context) = 0;

	virtual std::string getStateName() = 0;
};

#endif
