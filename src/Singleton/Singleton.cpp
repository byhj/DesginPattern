#include <iostream>
#include <string>

using namespace std;

class Singleton
{

public:
	string Method()
	{
		return "Singleton" ;
	}
	static Singleton & GetInstance()
	{
		static Singleton instance;
		return instance;
	}

private:
	Singleton() {}
	Singleton(const Singleton &);
	Singleton & operator = (const Singleton &);
	~Singleton() {}
};

int main()
{
	auto &s = Singleton::GetInstance();
	cout << s.Method() << endl;

	return 0;
}