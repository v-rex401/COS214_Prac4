#ifndef BIOHAZARDDECORATOR_H
#define BIOHAZARDDECORATOR_H

#include "ResponderDecorator.h"
#include "ResponderComponent.h"

class BiohazardDecorator : public ResponderDecorator
{

public:
	BiohazardDecorator(ResponderComponent *wrapped_);

	void executeAction();

	~BiohazardDecorator();
};

#endif
