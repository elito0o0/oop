#include<iostream>
using namespace std;
class Human
{
	char* firstName;
	char* lastName;
public:
	Human(const char* _firstName = "", const char* _lastName = "")
	{
		int firstNameLength = strlen(_firstName) + 1;
		firstName = new char[firstNameLength];
		strcpy_s(firstName, firstNameLength, _firstName);
		int lastNameLength = strlen(_lastName) + 1;
		lastName = new char[lastNameLength];
		strcpy_s(lastName, lastNameLength, _lastName);

	}
	Human(const Human& h)
	{
		int firstNameLength = strlen(h.firstName) + 1;
		firstName = new char[firstNameLength];
		strcpy_s(firstName, firstNameLength, h.firstName);
		int lastNameLength = strlen(h.lastName) + 1;
		lastName = new char[lastNameLength];
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
			lastName = new char[lastNameLength];
			strcpy_s(lastName, lastNameLength, other.lastName);

		}
		return (*this);
	}
	const char* getFirstName()
	{
		return firstName;
	}
	const char* getLastName()
	{
		return lastName;
	}
	~Human()
	{
		delete[] firstName;
		delete[] lastName;
	}
	virtual void print()
	{
		cout << "First name: " << firstName << endl;
		cout << "Last name:  " << lastName << endl;
	}

};
class Student :public Human
{
	double grade;
public:
	Student(const char* _firstName = "", const char* _lastName = "", double _grade = 2) :Human(_firstName, _lastName), grade(_grade){}
	Student(const Student& s) :Human(s)
	{

		grade = s.grade;
	}
	Student& operator=(const Student& other)
	{
		if (this != &other)
		{
			Human::operator=(other);
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
		Human::print();
		cout << "Grade:  " << grade << endl;
	}

};
class Worker :public Human
{
	double weekSalary;
	int workHoursPerDay;
public:
	Worker(const char* _firstName = "", const char* _lastName = "", double _weekSalary = 0, int _workHoursPerDay = 0) :Human(_firstName, _lastName)
	{
		weekSalary = _weekSalary;
		workHoursPerDay = _workHoursPerDay;
	}
	Worker(const Worker& w) :Human(w)
	{
		weekSalary = w.weekSalary;
		workHoursPerDay = w.workHoursPerDay;
	}
	Worker& operator=(const Worker& other)
	{
		if (this != &other)
		{
			Human::operator=(other);
			weekSalary = other.weekSalary;
			workHoursPerDay = other.workHoursPerDay;
		}
		return (*this);
	}
	double getWeekSalary()const
	{
		return weekSalary;
	}
	double moneyPerHour()
	{
		double moneyPerHour = weekSalary / (5 * workHoursPerDay);
		return moneyPerHour;
	}
	void print()
	{
		Human::print();
		cout << "Week salary: " << weekSalary << endl;
		cout << "Work hours per day: " << workHoursPerDay << endl;
		cout << "Money per hour:  " << moneyPerHour() << endl;
	}
};

int main()
{
	Student oneSt("Elena", "Nikolova", 6);
	Student twoSt("Donika", "Nikolova", 6);
	Student threeSt("Donika", "Ivanova", 5);
	Student fourSt("Simona", "Petrova", 4);
	Student fiveSt("Donka", "Petkova", 3);
	Student sixSt("Milla", "Borisova", 5);
	Student sevenSt("Viktoriq", "Blagoeva", 6);
	Student eightSt("Aleksandra", "Georgieva", 4);
	Student nineSt("Kalin", "Ivanov", 5);
	Student tenSt("Preslav", "Ivanov", 4);
	Student allStudents[10] = { oneSt, twoSt, threeSt, fourSt, fiveSt, sixSt, sevenSt, eightSt, nineSt, tenSt };
	for (int i = 0; i < 9; i++)
	{

		for (int j = i + 1; j < 10; j++)
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
	cout << "***********************************************************\n";
	Worker oneW("Mariq", "Velikova", 150, 8);
	Worker twoW("Aleksandra", "Gantsarova", 190, 9);
	Worker threeW("Monika", "Penkova", 200, 6);
	Worker fourW("Valeri", "Kostadinov", 140, 5);
	Worker fiveW("Ivona", "Encheva", 220, 8);
	Worker sixW("Svilen", "Stoinov", 175, 7);
	Worker sevenW("Yoana", "Vitanova", 160, 6);
	Worker eightW("Zara", "Vasileva", 250, 12);
	Worker nineW("Liliq", "Dimitrova", 185, 9);
	Worker tenW("Krasimira", "Georgieva", 268, 12);

	Worker allWorkers[10] = { oneW, twoW, threeW, fourW, fiveW, sixW, sevenW, eightW, nineW, tenW };
	for (int i = 0; i < 9; i++)
	{

		for (int j = i + 1; j < 10; j++)
		if (allWorkers[j].moneyPerHour()>allWorkers[i].moneyPerHour())
		{
			Worker worker = allWorkers[i];
			allWorkers[i] = allWorkers[j];
			allWorkers[j] = worker;
		}

	}

	for (int i = 0; i < 10; i++)
	{
		allWorkers[i].print();
	}
	cout << "***********************************************************\n";
	Human *human[20] = { &oneSt, &twoSt, &threeSt, &fourSt, &fiveSt, &sixSt, &sevenSt, &eightSt, &nineSt, &tenSt, &oneW, &twoW, &threeW, &fourW, &fiveW, &sixW, &sevenW, &eightW, &nineW, &tenW };
    for (int i = 0; i < 19; i++)
	{
		for (int j = i + 1; j < 20; j++)
		if (strcmp(human[j]->getFirstName(), human[i]->getFirstName()) == 0)
		{
			if (strcmp(human[j]->getLastName(), human[i]->getLastName()) < 0)
			{
				Human *h = human[i];
				human[i] = human[j];
				human[j] = h;
			}
		}
		else if (strcmp(human[j]->getFirstName(), human[i]->getFirstName()) < 0)
		{
			Human *h = human[i];
			human[i] = human[j];
			human[j] = h;

		}
	}
	for (int i = 0; i < 20; i++)
	{
		human[i]->print();
	}

	system("pause");
	return 0;
}
