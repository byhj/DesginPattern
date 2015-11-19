#include <string>
#include <iostream>

class Product
{
public:
	Product() = default;
	
	void AddPart(std::string part)
	{
		parts += part;
	}
    std::string GetPart()
	{
		return parts;
	}

private:
	std::string parts;
};

class Builder
{
public:
   virtual void BuilderPart() = 0;
};

class ConcreteBuilder1 :public Builder
{
public:
	void BuilderPart() override
	{
		product.AddPart("ConcreteBuilder1");
	}

	Product GetResult()
	{
		return product;
	}

private:
   Product product;
};

class ConcreteBuilder2 :public Builder
{
public:
	void BuilderPart() override
	{
		product.AddPart("ConcreteBuilder2");
	}

	Product GetResult()
	{
		return product;
	}

private:
	Product product;
};

class Director
{
public:
	Director(Builder &b): builder(b) {}
	void Construct()
	{
		builder.BuilderPart();
	}
private:
	Builder &builder;
};