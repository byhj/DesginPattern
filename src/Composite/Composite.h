#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;


class Component
{
public:
	virtual void Print() = 0;
};

class Composite : public Component
{

public:
	Composite(const string &s) : name(s) {}

	void AddElement(Component *element)
	{
		elements.push_back(element);
	}
	void RemoveElement(Component *element)
	{
		elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
	}
	Component* GetChild(int index)
	{
		return elements[index];
	}
	void Print() override
	{
		cout << name << endl;
		for (auto &e : elements)
			e->Print();
	}

private:
	string name;
	vector<Component*> elements;
};

class Leaf : public Component
{
public:
	Leaf(string s) : name(s) {}

	void Print() override
	{
		cout << name << endl;
	}

private:
	string name;
};
#endif // _DEBUG
