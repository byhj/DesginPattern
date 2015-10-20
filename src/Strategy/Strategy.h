#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>

using namespace std;

class Strategy
{
public:
	virtual void execute() = 0;
};

class Strategy1 : public Strategy
{
public:
	void execute() override
	{
		cout << "Startegy1" << endl;
	}
};


class Strategy2: public Strategy
{
public:
	void execute() override
	{
		cout << "Startegy2" << endl;
	}
};

class Context
{

public:
	Context(Strategy &s):strategy(&s) {}
	void setStrategy(Strategy &s)
	{
		strategy = &s;
	}
	void executeStrategy()
	{
		strategy->execute();
	}

private:
	Strategy *strategy = nullptr;
};
#endif
