#include "OnSceneState.h"
#include "ContainedState.h"

void OnSceneState::handleStateChange(ResponderComponent* context) {

    std::cout << " [State] " << context->getName() << " has finished working the scene. The incident is now Contained.\n";
    
	context->setState(new ContainedState());
}

std::string OnSceneState::getStateName() {
	return "On Scene";
}
