#include "DFSIterator.h"
#include <iostream>

DFSIterator::DFSIterator(ResponderComponent *root)
{
	if (root != nullptr)
	{
		collect(root); // start the traversal
	}
}

bool DFSIterator::hasNext()
{
	if (!components.empty())
	{
		if (components[currentIndex + 1] != nullptr)
		{
			return true;
		}
	}
	return false;
}

ResponderComponent *DFSIterator::next()
{
	if (!hasNext())
	{
		std::cout << "End reached, no element here";
		return nullptr;
	}
	return components[currentIndex++]; // return the next component and increment index of traversal
}

void DFSIterator::collect(ResponderComponent *node)
{
	components.push_back(node);
	for (ResponderComponent *child : node->getChildrenForIteration())
	{
		collect(child); // recursively go through tree
	}
}
