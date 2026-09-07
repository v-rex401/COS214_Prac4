#ifndef ONSCENESTATE_H
#define ONSCENESTATE_H

#include "UnitState.h"
#include "ResponderComponent.h"
#include <string>

class OnSceneState : public UnitState
{

public:
	void handleStateChange(ResponderComponent *context);

	std::string getStateName();
};

#endif
