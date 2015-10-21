#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Mediator
{
public:
	virtual void send(const string &id, const string &message) = 0;
};

class Colleague
{
public:
	Colleague(const string &cid) {	id = cid; }
	string getId() { return id; }
	void registerMediator(Mediator &m) { mediator = &m; }
	void receive(const string &msg)
	{
		cout << "Message received by " + id + " : " + msg << endl;
	}
	void send(const string &ids, const string &msg)
	{
		cout << id + " send message to " + ids + " : " + msg << endl;
		mediator->send(ids, msg);
	}

private:
	Mediator *mediator;
	string id;
};

class ConcreteMediator : public Mediator
{

public:
	void registerColleague(Colleague &c)
	{
		if (!isRegistered(c.getId()))
		{
			c.registerMediator(*this);
			colleagues[c.getId()] = &c;
		}
	}

	void send(const string &id, const string &message) override
	{
		if (isRegistered(id))
		{
			Colleague *c = colleagues[id];
			c->receive(message);
		}
	}

private:
	map<string, Colleague*> colleagues;
	bool isRegistered(string id)
	{
		return colleagues.find(id) != colleagues.end();
	}
};
#endif // _D
