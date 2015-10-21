#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <memory>


using namespace std;

class Flyweight
{

public:
	Flyweight(const string &s) { state = s; }
	~Flyweight() {}

	string doSomething(const string &s) { return s + " " + state; }

private:
	string state;
};

class FlyweightFactory
{

public:
	FlyweightFactory() {}
	~FlyweightFactory() {}

	Flyweight & getFlyweight(const string &key)
	{
		if (!flyweightExist(key))
			flyweights[key] = unique_ptr<Flyweight>(new Flyweight(key));

		return *flyweights[key];
	}

	int getFlyweightsNumber() { return flyweights.size(); }

private:
	map<string, unique_ptr<Flyweight>> flyweights;
	bool flyweightExist(const string &key)
	{
		return flyweights.find(key) != flyweights.end();
	}

};
#endif
