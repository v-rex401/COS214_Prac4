#ifndef UNITSTATE_H
#define UNITSTATE_H

#include <string>

class ResponderComponent; // forward declaration

// ---------------------------------------------------------------------------
// STATE PATTERN
// Participant: UnitState = State, ResponderUnit = Context
// ---------------------------------------------------------------------------
class UnitState {
public:
    virtual ~UnitState() = default;

    virtual void handleAction(ResponderComponent* context) = 0;

    virtual std::string getStateName() const = 0;
};

class DispatchedState : public UnitState {
public:
    void handleAction(ResponderComponent* context) override;
    std::string getStateName() const override { return "Dispatched"; }
};

class EnRouteState : public UnitState {
public:
    void handleAction(ResponderComponent* context) override;
    std::string getStateName() const override { return "En Route"; }
};

class OnSceneState : public UnitState {
public:
    void handleAction(ResponderComponent* context) override;
    std::string getStateName() const override { return "On Scene"; }
};

class ContainedState : public UnitState {
public:
    void handleAction(ResponderComponent* context) override;
    std::string getStateName() const override { return "Contained"; }
};

#endif // UNITSTATE_H
