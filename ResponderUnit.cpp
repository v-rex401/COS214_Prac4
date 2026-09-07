#include "ResponderUnit.h"

ResponderUnit::ResponderUnit(std::string name)
{
	this->name = name;
}

void ResponderUnit::executeAction()
{
	std::cout << "This unit is doing something" << std::endl;
}

std::string ResponderUnit::getName()
{
	return this->name;
}

void ResponderUnit::setState(UnitState *newState)
{
	std::cout << "Changing state to: " << newState->getStateName() << std::endl;
	currentState = newState;
}

void ResponderUnit::advanceState()
{
	// Set the new state
	currentState->handleStateChange(this);
}

UnitState *ResponderUnit::getCurrentState()
{
	return currentState;
}

std::vector<ResponderComponent *> ResponderUnit::getChildrenForIteration()
{
	return children;
}

ResponderUnit::~ResponderUnit()
{
	if (currentState != nullptr)
		delete currentState;
}