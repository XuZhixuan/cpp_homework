#include <iostream>
#include <string>

using namespace std;

struct Student
{
	string id;
	int grade_1;
	int grade_2;
	int grade_3;
	double average;
};

void process(Student*, int);

int main()
{
	string id;
	int g_1;
	int g_2;
	int g_3;

	Student* students = new Student[6];

	for (int i = 0; i < 6; i++)
	{
		cin >> id >> g_1 >> g_2 >> g_3;
		students[i].id = id;
		students[i].grade_1 = g_1;
		students[i].grade_2 = g_2;
		students[i].grade_3 = g_3;
	}

	process(students, 6);

	for (int i = 0; i < 6; i++)
	{
		cout << students[i].id << ' ' << students[i].average << endl;
	}

	delete[] students;

	return 0;
}

void process(Student* students, int size)
{
	for (int i = 0; i < size; i++)
	{
		students[i].average = (students[i].grade_1 + students[i].grade_2 + students[i].grade_3) / 3;
	}
}
