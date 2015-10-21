#include "Memento.h"

int main()
{
	Originator orginator;
	Memento memento("Memento design pattern");
	orginator.setMemento(memento);
	Memento mem = orginator.createMemento();
	cout << mem.getState();

	cin.get();

	return 0;
}