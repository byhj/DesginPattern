#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <memory>
#include <iostream>
#include <string>

using namespace std;

class Prototype
{
public:
	virtual ~Prototype() {}

	virtual unique_ptr<Prototype> clone() = 0;
};

class ConcretePortotype1 : public Prototype
{
public:
	~ConcretePortotype1() {}
	ConcretePortotype1(const ConcretePortotype1 &t) {*this = t;}
	ConcretePortotype1(const string &s): name(s) {}
	ConcretePortotype1 & operator = (const ConcretePortotype1 &t)
	{
		name = t.name;	 
		return *this;
	}

public:
	void SetName(const string &s) { name = s; }
	string GetName() { return name; }

	unique_ptr<Prototype> clone() override
	{
		unique_ptr<Prototype> temp{ new ConcretePortotype1(*this) };
		return temp;
	}
private:
	string name;

};


class ConcretePortotype2 : public Prototype
{

public:
	~ConcretePortotype2() {}
	ConcretePortotype2(int v) :value(v) {}

	void SetValue(int v) { value = v; }
	int GetValue() { return value; }
	unique_ptr<Prototype> clone() override
	{
		unique_ptr<Prototype> temp{ new ConcretePortotype2(*this) };
		return temp;
	}
private:
	int value;
};

#endif // _DE
