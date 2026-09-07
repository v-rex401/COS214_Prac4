#include "PriorityDecorator.h"
#include <iostream>

PriorityDecorator::PriorityDecorator(ResponderComponent* wrapped) {
	this->wrapped = wrapped;
}

void PriorityDecorator::executeAction() {
	std::cout << "Priority Called. Prioritizing stuff." << std::endl;
    if (wrapped != nullptr) {
        wrapped->executeAction();
    }
}

PriorityDecorator::~PriorityDecorator() {
}