#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

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



#endif // PRODUCT
