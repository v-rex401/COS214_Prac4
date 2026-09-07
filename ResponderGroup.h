#ifndef RESPONDERGROUP_H
#define RESPONDERGROUP_H

#include <string>
#include <vector>
#include "ResponderComponent.h"

class ResponderGroup : public ResponderComponent
{

private:
	std::string name;
	std::vector<ResponderComponent *> children;

public:
	ResponderGroup(std::string name);

	void executeAction();

	void add(ResponderComponent *component);

	void remove(ResponderComponent *component);

	std::string getName();

	std::vector<ResponderComponent *> getChildrenForIteration();

	Iterator *createIterator(std::string TraversalType);
};

#endif
