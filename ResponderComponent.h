#ifndef RESPONDERCOMPONENT_H
#define RESPONDERCOMPONENT_H

#include <string>
#include "UnitState.h"
#include "Iterator.h"
#include <vector>

class ResponderComponent
{

public:
	void executeAction();

	void add(ResponderComponent *component);

	void *remove(ResponderComponent component);

	virtual std::string getName() = 0;

	void setState(UnitState *newState);

	void advanceState();

	std::string getCurrentState();

	virtual Iterator createIterator(std::string TraversalType) = 0;

	std::vector<ResponderComponent *> getChildrenForIteration();
};

#endif
