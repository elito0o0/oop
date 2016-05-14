#include<iostream>
using namespace std;
const int max = 15;
class Student
{
	char *firstName;
	char *surname;
	char *lastName;
	int age;
	int schoolNumber;
public:
	Student(const char* _firstName = "", const char* _surname = "", const char* _lastName = "", int _age = 0, int _schoolNumber = 0) :
		age(_age), schoolNumber(_schoolNumber)
	{
		firstName = new char[strlen(_firstName) + 1];
		strcpy_s(firstName, strlen(firstName), _firstName);
		surname = new char[strlen(_surname) + 1];
		strcpy_s(surname, strlen(surname), _surname);
		lastName = new char[strlen(_lastName) + 1];
		strcpy_s(lastName, strlen(lastName), _lastName);
	}
	Student(const Student& s)
	{
		firstName = new char[strlen(s.firstName) + 1];
		strcpy_s(firstName, strlen(firstName), s.firstName);
		surname = new char[strlen(s.surname) + 1];
		strcpy_s(surname, strlen(surname), s.surname);
		lastName = new char[strlen(s.lastName) + 1];
		strcpy_s(lastName, strlen(lastName), s.lastName);
		this->age = s.age;
		this->schoolNumber = s.schoolNumber;
	}
	Student& operator=(const Student& other)
	{
		if (this != &other)
		{
			firstName = new char[strlen(other.firstName) + 1];
			strcpy_s(firstName, strlen(firstName), other.firstName);
			surname = new char[strlen(other.surname) + 1];
			strcpy_s(surname, strlen(surname), other.surname);
			lastName = new char[strlen(other.lastName) + 1];
			strcpy_s(lastName, strlen(lastName), other.lastName);
			age = other.age;
			schoolNumber = other.schoolNumber;
		}
		return (*this);
	}
	
	char* getStudentFirstName()const
	{
		return firstName;
	}
	char* getStudentSurname()const
	{
		return surname;
	}
	char* getStudentLastName()const
	{
		return lastName;
	}
	int getStudentAge()const
	{
		return age;
	}
	int getSchoolNumber()const
	{
		return schoolNumber;
	}
	void setStudentFirstName(const char* newFirstName)
	{
		firstName = new char[strlen(newFirstName) + 1];
		strcpy_s(firstName, strlen(firstName), newFirstName);
	}
	void setStudentSurname(const char* newSurname)
	{
		surname = new char[strlen(newSurname) + 1];
		strcpy_s(surname, strlen(surname), newSurname);
	}
	void setStudentLastName(const char* newLastName)
	{
		lastName = new char[strlen(newLastName) + 1];
		strcpy_s(lastName, strlen(lastName), newLastName);
	}
	void setStudentAge(int newAge)
	{
		age = newAge;
	}
	void setSchoolNumber(int newSchoolNumber)
	{
		schoolNumber = newSchoolNumber;
	}
	/*~Student()
	{
		delete[] firstName;
		delete[] surname;
		delete[] lastName;
	}*/
};
class Teacher
{
	char* firstName;
	char* surname;
	char* lastName;
	char* subject;
public:
	Teacher(const char* _firstName = "", const char* _surname = "", const char* _lastName = "", const char* _subject = "")
	{
		firstName = new char[strlen(_firstName) + 1];
		strcpy_s(firstName, strlen(firstName), _firstName);
		surname = new char[strlen(_surname) + 1];
		strcpy_s(surname, strlen(surname), _surname);
		lastName = new char[strlen(_lastName) + 1];
		strcpy_s(lastName, strlen(lastName), _lastName);
		subject = new char[strlen(_subject) + 1];
		strcpy_s(subject, strlen(subject), _subject);
    }
	Teacher(const Teacher& t)
	{
        firstName = new char[strlen(t.firstName) + 1];
		strcpy_s(firstName, strlen(firstName), t.firstName);
		surname = new char[strlen(t.surname) + 1];
		strcpy_s(surname, strlen(surname), t.surname);
		lastName = new char[strlen(t.lastName) + 1];
		strcpy_s(lastName, strlen(lastName), t.lastName);
		subject = new char[strlen(t.subject) + 1];
		strcpy_s(subject, strlen(subject), t.subject);

	}
	Teacher& operator=(const Teacher& other)
	{
		if (this != &other)
		{
			firstName = new char[strlen(other.firstName) + 1];
			strcpy_s(firstName, strlen(firstName), other.firstName);
			surname = new char[strlen(other.surname) + 1];
			strcpy_s(surname, strlen(surname), other.surname);
			lastName = new char[strlen(other.lastName) + 1];
			strcpy_s(lastName, strlen(lastName), other.lastName);
			subject = new char[strlen(other.subject) + 1];
			strcpy_s(subject, strlen(subject), other.subject);
		}
		return (*this);
	}
	
	char* getTeacherFirstName()const
	{
		return firstName;
	}
	char* getTeacherSurname()const
	{
		return surname;
	}
	char* getTeacherLastName()const
	{
		return lastName;
	}
	char* getSubject()const
	{
		return subject;
	}
	void setTeacherFirstName(const char* newFirstName)
	{
		firstName = new char[strlen(newFirstName) + 1];
		strcpy_s(firstName, strlen(firstName), newFirstName);
	}
	void setTeacherSurname(const char* newSurname)
	{
		surname = new char[strlen(newSurname) + 1];
		strcpy_s(surname, strlen(surname), newSurname);
	}
	void setTeacherLastName(const char* newLastName)
	{
		lastName = new char[strlen(newLastName) + 1];
		strcpy_s(lastName, strlen(lastName), newLastName);
	}
	void setSubject(const char* newSubject)
	{
		subject = new char[strlen(newSubject) + 1];
		strcpy_s(subject, strlen(subject), newSubject);
	}
	/*~Teacher()
	{
		delete[] firstName;
		delete[] surname;
		delete[] lastName;
		delete[] subject;
	}*/
};
class School
{
	Student *s;
	Teacher *t;
	
public:
	School( Student *st, Teacher *th)
	{
		 s = st;
		 t = th;

	}
	School(const School& d)
	{
		this->s = d.s;
		this->t = d.t;
	}
	School& operator=(const School& other)
	{
		if (this != &other)
		{
			s = other.s;
			t = other.t;
		}
		return (*this);
	}

	void searchStudentBySchoolNumber( int schoolsNumber)
	{
		for (int i = 0; i < 3; i++)
		{
			if (schoolsNumber == s[i].getSchoolNumber())
			{
				cout<<"Student's first name: "<<s[i].getStudentFirstName()<<endl;
				cout << "Student's surname: " << s[i].getStudentSurname() << endl;
				cout << "Student's last name: " <<s[i].getStudentLastName() << endl;
				cout << "Student's age: " <<s[i].getStudentAge() << endl;
			}
		}
	}
	void searchStudentByFirstAndLastNAme();
};
int main()
{
	Student a("Elena", "Petkova", "Nikolova", 19, 14);
	Student b("Donika", "Petkova", "Nikolova", 7, 6);
	Student allstudents[2] = { a, b };
	Teacher c("Eleonora", "Antonova", "Nikolova", "Matematika");
	Teacher d("Mariq", "Ivanova", "Ivanova", "Biologiq");
	Teacher allTeachers[2] = { c, d };
	School school(allstudents, allTeachers);
	
	school.searchStudentBySchoolNumber(14);

	system("pause");
	return 0;
}
