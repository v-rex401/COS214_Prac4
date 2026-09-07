#ifndef ENROUTESTATE_H
#define ENROUTESTATE_H

class EnRouteState : UnitState {


public:
	void handleStateChange(ResponderComponent* context);

	string getStateName();
};

#endif
