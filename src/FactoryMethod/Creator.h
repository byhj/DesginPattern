#ifndef CREATOR_H
#define CREATOR_H

#include "Product.h"
#include <memory>
#include <iostream>

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
			cout << p->method() << endl;
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
