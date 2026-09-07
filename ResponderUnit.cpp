#include "ResponderUnit.h"
#include "DFSIterator.h"
#include "ActiveUnitIterator.h"

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
	return name;
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

std::string ResponderUnit::getCurrentState()
{
	return currentState->getStateName();
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

Iterator *ResponderUnit::createIterator(std::string TraversalType)
{
	if (TraversalType == "DFS")
	{
		return new DFSIterator(this);
	}
	else if (TraversalType == "Active")
	{
		return new ActiveUnitIterator(this);
	}
	return nullptr;
}