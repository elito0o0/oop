#include<iostream>
using namespace std;
class Animal
{
	int age;
	double height;
	double weight;

public:
	Animal(int age = 0, double height = 0, double weight = 0);
	Animal(Animal& rhs)
	{
		this->age = rhs.age;
	}
};
int main()
{

}*/
/*#include<iostream>
using namespace std;
class Point3D
{
	int x;
	int y;
	int z;

public:
	int getX()const;
	int getY()const;
	int getZ()const;
	Point3D(int x = 0, int y = 0, int z = 0);
	Point3D(const Point3D& p)
	{
		this->x = p.x;
		this->y = p.y;
		this->z = p.z;
	}
};
int Point3D::getX()const
{
	return x;

}
int Point3D::getY()const
{
	return y;
}
int Point3D::getZ()const
{
	return z;
}
int main()
{

	system("pause");
	return 0;
}*/
/*#include<iostream>
using namespace std;
class Date
{
	int day;
	int month;
	int year;
public:
	int getDay()const;
	int getMonth()const;
	int getYear()const;
	void setDay(int newDay);
	void setMonth(int newMonth);
	void setYear(int newYear);
	Date(int day = 1, int month = 1, int year = 1900);
	Date(const Date& d)
	{
		this->day = d.day;
		this->month = d.month;
		this->year = d.year;
	}

};
int Date::getDay()const
{
	return day;
}
int Date::getMonth()const
{
	return month;
}
int Date::getYear()const
{
	return year;
}
void Date::setDay(int newDay)
{
	if (newDay >= 1 || newDay <= 31)
	{
		day = newDay;
	}
}
void Date::setMonth(int newMonth)
{
	if (newMonth >= 1 || newMonth <= 12)
	{
		month = newMonth;
	}
}
void Date::setYear(int newYear)
{
	if (newYear >= 1900)
	{
		year = newYear;
	}
}
*/
class Metal
{
	char name[32];
	double meltingPoint;
	double boilingPoint;
public:
	char* getName()const;
	int getMeltingPoint()const;
	int getBoilingPoint()const;
	void
};
