#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class State
{
public:
	virtual void handle() = 0;
	virtual ~State() {}
};

class ConcreteState1 : public State
{
public:
	void handle() override
	{
		cout << "ConcreteState1" << endl;
	}
};

class ConcreteState2 : public State
{
public:
	void handle() override
	{
		cout << "ConcreteState2" << endl;
	}
};


class Context
{
public:
	Context() : state{ new ConcreteState1 } {}
	~Context() {}

	void request() { return state->handle(); }
	void changeStateOperation()
	{
		state.reset(new ConcreteState2);

	}

private:
	unique_ptr<State> state;

};
#endif // _D
