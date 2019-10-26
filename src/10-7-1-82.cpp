#include <iostream>
#include <string>

using namespace std;

class Dog
{
    private:
        string name_;
        int age_;
        char sex_;
        float weight_;

    public:
        void setdata(string, int, char, float);
        string getName();
        int getAge();
        char getSex();
        float getWeight();
};

int main()
{
    string name;
    int age;
    char sex;
    float weight;

    cin >> name >> age >> sex >> weight;

    Dog doggy;

    doggy.setdata(name, age, sex, weight);

    cout << "Dog’s name:" << doggy.getName() << endl;
    cout << "Dog’s age:" << doggy.getAge() << endl;
    cout << "Dog’s sex:" << doggy.getSex() << endl;
    cout << "Dog’s weight:" << doggy.getWeight() << endl;
    cout << "Dog speak:Arf!Arf!" << endl;

    return 0;
}

void Dog::setdata(string name, int age, char sex, float weight)
{
    name_ = name;
    age_ = age;
    sex_ = sex;
    weight_ = weight;
}

string Dog::getName()
{
    return name_;
}

int Dog::getAge()
{
    return age_;
}

char Dog::getSex()
{
    return sex_;
}

float Dog::getWeight()
{
    return weight_;
}
