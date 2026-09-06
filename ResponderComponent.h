#ifndef RESPONDERCOMPONENT_H
#define RESPONDERCOMPONENT_H

#include <string>
#include <vector>

class UnitState;
class Iterator;


// ---------------------------------------------------------------------------
// COMPOSITE PATTERN
// Participant: ResponderComponent = Component
// ---------------------------------------------------------------------------
class ResponderComponent {
public:
    virtual ~ResponderComponent() = default;

    virtual void executeAction() = 0;

    virtual void add(ResponderComponent* component);
    virtual void remove(ResponderComponent* component);

    virtual std::string getName() const = 0;

    virtual void setState(UnitState* state);
    virtual void advanceState();
    virtual std::string getCurrentState() const;

    Iterator* createIterator(std::string TraversalType) const;

protected:
    virtual std::vector<ResponderComponent*> getChildrenForIteration() const;

    friend class DFSIterator;
    friend class BFSIterator;
    friend class ActiveUnitIterator;
    friend class ResponderDecorator;
};

#endif // RESPONDERCOMPONENT_H
