#include "ResponderGroup.h"
#include <string>
#include "DFSIterator.h"
#include "ActiveUnitIterator.h"
using namespace std;

ResponderGroup::ResponderGroup(std::string name) : name(name) {}

void ResponderGroup::executeAction()
{
	std::cout << "\n--> Entering " << name << " " << std::endl;

	/**Removed the following code because it was iterating twice
	 * - With it gone only iterator design pattern will handle the traversal
	 * - It was causing the leaves to execute too many times  */

	/* for (int i = 0; i < children.size(); i++)
	{
		if (children[i] != nullptr)
		{
			children[i]->executeAction();
		}
	}
	std::cout << std::endl; */
}

void ResponderGroup::add(ResponderComponent *component)
{
	if (component != nullptr)
	{
		children.push_back(component);
	}
}

void ResponderGroup::remove(ResponderComponent *component)
{
	if (component == nullptr)
	{
		return;
	}

	for (int i = 0; i < children.size(); i++)
	{
		if (children[i] == component || children[i]->getName() == component->getName())
		{
			children.erase(children.begin() + i);
			break;
		}
	}
}

string ResponderGroup::getName()
{
	return name;
}

vector<ResponderComponent *> ResponderGroup::getChildrenForIteration()
{
	return children;
}

Iterator *ResponderGroup::createIterator(std::string TraversalType)
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

ResponderGroup::~ResponderGroup()
{
	for (int i = 0; i < children.size(); i++)
	{
		if (children[i] != nullptr)
		{
			delete children[i];
			children[i] = nullptr;
		}
	}
	children.clear();
}

void ResponderGroup::setState(UnitState *newState)
{
	// got through children and call
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->setState(newState);
	}
}

void ResponderGroup::advanceState()
{
	// got through children and call
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->advanceState();
	}
}
std::string ResponderGroup::getCurrentState()
{
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->getCurrentState();
	}
	return "End of: " + name;
}