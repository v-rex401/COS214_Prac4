#ifndef RESPONDERCOMPONENT_H
#define RESPONDERCOMPONENT_H

class ResponderComponent {


public:
	void executeAction();

	void add(ResponderComponent* component);

	void* remove(ResponderComponent component);

	virtual string getName() = 0;

	void setState(UnitState* newState);

	void advanceState();

	string getCurrentState();

	virtual Iterator createIterator(string TraversalType) = 0;

	vector<ResponderComponent*> getChildrenForIteration();
};

#endif
