#ifndef BFSITERATOR_H
#define BFSITERATOR_H

class BFSIterator : Iterator {


public:
	BFSIterator(ResponderComponent* root);

	bool hasNext();

	ResponderComponent* next();
};

#endif
