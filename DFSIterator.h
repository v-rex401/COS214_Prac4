#ifndef DFSITERATOR_H
#define DFSITERATOR_H

#include "Iterator.h"
#include "ResponderComponent.h"

class DFSIterator : public Iterator
{

public:
	DFSIterator(ResponderComponent *root);

	bool hasNext();

	ResponderComponent *next();

private:
	void collect(ResponderComponent *node);
};

#endif
