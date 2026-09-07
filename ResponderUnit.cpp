#include "ResponderUnit.h"

ResponderUnit::ResponderUnit(std::string name)
{
	this->name = name;
}

void ResponderUnit::executeAction()
{
	// TODO - implement ResponderUnit::executeAction
	throw "Not yet implemented";
}

std::string ResponderUnit::getName()
{
	return this->name;
}

void ResponderUnit::setState(UnitState *newState)
{
	currentState = newState;
}

void ResponderUnit::advanceState()
{
	// Set the new state
}

UnitState *ResponderUnit::getCurrentState()
{
	return currentState;
}

std::vector<ResponderComponent *> ResponderUnit::getChildrenForIteration()
{
	return nullptr;
}
