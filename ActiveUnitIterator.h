#ifndef ACTIVEUNITITERATOR_H
#define ACTIVEUNITITERATOR_H

class ActiveUnitIterator : Iterator {


public:
	ActiveUnitIterator(ResponderComponent* root);

	bool hasNext();

	ResponderComponent* next();

	void collect(ResponderComponent* node);
};

#endif
