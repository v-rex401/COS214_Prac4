#ifndef RESPONDERGROUP_H
#define RESPONDERGROUP_H

#include "ResponderComponent.h"

// ---------------------------------------------------------------------------
// COMPOSITE PATTERN -- Composite
//-----------------------------------------------------------
class ResponderGroup : public ResponderComponent {
public:
    explicit ResponderGroup(std::string groupName);
    ~ResponderGroup() override;

    void executeAction() override;
    std::string getName() const override;

    void add(ResponderComponent* component) override;
    void remove(ResponderComponent* component) override;

protected:
    std::vector<ResponderComponent*> getChildrenForIteration() const override;

    std::string name;
    std::vector<ResponderComponent*> children;
};

class EmergencyResponse : public ResponderGroup {
public:
    explicit EmergencyResponse(std::string groupName) : ResponderGroup(std::move(groupName)) {}
};

class Division : public ResponderGroup {
public:
    explicit Division(std::string groupName) : ResponderGroup(std::move(groupName)) {}
};

class Squad : public ResponderGroup {
public:
    explicit Squad(std::string groupName) : ResponderGroup(std::move(groupName)) {}
};

#endif // RESPONDERGROUP_H
