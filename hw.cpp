#include<iostream>
#include<string>
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
		strcpy_s(surname, strlen(_surname) + 1, _surname);
		lastName = new char[strlen(_lastName) + 1];
		strcpy_s(lastName, strlen(_lastName) + 1, _lastName);

	}
	Student(const Student& s)
	{
		firstName = new char[strlen(s.firstName) + 1];
		strcpy_s(firstName, strlen(s.firstName) + 1, s.firstName);

		surname = new char[strlen(s.surname) + 1];
		strcpy_s(surname, strlen(s.surname) + 1, s.surname);

		lastName = new char[strlen(s.lastName) + 1];
		strcpy_s(lastName, strlen(s.lastName) + 1, s.lastName);

		this->age = s.age;
		this->schoolNumber = s.schoolNumber;
	}
	Student& operator=(const Student& other)
	{
		if (this != &other)
		{
			delete[] firstName;
			firstName = new char[strlen(other.firstName) + 1];
			strcpy_s(firstName, strlen(other.firstName) + 1, other.firstName);
			delete[] surname;
			surname = new char[strlen(other.surname) + 1];
			strcpy_s(surname, strlen(other.surname) + 1, other.surname);
			delete[] lastName;
			lastName = new char[strlen(other.lastName) + 1];
			strcpy_s(lastName, strlen(other.lastName) + 1, other.lastName);
			
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
		strcpy_s(firstName, strlen(newFirstName) + 1, newFirstName);
		
	}
	void setStudentSurname(const char* newSurname)
	{
		surname = new char[strlen(newSurname) + 1];
		strcpy_s(surname, strlen(newSurname) + 1, newSurname);
		
	}
	void setStudentLastName(const char* newLastName)
	{
		lastName = new char[strlen(newLastName) + 1];
		strcpy_s(lastName, strlen(newLastName) + 1, newLastName);
		
	}
	void setStudentAge(int newAge)
	{
		age = newAge;
	}
	void setSchoolNumber(int newSchoolNumber)
	{
		schoolNumber = newSchoolNumber;
	}
	~Student()
	{
	delete[] firstName;
	delete[] surname;
	delete[] lastName;
	}
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
		strcpy_s(firstName, strlen(_firstName) + 1, _firstName);
		
		surname = new char[strlen(_surname) + 1];
		strcpy_s(surname, strlen(_surname) + 1, _surname);
		
		lastName = new char[strlen(_lastName) + 1];
		strcpy_s(lastName, strlen(_lastName) + 1, _lastName);
		
		subject = new char[strlen(_subject) + 1];
		strcpy_s(subject, strlen(_subject) + 1, _subject);
		
	}
	Teacher(const Teacher& t)
	{
		firstName = new char[strlen(t.firstName) + 1];
		strcpy_s(firstName, strlen(t.firstName) + 1, t.firstName);
		
		surname = new char[strlen(t.surname) + 1];
		strcpy_s(surname, strlen(t.surname) + 1, t.surname);
		
		lastName = new char[strlen(t.lastName) + 1];
		strcpy_s(lastName, strlen(t.lastName) + 1, t.lastName);
		
		subject = new char[strlen(t.subject) + 1];
		strcpy_s(subject, strlen(t.subject) + 1, t.subject);
		
	}
	Teacher& operator=(const Teacher& other)
	{
		if (this != &other)
		{
			delete[] firstName;
			firstName = new char[strlen(other.firstName) + 1];
			strcpy_s(firstName, strlen(other.firstName) + 1, other.firstName);
			delete[] surname;
			surname = new char[strlen(other.surname) + 1];
			strcpy_s(surname, strlen(other.surname) + 1, other.surname);
			delete[] lastName;
			lastName = new char[strlen(other.lastName) + 1];
			strcpy_s(lastName, strlen(other.lastName) + 1, other.lastName);
			delete[] subject;
			subject = new char[strlen(other.subject) + 1];
			strcpy_s(subject, strlen(other.subject) + 1, other.subject);
			
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
		strcpy_s(firstName, strlen(newFirstName) + 1, newFirstName);
		
	}
	void setTeacherSurname(const char* newSurname)
	{
		surname = new char[strlen(newSurname) + 1];
		strcpy_s(surname, strlen(newSurname) + 1, newSurname);
		
	}
	void setTeacherLastName(const char* newLastName)
	{
		lastName = new char[strlen(newLastName) + 1];
		strcpy_s(lastName, strlen(newLastName) + 1, newLastName);
		
	}
	void setSubject(const char* newSubject)
	{
		subject = new char[strlen(newSubject) + 1];
		strcpy_s(subject, strlen(newSubject) + 1, newSubject);
		
	}
	~Teacher()
	{
		delete[] firstName;
		delete[] surname;
		delete[] lastName;
		delete[] subject;
	}
};
class School
{
	Student *s;
	Teacher *t;
	int teacherSize;
	int studentSize;
public:
	School(Student *st, Teacher *th, int _teacherSize=0, int _studentSize=0) :teacherSize(_teacherSize), studentSize(_studentSize)
	{
		s = new Student[_studentSize];
		for (int i = 0; i < _studentSize; i++)
		{
			s[i] = st[i];
		}
		t = new Teacher[_teacherSize];
		for (int i = 0; i < _teacherSize; i++)
		{
			t[i] = th[i];
		}


	}
	School(const School& d)
	{
		this->s = d.s;
		this->t = d.t;
		this->teacherSize = d.teacherSize;
		this->studentSize = d.studentSize;
	}
	School& operator=(const School& other)
	{
		if (this != &other)
		{
			s = other.s;
			t = other.t;
			teacherSize = other.teacherSize;
			studentSize = other.studentSize;
		}
		return (*this);
	}

