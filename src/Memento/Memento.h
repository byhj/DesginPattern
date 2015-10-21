#ifndef MEMENTO_H
#define MEMENTO_H

#include <iostream>
#include <string>

using namespace std;

//Memento: It holds the internal state of an Originator
class Memento
{
public:
	Memento(const string &s): state(s) {}
	string getState() const { return state; }
	void setState(const string &s) { state = s; }

private:
	string state;
};

//Originator: It is the one whose state needs to be saved

class Originator
{

public:
	Originator() {}
	Memento createMemento() { Memento m(state); return m; }
	void setMemento(const Memento &m) { state = m.getState();}

private:
	string state;
};

#endif // !MEMENTO_H
