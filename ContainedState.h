#ifndef CONTAINEDSTATE_H
#define CONTAINEDSTATE_H

class ContainedState : UnitState {


public:
	void handleStateChange(ResponderComponent* context);

	string getStateName();
};

#endif
