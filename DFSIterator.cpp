#include "DFSIterator.h"
#include <iostream>

DFSIterator::DFSIterator(ResponderComponent *root)
{
	currentIndex = 0;
	if (root != nullptr)
	{
		collect(root); // start the traversal
	}
}

bool DFSIterator::hasNext()
{
	return currentIndex < components.size();
}
DFSIterator::~DFSIterator()
{
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
	if (node == nullptr){
		return;
	}
	components.push_back(node);
	for (ResponderComponent *child : node->getChildrenForIteration())
	{
		collect(child); // recursively go through tree
	}
}
