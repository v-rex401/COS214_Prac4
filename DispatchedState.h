#ifndef DISPATCHEDSTATE_H
#define DISPATCHEDSTATE_H

class DispatchedState : UnitState {


public:
	void handleStateChange(ResponderComponent* context);

	string getStateName();
};

#endif
