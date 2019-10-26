#include <iostream>

using namespace std;

class Shape
{
public:
	virtual void printName() = 0;
	virtual double printArea() = 0;
};

class Circle : public Shape
{
protected:
	double radius_;

public:
	Circle(double);
	void printName();
	double printArea();
};

class Square : public Shape
{
protected:
	double length_;

public:
	Square(double);
	void printName();
	double printArea();
};

class Rectangle : public Shape
{
protected:
	double length_;
	double width_;

public:
	Rectangle(double, double);
	void printName();
	double printArea();
};

class Trapezoid : public Shape
{
protected:
	double length_u_;
	double length_l_;
	double height_;

public:
	Trapezoid(double, double, double);
	void printName();
	double printArea();
};

class Triangle : public Shape
{
protected:
	double length_;
	double height_;

public:
	Triangle(double, double);
	void printName();
	double printArea();
};

int main()
{
	double a, b, c, d, e, f, g, h, i;

	cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;

	Shape* arr[5];

	Circle circle(a);
	arr[0] = &circle;

	Square square(b);
	arr[1] = &square;

	Rectangle rectangle(c, d);
	arr[2] = &rectangle;

	Trapezoid trapezoid(e, f, g);
	arr[3] = &trapezoid;

	Triangle triangle(h, i);
	arr[4] = &triangle;

	double area = 0;

	for (int i = 0; i < 5; i++)
	{
		arr[i]->printName();
		area += arr[i]->printArea();
		cout << endl;
	}

	cout << "totalarea:" << area << endl;

	return 0;
}

Circle::Circle(double radius)
{
	radius_ = radius;
}

void Circle::printName()
{
	cout << "circle:";
	cout << "radius=" << radius_ << ',';
}

double Circle::printArea()
{
	double area = 3.14159 * radius_ * radius_;
	cout << "area:" << area;

	return area;
}

Square::Square(double length)
{
	length_ = length;
}

void Square::printName()
{
	cout << "square:";
	cout << "side=" << length_ << ',';
}

double Square::printArea()
{
	double area = length_ * length_;
	cout << "area:" << area;

	return area;
}

Rectangle::Rectangle(double length, double width)
{
	length_ = length;
	width_ = width;
}

void Rectangle::printName()
{
	cout << "rectangle:";
	cout << "length=" << length_ << ',';
	cout << "width=" << width_ << ',';
}

double Rectangle::printArea()
{
	double area = length_ * width_;
	cout << "area:" << area;

	return area;
}

Trapezoid::Trapezoid(double length_u, double length_l, double height)
{
	length_u_ = length_u;
	length_l_ = length_l;
	height_ = height;
}

void Trapezoid::printName()
{
	cout << "trapezoid:";
	cout << "upperside=" << length_u_ << ',';
	cout << "bottomside=" << length_l_ << ',';
	cout << "hight=" << height_ << ',';
}

double Trapezoid::printArea()
{
	double area = (length_u_ + length_l_) * height_ / 2;
	cout << "area:" << area;

	return area;
}

Triangle::Triangle(double length, double height)
{
	length_ = length;
	height_ = height;
}

void Triangle::printName()
{
	cout << "trangle:";
	cout << "bottomside=" << length_ << ',';
	cout << "hight=" << height_ << ',';
}

double Triangle::printArea()
{
	double area = length_ * height_ / 2;
	cout << "area:" << area;

	return area;
}
