#include "ResponderComponent.h"
#include "ResponderGroup.h"
#include "ResponderUnit.h"
#include "ResponderDecorator.h"
#include "PriorityDecorator.h"
#include "BiohazardDecorator.h"
#include "Iterator.h"
#include "UnitState.h"
#include "EmergencyResponse.h"
#include "Division.h"
#include "Squad.h"
#include "DispatchedState.h"
#include "OnSceneState.h"
#include "EnRouteState.h"

void iterateDFS(ResponderComponent *, std::string);
void iterateActive(ResponderComponent *, std::string);
void scenario1();
void scenario2();

int main()
{
    std::cout << "----- SCENARIO 1 -----\n ";
    scenario1();
    std::cout << "\n----- SCENARIO 2 -----\n ";
    scenario2();
    return 0;
}

void scenario1()
{
    //* Hazmat Incident
    std::cout << "----- Hazmat Incident -----\n";
    std::cout << "Set Inital States \n";
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
    fireSquad2->add(engine1);

    //* Build the FIRE DIVISION
    Division *fireDivision = new Division("Fire Division");
    fireDivision->add(fireSquad1);
    fireDivision->add(fireSquad2);

    //* INCIDENT
    EmergencyResponse *incident = new EmergencyResponse("Citywide Emergency");
    incident->add(hazmatDivision);
    incident->add(fireDivision);

    std::cout << std::endl;
    // Traversals
    iterateDFS(incident, "Initial incident sweep");
    std::cout << std::endl;
    iterateActive(incident, "Initial incident sweep");

    engine21->advanceState(); // Dispatched -> EnRoute (valid)
    engine21->advanceState(); // EnRoute -> OnScene (valid)
    engine21->advanceState(); // OnScene -> Contained (valid)
    engine21->advanceState(); // handleStateChange prints an "Invalid State Change" message and does NOT transition further

    // RUNTIME STRUCTURAL CHANGES: MOVE CHIEF OUT OF HAZMAT
    std::cout << "\n---- Runtime change: reassigning Chief Unit -----\n";
    hazmatDivision->remove(chiefUnit);
    iterateActive(incident, "Active units after removing chief");

    fireDivision->add(chiefUnit);

    /* Any DFSIterator built BEFORE this point will NOT reflect this move.
       Our  traversal-modification policy:  iterators must request a fresh iterator
       to see structural changes made after traversal has begun. */
    iterateDFS(incident, "Incident sweep after reassignment of chief ");

    std::cout << std::endl;

    iterateActive(incident, "Active units after reassignment of chief ");

    delete incident;
}

void scenario2()
{
    ResponderUnit *engine9 = new ResponderUnit("Engine 9");
    engine9->setState(new DispatchedState());
    ResponderUnit *rescue3 = new ResponderUnit("Rescue 3");
    rescue3->setState(new DispatchedState());

    Squad *strikeTeam = new Squad("Strike Team Bravo");
    strikeTeam->add(engine9);
    strikeTeam->add(rescue3);

    // Decorator
    ResponderComponent *urgentStrikeTeam = new PriorityDecorator(strikeTeam);
    Division *escalationDivision = new Division("Escalation Division");
    escalationDivision->add(urgentStrikeTeam);

    EmergencyResponse *incident = new EmergencyResponse("Highway Pileup");
    incident->add(escalationDivision);

    //*TWO ITERATORS - INDEPENDENT RUNS
    iterateDFS(incident, "Sweep A ");
    std::cout << "\n";
    iterateActive(incident, "Sweep B");

    std::cout << "\n----- Runtime change: hazardous spill reported -----\n";
    strikeTeam->remove(engine9);
    ResponderComponent *contaminatedEngine9 = new BiohazardDecorator(engine9);
    strikeTeam->add(contaminatedEngine9);
    contaminatedEngine9->advanceState();

    iterateDFS(incident, "Escalation sweep after contamination flagged");

    delete incident;
}

//* HELPER FUNCTONS FOR DEMO ---> SHOWS HOW TREE INNER WORKINGS IS NOT EXPOSED IN CLIENT CODE
void iterateDFS(ResponderComponent *root, std::string label)
{
    std::cout << label << " (DFS Traversal)\n";
    Iterator *iter = root->createIterator("DFS");
    while (iter->hasNext())
    {
        iter->next()->executeAction();
    }
    delete iter;
}

void iterateActive(ResponderComponent *root, std::string label)
{
    std::cout << label << " (Acitve Unit Traversal)\n";
    Iterator *iter = root->createIterator("Active");
    while (iter->hasNext())
    {
        std::cout << " Active: " << iter->next()->getName() << std::endl;
    }
    delete iter;
}