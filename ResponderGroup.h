#ifndef RESPONDERGROUP_H
#define RESPONDERGROUP_H

class ResponderGroup : ResponderComponent {

private:
	string name;
	std::vector<vector<ResponderComponent*>> children;

public:
	ResponderGroup(string name);

	void executeAction();

	void add(ResponderComponent* component);

	void* remove(ResponderComponent component);

	string getName();

	vector<ResponderComponent*> getChildrenForIteration();
};

#endif
