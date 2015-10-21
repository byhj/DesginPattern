#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Context
{
public:
	Context(const string &in) { input = in; }

	void setInput(const string &in) { input = in; }
	string getInput() { return input; }
	void setOutput(const string &out) { output = out; }
	string getOutput() { return output; }

private:
	string input;
	string output;
};

class AbstractExpression
{
public:

	virtual void interpret(Context &context)
	{
		string output = replaceString(context.getInput(), search(), replace());
		context.setInput(output);
		context.setOutput(output);
	}
	virtual string search() = 0;
	virtual string replace() = 0;

private:
	string replaceString(const string &str, const string &search, const string &replace)
	{
		string  s = str;
		size_t pos = 0;
		while ((pos = s.find(search, pos)) != string::npos)
		{
			s.replace(pos, search.length(), replace);
			pos += replace.length();
		}
		return s;
	}
};

class AExpression : public AbstractExpression
{
public:
	string search() override { return "A"; }
	string replace() override { return "AA"; }
};

class BExPression : public AbstractExpression
{
public:
	string search() override { return "B"; }
	string replace() override { return "BB"; }
};


#endif