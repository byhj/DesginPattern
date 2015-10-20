#include "Strategy.h"

int main()
{
	Strategy1 strategy1;
	Strategy2 strategy2;

	Context context(strategy1);
	context.executeStrategy();
	context.setStrategy(strategy2);
	context.executeStrategy();

	cin.get();

	return 0;
}