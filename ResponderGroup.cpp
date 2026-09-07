#include "ResponderGroup.h"
#include <string>
#include "DFSIterator.h"
#include "ActiveUnitIterator.h"
using namespace std;

ResponderGroup::ResponderGroup(std::string name) : name(name) {}

void ResponderGroup::executeAction()
{
	for (int i = 0; i < children.size(); i++)
	{
		if (children[i] != nullptr)
		{
			children[i]->executeAction();
		}
	}
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
