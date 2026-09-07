#ifndef BFSITERATOR_H
#define BFSITERATOR_H

#include "Iterator.h"
#include "ResponderComponent.h"

class BFSIterator : public Iterator
{

public:
	BFSIterator(ResponderComponent *root);

	bool hasNext();

	ResponderComponent *next();
};

#endif
