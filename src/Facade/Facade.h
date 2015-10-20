#ifndef FACADE_H
#define FACADE_H

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Subsystem1
{
public:
	void Method1()
	{
		cout << "Subsystem1::Method1" << endl;
	}
};

class SubsystemB
{
public:
	void MethodC()
	{
		cout << "SubsystemB::MethodC" << endl;
	}
};

class Subsystem3
{
public:
	string Method2()
	{
		return "Subsystem3::Method2";
	}
};

class Facade
{

public:
	Facade(): sub3(new Subsystem3() ) {}
	~Facade() {}

	void EasyToUseMethod1()
	{
		sub1.Method1();
		cout << sub3->Method2() << endl;
	}

	void EasyToUseMethod2()
	{
		SubsystemB subB;
		subB.MethodC();
		sub1.Method1();
	}

private:
	Subsystem1 sub1;
	unique_ptr<Subsystem3> sub3;
};
#endif