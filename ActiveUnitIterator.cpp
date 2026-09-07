#include "ActiveUnitIterator.h"

ActiveUnitIterator::ActiveUnitIterator(ResponderComponent *root)
{
	if (root != nullptr)
	{
		collect(root);
	}
}

bool ActiveUnitIterator::hasNext()
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

ResponderComponent *ActiveUnitIterator::next()
{
	if (!hasNext())
	{
		std::cout << "End reached, no element here";
		return nullptr;
	}
	return components[currentIndex++]; // return the next component and increment index of traversal
}

void ActiveUnitIterator::collect(ResponderComponent *node)
{
	std::vector<ResponderComponent *> children = node->getChildrenForIteration();

	if (children.empty())
	{
		// If its empty we have a leaf of the tree ResponderUnit
		if (node->getCurrentState() != "Contained")
		{
			components.push_back(node);
		}
		return;
	}
	for (ResponderComponent *child : children)
	{
		collect(child);
	}
}
