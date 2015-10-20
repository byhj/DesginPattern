#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <iostream>

using namespace std;

class AppFramework
{
public:
	void TemplateMothod()
	{
		step1();
		step2();
	}
protected:
	virtual void step1() = 0;
	virtual void step2() = 0;
};

class App : public AppFramework
{
protected:
	void step1() override
	{
		cout << "Template Method" << endl;
	}
	
	void step2() override
	{
		cout << "Design pattern" << endl;
	}
};


#endif // _DEBUG
