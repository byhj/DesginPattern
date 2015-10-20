#include "Iterator.h"

int main()
{
	vector<int> v{ 1, 2, 3 ,4 };
	VecIterator<int> vIter(v);
	Iterator<int> &iter = vIter;

	for (iter.first(); !iter.isDone(); iter.next())
		cout << iter.current() << endl;

	cin.get();

	return 0;
}