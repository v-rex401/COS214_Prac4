#ifndef RESPONDERDECORATOR_H
#define RESPONDERDECORATOR_H

class ResponderDecorator : ResponderComponent {

public:
	ResponderComponent* wrapped;

	void add(ResponderComponent* component);

	void* remove(ResponderComponent component);

	string getName();

	void setState(UnitState* newState);

	void advanceState();

	string getCurrentState();

	vector<ResponderComponent*> getChildrenForIteration();
};

#endif
