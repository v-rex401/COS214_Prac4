#ifndef PRIORITYDECORATOR_H
#define PRIORITYDECORATOR_H

#include "ResponderDecorator.h"
#include "ResponderComponent.h"
class PriorityDecorator : public ResponderDecorator
{

public:
	PriorityDecorator(ResponderComponent *wrapped);

	void executeAction();
	~PriorityDecorator();
};

#endif
