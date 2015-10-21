#include "Observer.h"

int main()
{
	ObserverImp a, b, c;
	Subject subject;
	subject.attachObserver(&a);
	subject.attachObserver(&b);
	subject.attachObserver(&c);

	subject.changeState("Observer pattern");
	cout << a.getState() << endl;
	cout << b.getState() << endl;
	cout << c.getState() << endl;

	cin.get();

	return 0;
}