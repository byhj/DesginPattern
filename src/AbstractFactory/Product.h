#include <iostream>
#include <memory>


class AbstractProductA
{
public:
	virtual void method() = 0;
};

class AbstractProductB
{
public:
	virtual void method() = 0;
};

class ProductF1A: public AbstractProductA
{
public:
	void method() override
	{
		std::cout << "ProductF1A" << std::endl;
	}
};

class ProductF1B : public AbstractProductB
{
public:
	void method() override
	{
		std::cout << "ProductF1B" << std::endl;
	}
};


class ProductF2A : public AbstractProductA
{
public:
	void method() override
	{
		std::cout << "ProductF2A" << std::endl;
	}
};

class ProductF2B : public AbstractProductB
{
public:
	void method() override
	{
		std::cout << "ProductF2B" << std::endl;
	}
};

class AbstractFactory
{
public:
	virtual std::unique_ptr<AbstractProductA> CreateProductA() = 0;
	virtual std::unique_ptr<AbstractProductB> CreateProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory
{
public:
	std::unique_ptr<AbstractProductA> CreateProductA() override
	{
		std::unique_ptr<AbstractProductA> ptr(nullptr);
		ptr.reset(new ProductF1A);

		return ptr;

	}
	std::unique_ptr<AbstractProductB> CreateProductB() override
	{
		std::unique_ptr<AbstractProductB> ptr(nullptr);
		ptr.reset(new ProductF1B);

		return ptr;
	}

};

class ConcreteFactory2 : public AbstractFactory
{
public:
	std::unique_ptr<AbstractProductA> CreateProductA() override
	{
		std::unique_ptr<AbstractProductA> ptr(nullptr);
		ptr.reset(new ProductF2A);

		return ptr;

	}
	std::unique_ptr<AbstractProductB> CreateProductB() override
	{
		std::unique_ptr<AbstractProductB> ptr(nullptr);
		ptr.reset(new ProductF2B);

		return ptr;
	}
};

class Client
{
public:
	Client(AbstractFactory *fac) :factory(fac) {} 

	void SetFactory(AbstractFactory *fac)
	{
		factory = fac;
	}

	void Create()
	{
		auto productA = factory->CreateProductA();
		productA->method();

	    auto productB = factory->CreateProductB();
		productB->method();
	}
private:
	AbstractFactory *factory = nullptr;
};