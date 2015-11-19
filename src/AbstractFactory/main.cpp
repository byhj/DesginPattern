//#include "Factory.h"
#include "Product.h"

int main()
{
	/*
	ConcreteFactory1 factory1;
	ConcreteFactory2 factory2;

	Context ctx(factory1);
	ctx.doSomething();

	ctx.setFactory(factory2);
	ctx.doSomething();
	*/
	ConcreteFactory1 factory1;
	ConcreteFactory2 factory2;

	Client client(&factory1);
	client.Create();
	client.SetFactory(&factory2);
	client.Create();

	std::cin.get();

	return 0;
}