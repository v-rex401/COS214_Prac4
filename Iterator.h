#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>
#include <string>
#include "ResponderComponent.h"

class Iterator
{

public:
	virtual bool hasNext() = 0;

	virtual ResponderComponent *next() = 0;

	virtual std::vector<ResponderComponent *> getSnapshot();
};

#endif
