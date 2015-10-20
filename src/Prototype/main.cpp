#include "Prototype.h"
#include <iostream>

using namespace std;

int main()
{
	ConcretePortotype1 cpa("Prototype");
	ConcretePortotype2 cpb(8);

	//make copy
	auto aCopy = cpa.clone();
	auto bCopy = cpb.clone();

	//casting prototype to orginal type
	auto aCopyPtr = dynamic_cast<ConcretePortotype1 *>(aCopy.get());
	auto bCopyPtr = dynamic_cast<ConcretePortotype2 *>(bCopy.get());

	cpa.SetName("XXX");
	cpb.SetValue(111);

	cout << aCopyPtr->GetName() << endl;
	cout << bCopyPtr->GetValue() << endl;

	cin.get();

	return 0;
}