#include <iostream>
#include "Adapter.h"

using namespace std;

void Func(Target &t)
{
	cout << t.Operation();
}

int main()
{
	Adapter adapter;
	//Adatper is also a Target
	Func(adapter);

	cin.get();

	return 0;
}