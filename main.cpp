#include "ResponderComponent.h"
#include "ResponderGroup.h"
#include "ResponderUnit.h"
#include "ResponderDecorator.h"
#include "Iterator.h"
#include "UnitState.h"
#include "EmergencyResponse.h"
#include "Division.h"
#include "Squad.h"
#include "DispatchedState.h"
#include "OnSceneState.h"
#include "EnRouteState.h"

int main()
{
    // Create Composite Units and Groups

    // Build from the leaves going up
    ResponderUnit *medic4 = new ResponderUnit("Medic 4");
    medic4->setState(new DispatchedState());

    // TODO Add wrappers for decorator to medic4

    ResponderUnit *tanker67 = new ResponderUnit("Tanker 67");
    medic4->setState(new EnRouteState());

    //* Build a squad component (composite) - Hazmat Alpha
    Squad *hazmatSquadAlpha = new Squad("Hazmat Squad Alpha");
    // Add the children leaves
    hazmatSquadAlpha->add(tanker67);
    hazmatSquadAlpha->add(medic4);

    ResponderUnit *chiefUnit = new ResponderUnit("Chief Unit");
    chiefUnit->setState(new DispatchedState());

    Division *hazmatDivision = new Division("Hazmat Division");
    // add children
    hazmatDivision->add(hazmatSquadAlpha);
    hazmatDivision->add(chiefUnit);

    //* BUILD FIRE SQUAD
    ResponderUnit *engine21 = new ResponderUnit("Engine 21");
    engine21->setState(new OnSceneState());
    ResponderUnit *ladderTruck42 = new ResponderUnit("Ladder Truck 42");
    ladderTruck42->setState(new DispatchedState());

    Squad *fireSquad1 = new Squad("Fire Squad 1");
    fireSquad1->add(engine21);
    fireSquad1->add(ladderTruck42);

    //* Build FIRE SQUAD 2
    ResponderUnit *engine1 = new ResponderUnit("Engine 1");
    engine1->setState(new DispatchedState());
    Squad *fireSquad2 = new Squad("Fire Squad 2");

    //* Build the FIRE DIVISION
    Division *fireDivision = new Division("Fire Division");
    fireDivision->add(fireSquad1);
    fireDivision->add(fireSquad2);

    //* INCIDENT
    EmergencyResponse *incident = new EmergencyResponse("Citywide Emergency");
    incident->add(hazmatDivision);
    incident->add(fireDivision);

    // Iterate Through using DFS
    Iterator *iterator = incident->createIterator("DFS");
    while (iterator->hasNext())
    {
        iterator->next()->executeAction();
    }

    // Iterate through to see activeunits

    // Show hierarchy clearly

    delete iterator;
    delete incident;
}