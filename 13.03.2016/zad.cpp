#include<iostream>
using namespace std;
struct Rectangle
{
	int length;
	int width;

};

void print_rectangle(Rectangle r)
{
	cout << "Length : " << r.length;
	cout << "Width: " << r.width;
}
//init rectangle r with values entered from the console
void init_rectangle(Rectangle& r)
{
	do
	{
		cout << "Enter length: ";
		cin >> r.length;
		cout << "Enter width: ";
		cin >> r.width;

	} while (r.length<=0||r.width<=0);
}
Rectangle init_rectangle()
{
	Rectangle r;
	//this is a pointer to the current Rectangle object
	//we will talk more about it later
	//we use "this"  to call  the init_rectangle function
	//implemenet above
	this->init_rectangle(r);
	return r;
}
int main()
{
	Rectangle p;
	p.init_rectangle(p);
	p.print_rectangle(p);
	system("pause");
	return 0;
}
