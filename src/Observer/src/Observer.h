#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <string>
#include <set>

using namespace std;

class Subject;

class Observer
{
public:
	virtual void update(Subject &subject) = 0;
};

class Subject
{
private:
	string state;
	set<Observer*> observers;

public:
	void attachObserver(Observer *obs) { observers.insert(obs); }
	void detachObserver(Observer *obs) { observers.erase(obs); }

	void notifyObservers()
	{
		for (auto &obs : observers)
			obs->update(*this);
	}

	string getState() { return state; }
	void changeState(const string &s)
	{
		state = s;
		notifyObservers();
	}
};

class ObserverImp : public Observer
{
public:
	void update(Subject &subject) override
	{
		state = subject.getState();
	}
	string getState()
	{
		return state;
	}

private:
	string state;
};
#endif
