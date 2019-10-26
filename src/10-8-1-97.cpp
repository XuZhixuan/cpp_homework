#include <iostream>
#include <cmath>

using namespace std;

class Point
{
    protected:
        int x_;
        int y_;

    public:
        Point();
        void setPoint(int, int);
        int getX();
        int getY();
        void print();
};

class Line : public Point
{
    protected:
        Point endPoint_;

    public:
        Line();
        void setEndPoint(int, int);
        int getX1();
        int getY1();
        double length();
        void print();
};

int main()
{
    Line l;

    int x, y, x1, y1;

    cin >> x >> y >> x1 >> y1;

    l.setPoint(x, y);
    l.setEndPoint(x1, y1);

    cout << "Line l:";
    l.print();
    cout << endl << "the Length of l:" << l.length() << endl;

    return 0;
}

Point::Point()
{
    x_ = 0;
    y_ = 0;
}

void Point::setPoint(int x, int y)
{
    x_ = x;
    y_ = y;
}

int Point::getX()
{
    return x_;
}

int Point::getY()
{
    return y_;
}

void Point::print()
{
    cout << '[' << x_ << ',' << y_ << ']';
}

Line::Line()
{
    //
}

void Line::setEndPoint(int x, int y)
{
    endPoint_.setPoint(x, y);
}

int Line::getX1()
{
    return endPoint_.getX();
}

int Line::getY1()
{
    return endPoint_.getY();
}

double Line::length()
{
    int x = x_ - endPoint_.getX();
    int y = y_ - endPoint_.getY();

    x *= x;
    y *= y;

    return sqrt(x + y);
}

void Line::print()
{
    cout << "StartPoint=";
    Point::print();
    cout << ';';
    cout << "EndPoint=";
    endPoint_.print();
}
