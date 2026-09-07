#ifndef ONSCENESTATE_H
#define ONSCENESTATE_H

class OnSceneState : UnitState {


public:
	void handleStateChange(ResponderComponent* context);

	string getStateName();
};

#endif
