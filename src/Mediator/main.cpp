#include "Mediator.h"

int main()
{
	Colleague peter("Peter");
	Colleague paul("Paul");
	Colleague kate("Kate");

	ConcreteMediator mediator;
	mediator.registerColleague(peter);
	mediator.registerColleague(paul);
	mediator.registerColleague(kate);

	peter.send("Paul", "wu");
	paul.send("Peter", "aas");
	kate.send("Paul", "diku");
	paul.send("Kate", "ydkm");
	
	cin.get();

	return 0;
}