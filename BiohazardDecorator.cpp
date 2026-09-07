#include "BiohazardDecorator.h"
#include <iostream>

BiohazardDecorator::BiohazardDecorator(ResponderComponent* wrapped_) {
	wrapped = wrapped_;
}

void BiohazardDecorator::executeAction() {
	std::cout << "Biohazard Called. Doing biohazard stuff." << std::endl;
    if (wrapped != nullptr) {
        wrapped->executeAction();
    }
}

BiohazardDecorator::~BiohazardDecorator() {
}