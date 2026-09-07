#ifndef RESPONDERDECORATOR_H
#define RESPONDERDECORATOR_H

#include "ResponderComponent.h"
#include <string>
class ResponderDecorator : public ResponderComponent
{

public:
	ResponderComponent *wrapped;

	void add(ResponderComponent *component);

	void remove(ResponderComponent *component);

	std::string getName();

	void setState(UnitState *newState);

	void advanceState();

	std::string getCurrentState();

	std::vector<ResponderComponent *> getChildrenForIteration();

	Iterator *createIterator(std::string TraversalType);
};

#endif
