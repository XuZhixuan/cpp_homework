#include <iostream>

using namespace std;

class ElectronicClock
{
    private:
        int year_;
        int month_;
        int day_;
        int hour_;
        int minute_;
        int second_;
    
    public:
        ElectronicClock();
        ElectronicClock(int, int, int, int, int, int);
        void printTime();
};

int main()
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;

    cin >> year >> month >> day;
    cin >> hour >> minute >> second;

    ElectronicClock e(year, month, day, hour, minute, second);

    e.printTime();

    return 0;
}

ElectronicClock::ElectronicClock(int year, int month, int day, int hour, int minute, int second)
{
    year_ = year;
    month_ = month;
    day_ = day;
    hour_ = hour;
    minute_ = minute;
    second_ = second;
}

void ElectronicClock::printTime()
{
    cout << year_ << "年";
    cout << month_ << "月";
    cout << day_ << "日";

    cout << endl;

    cout << hour_ << ':';
    cout << minute_ << ':';
    cout << second_ << endl;
}
