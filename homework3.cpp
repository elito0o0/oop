#include<iostream>
using namespace std;
class Human
{
	char* firstName;
	char* lastName;
public:
	Human(const char* _firstName = "", const char* _lastName = "")
	{
		int firstNameLength=strlen(_firstName)+1;
		firstName = new char[firstNameLength];
		strcpy_s(firstName, firstNameLength, _firstName);
		int lastNameLength = strlen(_lastName) + 1;
		lastName = new char[lastNameLength] + 1;
		strcpy_s(lastName, lastNameLength, _lastName);

	}
	Human(const Human& h)
	{
		int firstNameLength = strlen(h.firstName) + 1;
		firstName = new char[firstNameLength];
		strcpy_s(firstName, firstNameLength, h.firstName);
		int lastNameLength = strlen(h.lastName) + 1;
		lastName = new char[lastNameLength] + 1;
		strcpy_s(lastName, lastNameLength, h.lastName);
	}
	Human& operator=(const Human& other)
	{
		if (this != &other)
		{
			delete[] firstName;
			int firstNameLength = strlen(other.firstName) + 1;
			firstName = new char[firstNameLength];
			strcpy_s(firstName, firstNameLength, other.firstName);
			delete[] lastName;
			int lastNameLength = strlen(other.lastName) + 1;
			lastName = new char[lastNameLength] + 1;
			strcpy_s(lastName, lastNameLength, other.lastName);
			
		}
		return (*this);
	}
	char* getFirstName()const
	{
		return firstName;
	}
	char* getLastName()const
	{
		return lastName;
	}
	
	
};
class Student :public Human
{
	double grade;
public:
	Student(const char* _firstName = "", const char* _lastName = "", double _grade = 2) :Human(_firstName, _lastName), grade(_grade){}
	Student(const Student& s)
	{
		grade = s.grade;
	}
	Student& operator=(const Student& other)
	{
		if (this != &other)
		{
			grade = other.grade;
		}
		return (*this);
	}
	double getGrade()const
	{
		return grade;
	}
	void print()
	{
		cout << "First name: " << getFirstName()<<endl;
		cout << "Last name:  " << getLastName() << endl;
		cout << "Grade:  " << grade << endl;
	}

};
class Worker :public Human
{
	double weekSalary;
	int workHoursPerDay;
public:
	Worker(const char* _firstName = "", const char* _lastName = "", double _weekSalary = 0, int _workHoursPerDay = 0) :Human(_firstName, _lastName), weekSalary(_weekSalary), workHoursPerDay(_workHoursPerDay){}
	Worker(const Worker& w)
	{
		this->weekSalary = w.weekSalary;
		this->workHoursPerDay - w.workHoursPerDay;
	}
	Worker& operator=(const Worker& other)
	{
		if (this != &other)
		{
			weekSalary = other.weekSalary;
			workHoursPerDay = other.workHoursPerDay;
		}
	}

};

int main()
{
	Student oneSt("Elena", "Nikolova",6);
	Student twoSt("Donika", "Nikolova", 6);
	Student threeSt("Donika", "Ivanova", 5);
	Student fourSt("Simona", "Petrova", 4);
	Student fiveSt("Donka", "Petkova", 3);
	Student sixSt("Milla", "Borisova", 5);
	Student sevenSt("Viktoriq", "Blagoeva", 6);
	Student eightSt("Aleksandar", "Georgiev", 4);
	Student nineSt("Kalin", "Ivanov", 5);
	Student tenSt("Preslav", "Ivanov",4);
	
	Student allStudents[10] = {oneSt,twoSt,threeSt,fourSt,fiveSt,sixSt,sevenSt,eightSt,nineSt,tenSt};
	for (int i = 0; i < 9; i++)
	{

		for (int j = i+1; j < 10; j++)
		if ((allStudents[j].getGrade()) < allStudents[i].getGrade())
		{
			Student student = allStudents[i];
			allStudents[i] = allStudents[j];
			allStudents[j] = student;
		}
				
	}
		
	for (int i = 0; i < 10; i++)
	{
		allStudents[i].print();
	}
	system("pause");
	return 0;
}
