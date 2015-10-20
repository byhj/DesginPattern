#ifndef PROXY_H
#define PROXY_H

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Subject
{
public:
	virtual string Method() = 0;
};

class RealSubject : public Subject
{
public:
	virtual string Method() override
	{
		return "Proxy Pattern";
	}
};

class Proxy : public Subject
{

public:
	Proxy() {}
	virtual ~Proxy() {}

	virtual string Method() override
	{
		CreateSubject();
		return rs->Method();
	}

private:
	unique_ptr<RealSubject> rs;
	void CreateSubject()
	{
		if (rs == nullptr)
			rs.reset(new RealSubject);
	}
};
#endif