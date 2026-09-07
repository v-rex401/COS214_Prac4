#ifndef RESPONDERUNIT_H
#define RESPONDERUNIT_H

#include "ResponderComponent.h"
#include "UnitState.h"
#include <string>
#include <vector>

class ResponderUnit : public ResponderComponent
{

private:
	std::string name;
	UnitState *currentState;
	std::vector<ResponderComponent *> children;

public:
	ResponderUnit(std::string name);

	void executeAction();

	std::string getName();

	void setState(UnitState *newState);

	void advanceState();

	std::string getCurrentState();

	std::vector<ResponderComponent *> getChildrenForIteration();

	Iterator *createIterator(std::string TraversalType);

	~ResponderUnit();
};

#endif
