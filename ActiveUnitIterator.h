#ifndef ACTIVEUNITITERATOR_H
#define ACTIVEUNITITERATOR_H

#include "Iterator.h"
#include "ResponderComponent.h"

class ActiveUnitIterator : public Iterator
{

public:
	ActiveUnitIterator(ResponderComponent *root);

	bool hasNext();

	ResponderComponent *next();

	void collect(ResponderComponent *node);
};

#endif
