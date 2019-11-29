#include <iostream>
#include <string>

using namespace std;

char str[3];

char* convert(int);

class Time
{
    private:
        int hour_;
        int minute_;
        int second_;
    
    public:
        Time();
        Time(int, int, int);
        void setTime(int, int, int);
        void addTime(int, int, int);
        void subTime(int, int, int);
        void printTime_24();
        void printTime_12();
};

int main()
{
    Time t1;
    Time t2(8, 10, 30);

    cout << "t1_12" << ' ';
    t1.printTime_12();
    cout << "t1_24" << ' ';
    t1.printTime_24();

    cout << "t2_12" << ' '; 
    t2.printTime_12();
    cout << "t2_24" << ' ';
    t2.printTime_24();

    int hour, minute, second;

    cin >> hour >> minute >> second;
    t1.setTime(hour, minute, second);

    cin >> hour >> minute >> second;
    t1.addTime(hour, minute, second);
    t2.subTime(hour, minute, second);

    t1.printTime_12();    
    t1.printTime_24();    

    t2.printTime_12();    
    t2.printTime_24();

    return 0;
}

Time::Time()
{
    hour_ = 0;
    minute_ = 0;
    second_ = 0;
}

Time::Time(int hour, int minute, int second)
{
    second_ = second % 60;
    minute += second / 60;
    minute_ = minute % 60;    
    hour += minute / 24;
    hour_ = hour % 24;
}

void Time::setTime(int hour, int minute, int second)
{
    second_ = second % 60;
    minute += second / 60;
    minute_ = minute % 60;    
    hour += minute / 60;
    hour_ = hour % 24;
}

void Time::addTime(int hour, int minute, int second)
{
    second_ += second;
    minute += second_ / 60;
    second_ %= 60;
    minute_ += minute;
    hour += minute_ / 60;
    minute_ %= 60;
    hour_ += hour;
    hour_ %= 24;
}

void Time::subTime(int hour, int minute, int second)
{
    second_ -= second;
    while (second_ < 0)
    {
        second_ += 60;
        minute_ --;
    }
    
    minute_ -= minute;
    while (minute_ < 0)
    {
        minute_ += 60;
        hour_ --;
    }    

    hour_ -= hour;
    while (hour_ < 0)
    {
        hour_ += 24;
    }   

}

void Time::printTime_12()
{
    int hour = hour_;
    string flag = " AM";
    
    if (hour >= 12)
    {
        flag = " PM";
        hour -= 12;
    }

    cout << convert(hour) << ':';
    cout << convert(minute_) << ':';
    cout << convert(second_) << flag << endl;
}

void Time::printTime_24()
{
    cout << convert(hour_) << ':';
    cout << convert(minute_) << ':';
    cout << convert(second_) << endl;
}

char* convert(int input)
{
    str[0] = '0' + input / 10;
    str[1] = '0' + input % 10;
    
    return str;
}
