#include "Builder.h"
#include <iostream>

using namespace std;

int main()
{
	ConcreteBuilder1 builder1;
	ConcreteBuilder2 builder2;

	Director director1(builder1);
	Director director2(builder2);

	director1.Construct();
	director2.Construct();

	Product &product1 = builder1.GetProduct();
	cout << product1.GetPart() << endl;

	Product &product2 = builder2.GetProduct();
	cout << product2.GetPart() << endl;

	cin.get();

	return 0;
}