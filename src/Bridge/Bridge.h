#ifndef BRIDGET_H
#define BRIDGET_H

#include <iostream>

using namespace std;

class Implementor
{
public:
	virtual void Implementation() = 0;
};

class ConcreteImplementorA : public  Implementor
{
public:
	void Implementation() override
	{
		cout << "ConcreteImplementorA::operation" << endl;
	}
};

class ConcreteImplementorB : public Implementor
{

public:

    void Implementation() override
    {
		cout << "ConcreteImplementorB::operation" << endl;
    }

};

class Abstraction
{
protected:
	Implementor &implementor;
public:
	Abstraction(Implementor & imp): implementor(imp) {}

	virtual void operation()
	{
		implementor.Implementation();
	}

};

class RefindedAbstraction : public Abstraction
{
public:
	RefindedAbstraction(Implementor &imp):Abstraction(imp) {}
	void operation() override
	{
		implementor.Implementation();
	}

};

#endif