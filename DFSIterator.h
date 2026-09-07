#ifndef DFSITERATOR_H
#define DFSITERATOR_H

class DFSIterator : Iterator {


public:
	DFSIterator(ResponderComponent* root);

	bool hasNext();

	ResponderComponent* next();

private:
	void collect(ResponderComponent* node);
};

#endif
