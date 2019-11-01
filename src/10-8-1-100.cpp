#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

char str[3];

const string MONTH_NAME[13] = {
	"Error",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

const int MONTH_DAYS[13] = {
	-1,
	31,
	28,
	31,
	30,
	31,
	30,
	31,
	31,
	30,
	31,
	30,
	31
};

char* convert(int);

class Time
{
private:
	int hour_;
	int minute_;
	int second_;

public:
	Time();
	void setTime(int, int, int);
	int secCalc();
	Time add(Time&);
	Time sub(Time&);
	void print_12();
	void print_24();
};

class Date
{
private:
	int year_;
	int month_;
	int day_;

public:
	Date();
	void setDate(int, int, int);
	int dayCalc();
	void incDay();
	void addDay(int);
	bool isLeapYear();
	bool isEndOfMonth();
	void print_ymd();
	void print_mdy();
	int daysBetween(Date);
};

class DateTime : public Date, public Time
{
public:
	DateTime();
	DateTime addTime(Time&);
};

int main()
{
	DateTime dt;

	int a, b, c;
	cin >> a >> b >> c;

	dt.setDate(a, b, c);
	cin >> a >> b >> c;

	Time at;
	at.setTime(a, b, c);
	dt.addTime(at);

	cin >> a >> b >> c;
	at.setTime(a, b, c);
	dt.addTime(at);

	dt.print_mdy();
	dt.print_12();

	return 0;
}

Time::Time()
{
	hour_ = 0;
	minute_ = 0;
	second_ = 0;
}

void Time::setTime(int hour, int minute, int second)
{
	second_ = second % 60;
	minute += second / 60;
	minute_ = minute % 60;
	hour += minute / 60;
	hour_ = hour;
}

int Time::secCalc()
{
	int secs = 0;
	secs += hour_ * 60 * 60;
	secs += minute_ * 60;
	secs += second_;

	return secs;
}

Time Time::add(Time& t)
{
	int second = t.second_;
	int minute = t.minute_;
	int hour = t.hour_;

	second_ += second;
	minute += second_ / 60;
	second_ %= 60;
	minute_ += minute;
	hour += minute_ / 60;
	minute_ %= 60;
	hour_ += hour;
	hour_ %= 24;

	return *this;
}

Time Time::sub(Time& t)
{
	int second = t.second_;
	int minute = t.minute_;
	int hour = t.hour_;

	second_ -= second;
	while (second_ < 0)
	{
		second_ += 60;
		minute_--;
	}

	minute_ -= minute;
	while (minute_ < 0)
	{
		minute_ += 60;
		hour_--;
	}

	hour_ -= hour;
	while (hour_ < 0)
	{
		hour_ += 24;
	}

	return *this;
}

void Time::print_12()
{
	int hour = hour_;
	string flag = " AM";

	if (hour >= 12)
	{
		flag = " PM";
		hour -= 12;
	}

	cout << convert(hour);
	cout << ':' << convert(minute_);
	cout << ':' << convert(second_) << flag << endl;
}

void Time::print_24()
{
	cout << convert(hour_);
	cout << ':' << convert(minute_);
	cout << ':' << convert(second_) << endl;
}

Date::Date()
{
	year_ = 1900;
	month_ = 1;
	day_ = 1;
}

void Date::setDate(int year, int month, int day)
{
	if (year >= 1900)
	{
		year_ = year;
		month_ = month;
		day_ = day;
	}
}

int Date::dayCalc()
{
	int year = year_;
	int month = month_;
	int day = day_;

	int days = day_ - 1;

	month_ -= 1;
	while (month_ > 0)
	{
		if (month_ == 2)
		{
			if (isLeapYear())
			{
				days += 29;
			}
			else {
				days += 28;
			}
		}
		else {
			days += MONTH_DAYS[month_];
		}

		month_--;
	}

	year_ -= 1;
	while (year_ >= 1900)
	{
		if (isLeapYear())
		{
			days += 366;
		}
		else {
			days += 365;
		}
		year_--;
	}

	setDate(year, month, day);

	return days;
}

void Date::incDay()
{
	if (isEndOfMonth())
	{
		month_ += 1;
		day_ = 1;

		if (month_ > 12)
		{
			month_ = 1;
			year_ += 1;
		}
	}
	else
	{
		day_ += 1;
	}
}

void Date::addDay(int day)
{
	for (int i = 0; i < day; i++)
	{
		incDay();
	}
}

bool Date::isLeapYear()
{
	if (year_ % 4 == 0)
	{
		if (year_ % 100 == 0 && year_ % 400 != 0)
		{
			return false;
		}
		return true;
	}
	return false;
}

bool Date::isEndOfMonth()
{
	int day = day_;

	if (month_ == 2 && isLeapYear())
	{
		day -= 1;
	}

	return day == MONTH_DAYS[month_];
}

void Date::print_ymd()
{
	cout << year_ << ',' << month_ << ',' << day_ << endl;
}

void Date::print_mdy()
{
	cout << MONTH_NAME[month_] << ' ' << day_ << ',' << year_ << endl;
}

int Date::daysBetween(Date date)
{
	return abs(dayCalc() - date.dayCalc());
}

DateTime::DateTime()
{
	//
}

DateTime DateTime::addTime(Time& t)
{
	int seconds = t.secCalc();
	seconds += secCalc();

	addDay(seconds / 86400);
	add(t);

	return *this;
}

char* convert(int input)
{
	str[0] = '0' + input / 10;
	str[1] = '0' + input % 10;

	return str;
}
