#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	Person();
	Person(string, int, string);
	virtual void ShowInfo() = 0;

protected:
	string name_;
	int age_;
	string status_;
};

class Teacher : protected Person
{
public:
	Teacher(string, int);
	void ShowInfo();
};

class Student : protected Person
{
public:
	Student(string, int);
	void ShowInfo();
};

Person::Person()
{
	name_ = "";
	age_ = 0;
	status_ = "";
}

Person::Person(string name, int age, string status)
{
	name_ = name;
	age_ = age;
	status_ = status;
}

Teacher::Teacher(string name, int age)
{
	name_ = name;
	age_ = age;
	status_ = "teacher";
}

void Teacher::ShowInfo()
{
	cout << "name:" << name_ << endl;
	cout << "age:" << age_ << endl;
	cout << "status:" << status_ << endl;
}

Student::Student(string name, int age)
{
	name_ = name;
	age_ = age;
	status_ = "student";
}

void Student::ShowInfo()
{
	cout << "name:" << name_ << endl;
	cout << "age:" << age_ << endl;
	cout << "status:" << status_ << endl;
}

int main()
{
	string input_name;
	int input_age;
	string input_status;

	cin >> input_name >> input_age >> input_status;

	if (input_status == "teacher")
	{
		Teacher t(input_name, input_age);
		t.ShowInfo();
	}
	else if (input_status == "student")
	{
		Student s(input_name, input_age);
		s.ShowInfo();
	}

	cin >> input_name >> input_age >> input_status;

	if (input_status == "teacher")
	{
		Teacher t(input_name, input_age);
		t.ShowInfo();
	}
	else if (input_status == "student")
	{
		Student s(input_name, input_age);
		s.ShowInfo();
	}

	return 0;
}
