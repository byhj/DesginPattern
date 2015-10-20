#include "Proxy.h"

void print(Subject &s)
{
	cout << s.Method() << endl;
}

int main()
{
	Proxy proxy;
	print(proxy);

	cin.get();

	return 0;
}