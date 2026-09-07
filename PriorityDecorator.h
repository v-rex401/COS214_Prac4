#ifndef PRIORITYDECORATOR_H
#define PRIORITYDECORATOR_H

class PriorityDecorator : ResponderDecorator {


public:
	PriorityDecorator(ResponderComponent* wrapped);

	void executeAction();
};

#endif
