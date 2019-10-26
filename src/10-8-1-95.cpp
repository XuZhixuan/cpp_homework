#include <iostream>
#include <cstring>

using namespace std;

class Person
{
    protected:
        char Name_[10];
        int Age_;
        char Sex_;

    public:
        void Register(char*, int, char);
        char* GetName();
        int GetAge();
        char GetSex();
        void ShowMe();
};

class Teacher : protected Person
{
    protected:
        char Specialty_[20];
        char Position_[20];
        char MajorCourse_[20];

    public:
        Teacher();
        void TeacherRegister(char*, int, char, char*, char*, char*);
        void ShowMe();
};

int main()
{
    Teacher t;
    t.ShowMe();

    char name[20];
    char spec[20];
    char pos[20];
    char maj[20];
    char sex;
    int age;

    cin >> name >> age >> sex >> spec >> pos >> maj;

    t.TeacherRegister(name, age, sex, spec, pos, maj);
    t.ShowMe();

    return 0;
}

void Person::Register(char* name, int age, char sex)
{
    strcpy(Name_, name);
    Age_ = age;
    Sex_ = sex;
}

char* Person::GetName()
{
    return Name_;
}

int Person::GetAge()
{
    return Age_;
}

char Person::GetSex()
{
    return Sex_;
}

void Person::ShowMe()
{
    cout << Name_ << ' ' << Age_ << ' ' << Sex_ << ' ';
}

Teacher::Teacher()
{
    char def[20] = {'X', 'X', 'X', '\0'};
    Register(def, 0, 'm');
    strcpy(Specialty_, def);
    strcpy(Position_, def);
    strcpy(MajorCourse_, def);
}

void Teacher::TeacherRegister(char* name, int age, char sex, char* spec, char* pos, char* maj)
{
    Register(name, age, sex);
    strcpy(Specialty_, spec);
    strcpy(Position_, pos);
    strcpy(MajorCourse_, maj);
}

void Teacher::ShowMe()
{
    Person::ShowMe();
    cout << Specialty_ << ' ' << Position_ << ' ' << MajorCourse_ << endl;
}
