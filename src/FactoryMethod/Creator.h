#ifndef CREATOR_H
#define CREATOR_H

#include <memory>
#include <iostream>
#include <string>

enum class ProductType
{
	PRODUCT1,
	PRODUCT2,
};

class Product
{
public:
	virtual ~Product() {}
	virtual std::string method() = 0;
};

class Product1 : public Product
{

public:

	~Product1() {}

	std::string method() override { return "Product1::method"; }
};

class Product2 : public Product
{
public:
	~Product2() {}
	std::string method() override { return "Product2::method"; }
};


class Creator
{
public:
	virtual ~Creator(){}

	void AnOperation()
	{
		ProductType products[] ={ ProductType::PRODUCT1, ProductType::PRODUCT2 };
		for (auto type : products)
		{
			auto p = FactoryMethod(type);
			std::cout << p->method() << std::endl;
		}
	}

protected:

	virtual unique_ptr<Product> FactoryMethod(ProductType type) = 0;

};


class ConcreteCreator : public Creator
{
public:
	~ConcreteCreator(){}

protected:
	unique_ptr<Product> FactoryMethod(ProductType type) override
	{
		unique_ptr<Product> ret(nullptr);

		switch (type)
		{
		case ProductType::PRODUCT1 : ret.reset(new Product1);
			break;
		case ProductType::PRODUCT2 : ret.reset(new Product2);
			break;
		default:
			break;
		}
		return ret;

	}
};
#endif // 
