#ifndef EMERGENCYRESPONSE_H
#define EMERGENCYRESPONSE_H

#include <string>
#include "ResponderGroup.h"

class EmergencyResponse : public ResponderGroup
{

public:
	EmergencyResponse(std::string name);
};

#endif
