#ifndef RESPONDERDECORATOR_H
#define RESPONDERDECORATOR_H

#include "ResponderComponent.h"

// ---------------------------------------------------------------------------
// DECORATOR PATTERN
// Participant: ResponderDecorator = Decorator, BiohazardDecorator /
// PriorityDecorator = ConcreteDecorator
// ---------------------------------------------------------------------------
class ResponderDecorator : public ResponderComponent {
public:
    explicit ResponderDecorator(ResponderComponent* wrappedComponent);
    ~ResponderDecorator() override;

    std::string getName() const override;
    void add(ResponderComponent* component) override;
    void remove(ResponderComponent* component) override;
    void setState(UnitState* state) override;
    void advanceState() override;
    std::string getCurrentState() const override;

protected:
    std::vector<ResponderComponent*> getChildrenForIteration() const override;

    ResponderComponent* wrapped;
};

class BiohazardDecorator : public ResponderDecorator {
public:
    explicit BiohazardDecorator(ResponderComponent* wrappedComponent);
    void executeAction() override;
};

class PriorityDecorator : public ResponderDecorator {
public:
    explicit PriorityDecorator(ResponderComponent* wrappedComponent);
    void executeAction() override;
};

#endif // RESPONDERDECORATOR_H
