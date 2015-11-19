#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <memory>

using namespace std;

enum class ProductType
{
	PRODUCT1,
    PRODUCT2,
};

class Product
{
public:
	virtual ~Product() {}
	virtual string method() = 0;
};

class Product1 : public Product
{

public:

	~Product1(){}

	string method() override  {return "Product1::method";}
};

class Product2 : public Product
{
public:
	~Product2(){}
	string method() override { return "Product2::method";}
};

class Creator
{
public:
	void AnOperation()
	{
		ProductType products[] = { ProductType::PRODUCT1, ProductType::PRODUCT2 };
		for (auto type : products)
		{
			auto p = FactoryMethod(type);
			std::cout << p->method() << std::endl;
		}
	}

	virtual std::unique_ptr<Product> FactoryMethod(ProductType type) = 0;
};

class ConcreteCreator : public Creator
{
public:
	std::unique_ptr<Product> FactoryMethod(ProductType type) override
	{
		unique_ptr<Product> ret(nullptr);

		switch (type)
		{
		case ProductType::PRODUCT1: ret.reset(new Product1);
			break;
		case ProductType::PRODUCT2: ret.reset(new Product2);
			break;
		default:
			break;
		}
		return ret;
	}
};


#endif // PRODUCT
