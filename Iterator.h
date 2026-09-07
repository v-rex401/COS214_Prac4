#ifndef ITERATOR_H
#define ITERATOR_H

class Iterator {

private:
	vector<ResponderComponent*> snapshot;
public:
	int index;

	virtual bool hasNext() = 0;

	virtual ResponderComponent* next() = 0;

	vector<ResponderComponent*> getSnapshot();
};

#endif
