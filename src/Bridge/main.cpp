#include "Bridge.h"

using namespace std;

int main()
{
	ConcreteImplementorA impA;
	ConcreteImplementorB impB;
	RefindedAbstraction rabA(impA);
	RefindedAbstraction rabB(impB);

	rabA.operation();
	rabB.operation();

	cin.get();

	return 0;
}