#include<iostream>
#include<string>
using namespace std;
class Person
{
	char name[25];
	int age;
public:
	Person(const char* _name = "", int _age = 0) :age(_age){ strcpy_s(name, _name); };
	Person(const Person& k)
	{
		this->age = k.age;
		strcpy_s(name, k.name);

	}
	Person& operator=(const Person& other)
	{
		if (this != &other)
			strcpy_s(name, other.name);
		age = other.age;
		return (*this);

	}
	~Person()
	{
		delete[] name;
	}
};

class Student :public Person{
	char favoriteClass[50];
public:
	Student(const char* _name = "", int _age = 0, const char* _favoriteClass = "") :Person(_name, _age){ strcpy_s(favoriteClass, _favoriteClass); };
	Student(const Student& l)
	{
		Person::Person();
		strcpy_s(favoriteClass, l.favoriteClass);
	}
	Student& operator=(const Student& other)
	{
		if (this != &other)
			Person::operator=(other);
		strcpy_s(favoriteClass, other.favoriteClass);
		return (*this);

	}
	~Student()
	{
		delete [] favoriteClass;
	}
};
class Teacher :public Person
{
	char speciality[50];
public:
	Teacher(const char* _name = "", int _age = 0, const char* _speciality = "") :Person(_name, _age){
		strcpy_s(speciality, _speciality);
	}
	Teacher(const Teacher& d)
	{
		Person::Person();
		strcpy_s(speciality, d.speciality);
	}
	Teacher& operator=(const Teacher& other)
	{
		Person::operator=(other);
		if (this != &other)
			strcpy_s(speciality, other.speciality);
		return (*this);
	}
	~Teacher()
	{
		delete [] speciality;
	}

};
int main()
{

	system("Pause");
	return 0;
}
