#ifndef RESPONDERCOMPONENT_H
#define RESPONDERCOMPONENT_H

#include <string>
#include "UnitState.h"
#include "Iterator.h"
#include <vector>

class UnitState; // forward declaration - only used as a pointer/return type below
class Iterator;	 // forward declaration - only used as a return type below

class ResponderComponent
{

public:
	virtual void executeAction() = 0;

	virtual void add(ResponderComponent *component) {};

	virtual void remove(ResponderComponent *component) {};

	virtual std::string getName() = 0;

	virtual void setState(UnitState *newState) = 0;

	virtual void advanceState() = 0;

	virtual std::string getCurrentState() = 0;

	virtual Iterator *createIterator(std::string TraversalType) = 0;

	virtual std::vector<ResponderComponent *> getChildrenForIteration() = 0;
	virtual ~ResponderComponent() {};
};

#endif
