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
		delete[] firstName;
		surname = new char[strlen(_surname) + 1];
		strcpy_s(surname, strlen(surname), _surname);
		delete[] surname;
		lastName = new char[strlen(_lastName) + 1];
		strcpy_s(lastName, strlen(lastName), _lastName);
		delete[] lastName;
	}
	Student(const Student& s)
	{
		firstName = new char[strlen(s.firstName) + 1];
		strcpy_s(firstName, strlen(firstName), s.firstName);
		delete[] firstName;
		surname = new char[strlen(s.surname) + 1];
		strcpy_s(surname, strlen(surname), s.surname);
		delete[] surname;
		lastName = new char[strlen(s.lastName) + 1];
		strcpy_s(lastName, strlen(lastName), s.lastName);
		delete[] lastName;
		this->age = s.age;
		this->schoolNumber = s.schoolNumber;
	}
	Student& operator=(const Student& other)
	{
		if (this != &other)
		{
			firstName = new char[strlen(other.firstName) + 1];
			strcpy_s(firstName, strlen(firstName), other.firstName);
			delete[] firstName;
			surname = new char[strlen(other.surname) + 1];
			strcpy_s(surname, strlen(surname), other.surname);
			delete[] surname;
			lastName = new char[strlen(other.lastName) + 1];
			strcpy_s(lastName, strlen(lastName), other.lastName);
			delete[] lastName;
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
		delete[] firstName;
	}
	void setStudentSurname(const char* newSurname)
	{
		surname = new char[strlen(newSurname) + 1];
		strcpy_s(surname, strlen(surname), newSurname);
		delete[] surname;
	}
	void setStudentLastName(const char* newLastName)
	{
		lastName = new char[strlen(newLastName) + 1];
		strcpy_s(lastName, strlen(lastName), newLastName);
		delete[] lastName;
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
		strcpy_s(firstName, strlen(firstName), _firstName);
		delete[] firstName;
		surname = new char[strlen(_surname) + 1];
		strcpy_s(surname, strlen(surname), _surname);
		delete[] surname;
		lastName = new char[strlen(_lastName) + 1];
		strcpy_s(lastName, strlen(lastName), _lastName);
		delete[] lastName;
		subject = new char[strlen(_subject) + 1];
		strcpy_s(subject, strlen(subject), _subject);
		delete[] subject;
	}
	Teacher(const Teacher& t)
	{
		firstName = new char[strlen(t.firstName) + 1];
		strcpy_s(firstName, strlen(firstName), t.firstName);
		delete[] firstName;
		surname = new char[strlen(t.surname) + 1];
		strcpy_s(surname, strlen(surname), t.surname);
		delete[] surname;
		lastName = new char[strlen(t.lastName) + 1];
		strcpy_s(lastName, strlen(lastName), t.lastName);
		delete[] lastName;
		subject = new char[strlen(t.subject) + 1];
		strcpy_s(subject, strlen(subject), t.subject);
		delete[] subject;
	}
	Teacher& operator=(const Teacher& other)
	{
		if (this != &other)
		{
			firstName = new char[strlen(other.firstName) + 1];
			strcpy_s(firstName, strlen(firstName), other.firstName);
			delete[] firstName;
			surname = new char[strlen(other.surname) + 1];
			strcpy_s(surname, strlen(surname), other.surname);
			delete[] surname;
			lastName = new char[strlen(other.lastName) + 1];
			strcpy_s(lastName, strlen(lastName), other.lastName);
			delete[] lastName;
			subject = new char[strlen(other.subject) + 1];
			strcpy_s(subject, strlen(subject), other.subject);
			delete[] subject;
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
		delete[] firstName;
	}
	void setTeacherSurname(const char* newSurname)
	{
		surname = new char[strlen(newSurname) + 1];
		strcpy_s(surname, strlen(surname), newSurname);
		delete[] surname;
	}
	void setTeacherLastName(const char* newLastName)
	{
		lastName = new char[strlen(newLastName) + 1];
		strcpy_s(lastName, strlen(lastName), newLastName);
		delete[] lastName;
	}
	void setSubject(const char* newSubject)
	{
		subject = new char[strlen(newSubject) + 1];
		strcpy_s(subject, strlen(subject), newSubject);
		delete[] subject;
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
public:
	School(Student *st, Teacher *th, int _teacherSize) :teacherSize(_teacherSize)
	{
		s = st;
		t = th;

	}
	School(const School& d)
	{
		this->s = d.s;
		this->t = d.t;
		this->teacherSize = d.teacherSize;
	}
	School& operator=(const School& other)
	{
		if (this != &other)
		{
			s = other.s;
			t = other.t;
			teacherSize = other.teacherSize;
		}
		return (*this);
	}

	void searchStudentBySchoolNumber(int schoolsNumber)
	{
		for (int i = 0; i < 3; i++)
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
		for (int i = 0; i < 3; i++)
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
	School school(allStudents, allTeachers, 2);

	school.searchStudentBySchoolNumber(14);
	cout << "*******************************************************\n";
	school.searchStudentByFirstAndLastName("Donika", "Nikolova");
	cout << "*******************************************************\n";
	school.SearchTeacherBySubject("Matematika");
	system("pause");
	return 0;
}
