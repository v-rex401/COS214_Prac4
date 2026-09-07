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

	virtual void add(ResponderComponent *component);

	virtual void remove(ResponderComponent *component);

	virtual std::string getName() = 0;

	virtual void setState(UnitState *newState);

	virtual void advanceState();

	virtual std::string getCurrentState();

	virtual Iterator createIterator(std::string TraversalType) = 0;

	virtual std::vector<ResponderComponent *> getChildrenForIteration();
};

#endif
