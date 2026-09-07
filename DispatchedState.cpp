#include "DispatchedState.h"
#include "EnRouteState.h"

void DispatchedState::handleStateChange(ResponderComponent* context) {

	std::cout << " [State] " << context->getName() << " has left base and is now En Route.\n";

	context->setState(new EnRouteState());
}

std::string DispatchedState::getStateName() {
	return "Dispatched";
}
