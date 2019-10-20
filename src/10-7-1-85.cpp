#include <iostream>

using namespace std;

class Point
{
    private:
        int x_coordinate_;
        int y_coordinate_;

    public:
        void setCoordinate(int, int);
        int getXCoordinate();
        int getYCoordinate();
        void printCoordinates();
};

class Circle
{
    private:
        Point center_;
        int radius_;

    public:
        void setCenter(int, int);
        void setRadius(int);
        Point getCenter();
        int getRadius();
        void printRadius();
};

int main()
{
    int x, y, r;

    cin >> x >> y >> r;

    Circle circle;

    circle.setCenter(x, y);
    circle.setRadius(r);

    circle.getCenter().printCoordinates();
    circle.printRadius();

    return 0;
}

void Point::setCoordinate(int x, int y)
{
    x_coordinate_ = x;
    y_coordinate_ = y;
}

int Point::getXCoordinate()
{
    return x_coordinate_;
}

int Point::getYCoordinate()
{
    return y_coordinate_;
}

void Point::printCoordinates()
{
    cout << "X=" << x_coordinate_ << endl;
    cout << "Y=" << y_coordinate_ << endl;
}

void Circle::setCenter(int x, int y)
{
    Point center;
    center.setCoordinate(x, y);
    center_ = center;
}

void Circle::setRadius(int r)
{
    radius_ = r;
}

Point Circle::getCenter()
{
    return center_;
}

int Circle::getRadius()
{
    return radius_;
}

void Circle::printRadius()
{
    cout << "R=" << radius_ << endl;
}
