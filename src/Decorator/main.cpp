#include "Decorator.h"

int main()
{
	ConcreteComponent component;
	Decorator dec(component);
	Component &comp = dec;

	//Decorator is also a component so can be also decorated
	Decorator decTemp(comp);
	dec.Operation();
	decTemp.Operation();

	cin.get();

	return 0;
}