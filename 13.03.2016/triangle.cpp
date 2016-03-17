#include<iostream>
#include<cmath>
using namespace std;

struct Triangle
{
	double a;
	double b;
	double c;

	double getAB()
	{
		return c;
	}
	double getBC()
	{
		return a;
	}
	double GetAC()
	{
		return b;
	}
	Triangle mult_k(int k);
	void create(double x, double y, double z);
	void print();
	double perimeter();
	double  surface();
};
void Triangle::create(double x,double y,double z)
{
	a = x;
	b = y;
	c = z;
}
void Triangle::print()
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}
double Triangle:: perimeter()
{
	return a + b + c;
}
double Triangle::surface()
{
	double semiperimeter = perimeter() / 2;
	return sqrt((semiperimeter - c)*(semiperimeter - b)*(semiperimeter - a)*semiperimeter);
}
Triangle Triangle::mult_k(int k)
{
	Triangle p;
	p.create(k*a, k*b, k*c);
	return p;


}
int main()
{
	Triangle p;
	double a, b, c;
		cout << "AB=";
		cin >> c;
		cout << "BC= ";
		cin >> a;
		cout << "AC= ";
		cin >> b;
		if (a + b > c && b + c > a && a + c > b)
		{
			p.create(a, b, c);
			p.print();
			cout << "P = " << p.perimeter();
			cout << "\n";
			cout << "S =  " << p.surface();
			cout << "\n";
			int k = 2;
			p.mult_k(k);
		}
		else cout << "Ne sus6testvuva"<<endl;
	system("pause");
	return 0;
}
