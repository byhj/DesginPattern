#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Receiver
{
public:
	void action1(const string &s) { cout << "Receiver::action1: " << s << endl; }
	void action2(int arg) { cout << "Receiver::action2: " << arg << endl; }
};

class Command
{
public:
	virtual void execute() = 0;
};

class ConcreteCommand1 : public Command
{

public:
	ConcreteCommand1(Receiver &r, const string &a) : receiver(r), arg(a) {}
	void execute() override
	{
		receiver.action1(arg);
	}

private:
	Receiver &receiver;
	string arg;
};

class ConcreteCommand2 : public Command
{

public:
	ConcreteCommand2(Receiver &r, const int &a) : receiver(r), arg(a) {}
	void execute() override
	{
		receiver.action2(arg);
	}

private:
	Receiver &receiver;
	int arg;
};

//Macro is set of Commands but is also a Command (Composite pattern)
class Macro : public Command 
{

public:
	void addCommand(Command *c) { commands.push_back(c); };
	void execute() override
	{
		for (auto &c : commands)
			c->execute();
	}

private:
	vector<Command*> commands;

};

class Invoker
{

public:
	Invoker(Command & command) : cmd(command) {}
	void executeCommand() { cmd.execute(); }

private:
	Command &cmd;
};
#endif