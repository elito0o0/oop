#include<iostream>
using namespace std;
class Base
{
public:
	void print()
	{
		cout << "I'm Bo" << endl;
	}
};
class Der :public Base
{
public:
	void print()
	{
		Base::print();
		cout << "Denived" << endl;
	}
};
class Der1
{
public:
	void print()
	{

	}
};
int main()
{
	Base b;
	Der d;
	b.print();
	d.print();
	Base *b1 = &d;
	b1->print();
	system("pause");
	return 0;
}
