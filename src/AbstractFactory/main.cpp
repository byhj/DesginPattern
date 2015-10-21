#include "Factory.h"

int main()
{
	ConcreteFactory1 factory1;
	ConcreteFactory2 factory2;

	Context ctx(factory1);
	ctx.doSomething();

	ctx.setFactory(factory2);
	ctx.doSomething();

	cin.get();

	return 0;
}