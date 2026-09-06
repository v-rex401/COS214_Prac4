#ifndef RESPONDERUNIT_H
#define RESPONDERUNIT_H

#include "ResponderComponent.h"

// ---------------------------------------------------------------------------
// COMPOSITE PATTERN -- Leaf
// STATE PATTERN -- Context
// ---------------------------------------------------------------------------
class ResponderUnit : public ResponderComponent {
public:
    explicit ResponderUnit(std::string unitName);
    ~ResponderUnit() override;

    void executeAction() override;
    std::string getName() const override;

    void setState(UnitState* state) override;
    void advanceState() override;
    std::string getCurrentState() const override;

protected:
    std::vector<ResponderComponent*> getChildrenForIteration() const override;

private:
    std::string name;
    UnitState* currentState;
};

#endif // RESPONDERUNIT_H
