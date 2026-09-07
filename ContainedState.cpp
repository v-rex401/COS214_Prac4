#include "ContainedState.h"

void ContainedState::handleStateChange(ResponderComponent* context) {
	
	    std::cout << " [State] Invalid State Change: " << context->getName() << " is already Contained.\n";
}

std::string ContainedState::getStateName() {
	return "Contained";
}
