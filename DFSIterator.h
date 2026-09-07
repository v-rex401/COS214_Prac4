#ifndef DFSITERATOR_H
#define DFSITERATOR_H

#include "Iterator.h"
#include "ResponderComponent.h"

class DFSIterator : public Iterator
{

public:
	DFSIterator(ResponderComponent *root);
	virtual ~DFSIterator();
	bool hasNext();

	ResponderComponent *next();

private:
	int currentIndex;
	std::vector<ResponderComponent *> components;
	void collect(ResponderComponent *node);
};

#endif
