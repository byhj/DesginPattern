#ifndef BUILDER_H
#define BUILDER_H

#include <iostream>
#include <string>

using namespace std;

class Product
{
public:
	Product() {}
	~Product() {}

	void AddPart(string part)
	{
		parts += part + "\n";
	}
	string GetPart()
	{
		return parts;
	}

private:
	string parts;
};

class Builder
{
public:
	virtual void BuildPart1() = 0;
	virtual void BuildPart2() = 0;
};

class ConcreteBuilder1 : public Builder
{
public:
	void BuildPart1() override
	{
		product.AddPart("Builder");
	}
	void BuildPart2() override
	{
		product.AddPart("Pattern");
	}

	Product & GetProduct()
	{
		return product;
	}

private:
	Product product;
};

class ConcreteBuilder2 : public Builder
{
public:
	void BuildPart1() override
	{
		product.AddPart("Pattern");
	}
	void BuildPart2() override
	{
		product.AddPart("Builder");
	}
	Product & GetProduct()
	{
		return product;
	}

private:
	Product product;
};

class Director
{
public:
	Director(Builder &b):builder(b) {}

	void Construct()
	{
		builder.BuildPart1();
		builder.BuildPart2();
	}

private:
	Builder &builder;
};

#endif
