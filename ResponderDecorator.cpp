#include "ResponderDecorator.h"
#include <string>
using namespace std;

void ResponderDecorator::add(ResponderComponent *component)
{
    if (wrapped)
    {
        wrapped->add(component);
    }
}

void ResponderDecorator::remove(ResponderComponent *component)
{
    if (wrapped != nullptr)
    {
        wrapped->remove(component);
    }
}

string ResponderDecorator::getName()
{
    if (wrapped != nullptr)
    {
        return wrapped->getName();
    }
    return "";
}

void ResponderDecorator::setState(UnitState *newState)
{
    if (wrapped != nullptr)
    {
        wrapped->setState(newState);
    }
}

void ResponderDecorator::advanceState()
{
    if (wrapped != nullptr)
    {
        wrapped->advanceState();
    }
}

std::string ResponderDecorator::getCurrentState()
{
    if (wrapped != nullptr)
    {
        return wrapped->getCurrentState();
    }
    return "";
}

vector<ResponderComponent *> ResponderDecorator::getChildrenForIteration()
{
    if (wrapped != nullptr)
    {
        return wrapped->getChildrenForIteration();
    }
    return std::vector<ResponderComponent *>();
}

Iterator *ResponderDecorator::createIterator(std::string TraversalType)
{
    if (wrapped != nullptr)
    {
        return wrapped->createIterator(TraversalType);
    }
    return nullptr;
}

ResponderDecorator::~ResponderDecorator()
{
    if (wrapped != nullptr)
    {
        delete wrapped;
        wrapped = nullptr;
    }
}