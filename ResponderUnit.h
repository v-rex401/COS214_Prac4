#ifndef RESPONDERUNIT_H
#define RESPONDERUNIT_H

#include "ResponderComponent.h"
#include <string>
#include <vector>

class ResponderUnit : public ResponderComponent
{

private:
	std::string name;
	UnitState *currentState;

public:
	ResponderUnit(std::string name);

	void executeAction();

	std::string getName();

	void setState(UnitState *newState);

	void advanceState();

	std::string getCurrentState();

	std::vector<ResponderComponent *> getChildrenForIteration();
};

#endif
