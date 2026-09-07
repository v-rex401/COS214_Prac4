#ifndef UNITSTATE_H
#define UNITSTATE_H

class UnitState {


public:
	virtual void handleStateChange(ResponderComponent* context) = 0;

	virtual string getStateName() = 0;
};

#endif
