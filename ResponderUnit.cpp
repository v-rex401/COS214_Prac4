#include "ResponderUnit.h"
#include "DFSIterator.h"
#include "ActiveUnitIterator.h"

ResponderUnit::ResponderUnit(std::string name)
{
	this->name = name;
	currentState = nullptr;
}

void ResponderUnit::executeAction()
{
	std::cout << "[LEAF] " << name << " is active. Current state: " << getCurrentState() << std::endl;
}

std::string ResponderUnit::getName()
{
	return name;
}

void ResponderUnit::setState(UnitState *newState)
{
	if (currentState != nullptr)
	{
		delete currentState; // Prevent memory leak of old state
	}
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
	if (currentState != nullptr)
	{
		return currentState->getStateName();
	}
	return "No State Assigned";
}

std::vector<ResponderComponent *> ResponderUnit::getChildrenForIteration()
{
	return children;
}

ResponderUnit::~ResponderUnit()
{
	if (currentState != nullptr)
		delete currentState;
	currentState = nullptr;
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