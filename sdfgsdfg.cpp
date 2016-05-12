#include<iostream>
#include<string>
using namespace std;
class Person
{
	char *name;
	int age;
public:
	Person(const char* _name = "", int _age = 0) :age(_age){ name = new char[strlen(_name) + 1]; strcpy_s(name, strlen(name), _name); };
	Person(const Person& k)
	{
		this->age = k.age;
		name = new char[strlen(k.name) + 1];
		strcpy_s(name,strlen(name), k.name);

	}
	Person& operator=(const Person& other)
	{
		if (this != &other)
			name = new char[strlen(other.name) + 1];
			strcpy_s(name,strlen(name), other.name);
		age = other.age;
		return (*this);

	}
	~Person()
	{
		delete[] name;
	}
};

class Student :public Person{
	char *favoriteClass;
public:
	Student(const char* _name = "", int _age = 0, const char* _favoriteClass = "") :Person(_name, _age){ 
		favoriteClass = new char[strlen(_favoriteClass) + 1];
		strcpy_s(favoriteClass,strlen(favoriteClass), _favoriteClass); };
	Student(const Student& l) :Person(l)
	{
		favoriteClass = new char[strlen(l.favoriteClass) + 1];
		strcpy_s(favoriteClass,strlen(favoriteClass), l.favoriteClass);
	}
	Student& operator=(const Student& other)
	{
		Person::operator=(other);
		if (this != &other)
			favoriteClass = new char[strlen(other.favoriteClass) + 1];
		strcpy_s(favoriteClass,strlen(favoriteClass), other.favoriteClass);
		return (*this);

	}
	~Student()
	{
		delete [] favoriteClass;
	}
};
class Teacher :public Person
{
	char* speciality;
public:
	Teacher(const char* _name = "", int _age = 0, const char* _speciality = "") :Person(_name, _age){

		speciality = new char[strlen(_speciality) + 1];
		
		strcpy_s(speciality, strlen(speciality), _speciality);
	}
	Teacher(const Teacher& d) : Person(d)
	{
		speciality = new char[strlen(d.speciality) + 1];
		strcpy_s(speciality,strlen(speciality), d.speciality);
	}
	Teacher& operator=(const Teacher& other)
	{
		Person::operator=(other);
		if (this != &other)
			speciality = new char[strlen(other.speciality) + 1];
			strcpy_s(speciality,strlen(speciality),other.speciality);
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
