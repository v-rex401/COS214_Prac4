#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>
#include <string>
#include "ResponderComponent.h"

class Iterator
{

private:
	std::vector<ResponderComponent *> snapshot;

public:
	int index;

	virtual bool hasNext() = 0;

	virtual ResponderComponent *next() = 0;

	std::vector<ResponderComponent *> getSnapshot();
};

#endif
