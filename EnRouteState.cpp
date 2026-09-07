#include "EnRouteState.h"
#include "OnSceneState.h"

void EnRouteState::handleStateChange(ResponderComponent* context) {

	std::cout << " [State] " << context->getName() << " has arrived and is now On Scene.\n";

    context->setState(new OnSceneState());
}

std::string EnRouteState::getStateName() {
	return "En Route";
}
