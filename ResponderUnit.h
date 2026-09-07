#ifndef RESPONDERUNIT_H
#define RESPONDERUNIT_H

class ResponderUnit : ResponderComponent {

private:
	string name;
	UnitState currentState;

public:
	ResponderUnit(string name);

	void executeAction();

	string getName();

	void setState(UnitState* newState);

	void advanceState();

	string getCurrentState();

	vector<ResponderComponent*> getChildrenForIteration();
};

#endif
