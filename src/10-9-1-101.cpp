#include <iostream>

using namespace std;

class Shape
{
    public:
        virtual double area() = 0;
};

class Circle : public Shape
{
    private:
        double radius_;
    
    public:
        Circle(double);
        double area();
};

class Rectangle : public Shape
{
    private:
        double length_;
        double height_;

    public:
        Rectangle(double, double);
        double area();
};

class Triangle : public Shape
{
    private:
        double length_;
        double height_;

    public:
        Triangle(double, double);
        double area();
};

int main()
{
    double a, b;

    cin >> a;
    Circle c(a);

    cout << c.area() << endl;

    cin >> a >> b;
    Rectangle r(a, b);

    cout << r.area() << endl;

    cin >> a >> b;
    Triangle t(a, b);

    cout << t.area() << endl;

    return 0;
}

Circle::Circle(double radius)
{
    radius_ = radius;
}

double Circle::area()
{
    return 3.14159 * radius_ * radius_;
}

Rectangle::Rectangle(double length, double height)
{
    length_ = length;
    height_ = height;
}

double Rectangle::area()
{
    return length_ * height_;
}

Triangle::Triangle(double length, double height)
{
    length_ = length;
    height_ = height;
}

double Triangle::area()
{
    return length_ * height_ / 2;
}
