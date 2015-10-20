#ifndef ADAPTER_H
#define ADAPTER_H

#include <string>

using namespace  std;

class Target
{
public:
	virtual ~Target() {}

	virtual string Operation() = 0;
};

class Adaptee
{
public:
	virtual ~Adaptee() {}

	string Method1()
	{
		return "Adapter";
	}
	string Method2()
	{
		return "Pattern";
	}

};

class Adapter : public Target, private Adaptee
{
public:
	string Operation() override
	{
		return Method1() + Method2();
	}
};

#endif