	void searchStudentBySchoolNumber(int schoolsNumber)
	{
		for (int i = 0; i < studentSize; i++)
		{
			if (schoolsNumber == s[i].getSchoolNumber())
			{
				cout << "Student's first name: " << s[i].getStudentFirstName() << endl;
				cout << "Student's surname: " << s[i].getStudentSurname() << endl;
				cout << "Student's last name: " << s[i].getStudentLastName() << endl;
				cout << "Student's age: " << s[i].getStudentAge() << endl;
			}
		}
	}
	void searchStudentByFirstAndLastName(char *firstName, char *lastName)
	{
		for (int i = 0; i < studentSize; i++)
		{
			if (strcmp(s[i].getStudentFirstName(), firstName) == 0 && strcmp(s[i].getStudentLastName(), lastName) == 0)
			{
				cout << "Student's first name: " << s[i].getStudentFirstName() << endl;
				cout << "Student's surname: " << s[i].getStudentSurname() << endl;
				cout << "Student's last name: " << s[i].getStudentLastName() << endl;
				cout << "Student's age: " << s[i].getStudentAge() << endl;
				cout << "Student's school number: " << s[i].getSchoolNumber() << endl;
			}
		}

	}
	void SearchTeacherBySubject(char *subject)
	{
		for (int i = 0; i < teacherSize; i++)
		{
			if (strcmp(t[i].getSubject(), subject) == 0)
			{
				cout << "Teacher's first name: " << t[i].getTeacherFirstName() << endl;
				cout << "Teacher's surname:  " << t[i].getTeacherSurname() << endl;
				cout << "Teacher's last name: " << t[i].getTeacherLastName() << endl;
			}
		}
	}
};
int main()
{
	Student a("Elena", "Petkova", "Nikolova", 19, 14);
	Student b("Donika", "Petkova", "Nikolova", 7, 6);
	Student f("Donika", "Ivanova", "Nikolova", 10, 5);
	Student allStudents[3] = { a, b, f };
	Teacher c("Eleonora", "Antonova", "Nikolova", "Matematika");
	Teacher d("Mariq", "Ivanova", "Ivanova", "Biologiq");
	Teacher allTeachers[2] = { c, d };
	School school(allStudents, allTeachers, 2,2);

	school.searchStudentBySchoolNumber(14);
	cout << "*******************************************************\n";
	school.searchStudentByFirstAndLastName("Donika", "Nikolova");
	cout << "*******************************************************\n";
	school.SearchTeacherBySubject("Matematika");
	system("pause");
	return 0;
}
