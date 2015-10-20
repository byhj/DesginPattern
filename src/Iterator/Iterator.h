#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

using namespace std;

template<typename T>
class Iterator
{
public:
	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool isDone() const = 0;
	virtual T& current() = 0;
};

template<typename T>
class VecIterator : public Iterator<T>
{
public:
	VecIterator(vector<T> &v):vec(v), pos(0) {}

	void first() override {
		pos = 0;
	}
	void next() override
	{
		++pos;
	}
	bool isDone() const override
	{
		return pos >= vec.size();
	}
	T& current() override
	{
		if (isDone() == false)
			return vec.at(pos);

		throw out_of_range("out of range");
	}

private:
	vector<T> vec;
	size_t  pos;
};
#endif // _DE
