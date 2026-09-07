TARGET = taskforge

# ResponderComponent, Iterator and UnitState have no matching .cpp -
# they're abstract/header-only, so there's no .o to build for them.
OBJS = main.o \
ActiveUnitIterator.o BiohazardDecorator.o ContainedState.o DFSIterator.o \
DispatchedState.o Division.o EmergencyResponse.o EnRouteState.o \
OnSceneState.o PriorityDecorator.o ResponderDecorator.o ResponderGroup.o \
ResponderUnit.o Squad.o

$(TARGET): $(OBJS)
	g++ -std=c++11 -g -o $(TARGET) $(OBJS)

main.o: main.cpp
	g++ -std=c++11 -g -c main.cpp

ActiveUnitIterator.o: ActiveUnitIterator.cpp
	g++ -std=c++11 -g -c ActiveUnitIterator.cpp

BiohazardDecorator.o: BiohazardDecorator.cpp
	g++ -std=c++11 -g -c BiohazardDecorator.cpp

ContainedState.o: ContainedState.cpp
	g++ -std=c++11 -g -c ContainedState.cpp

DFSIterator.o: DFSIterator.cpp
	g++ -std=c++11 -g -c DFSIterator.cpp

DispatchedState.o: DispatchedState.cpp
	g++ -std=c++11 -g -c DispatchedState.cpp

Division.o: Division.cpp
	g++ -std=c++11 -g -c Division.cpp

EmergencyResponse.o: EmergencyResponse.cpp
	g++ -std=c++11 -g -c EmergencyResponse.cpp

EnRouteState.o: EnRouteState.cpp
	g++ -std=c++11 -g -c EnRouteState.cpp

OnSceneState.o: OnSceneState.cpp
	g++ -std=c++11 -g -c OnSceneState.cpp

PriorityDecorator.o: PriorityDecorator.cpp
	g++ -std=c++11 -g -c PriorityDecorator.cpp

ResponderDecorator.o: ResponderDecorator.cpp
	g++ -std=c++11 -g -c ResponderDecorator.cpp

ResponderGroup.o: ResponderGroup.cpp
	g++ -std=c++11 -g -c ResponderGroup.cpp

ResponderUnit.o: ResponderUnit.cpp
	g++ -std=c++11 -g -c ResponderUnit.cpp

Squad.o: Squad.cpp
	g++ -std=c++11 -g -c Squad.cpp

clean:
	rm -f *.o $(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

run: $(TARGET)
	./$(TARGET)