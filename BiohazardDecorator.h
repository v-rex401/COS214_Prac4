#ifndef BIOHAZARDDECORATOR_H
#define BIOHAZARDDECORATOR_H

class BiohazardDecorator : ResponderDecorator {


public:
	BiohazardDecorator(ResponderComponent* wrapped_);

	void executeAction();
};

#endif
