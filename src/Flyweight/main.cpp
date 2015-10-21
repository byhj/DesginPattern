#include "Flyweight.h"

int main()
{
	FlyweightFactory factory;
	
	set<string> colors{ "red", "green", "blue" };
	set<string> shades{ "pale", "dark", "light" };

	for (auto &s: shades)
		for (auto &c : colors)
		{
			Flyweight &flyweight = factory.getFlyweight(c);
			cout << flyweight.doSomething(s) << endl;
		}

	cout << "getFlyweightsNumber :";
	cout << factory.getFlyweightsNumber() << endl;

	cin.get();

	return 0;
}