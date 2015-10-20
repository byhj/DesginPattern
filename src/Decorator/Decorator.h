#ifndef DECORATOR_H
#define DECORATOR_H

#include <iostream>
#include <string>

using namespace std;

class Component
{
public:
	virtual void Operation() = 0;
};

class ConcreteComponent : public Component
{
	void Operation() override
	{
		cout << "Pattern";
	}
};

class Decorator : public Component
{

public:
	Decorator(Component &com):component(com){}
	
	void Operation() override
	{
		BeforeOperation();

		component.Operation();

		AfterOperation();
	}

private:
	Component &component;
	void BeforeOperation()
	{
		cout << "Decorator ";
	}
	void AfterOperation()
	{
		cout << "."  << endl;
	}

};
#endif // _DEBUG
