#include <iostream>

using namespace std;

class Ellipse
{
    private:
        int x_;
        int y_;
        double a_;
        double b_;

    public:
        Ellipse();
        Ellipse(int, int, double, double);

        double Area();
};

int main()
{
    int x, y;
    double a, b;

    cin >> x >> y >> a >> b;

    Ellipse e(x, y, a, b);


    cout << e.Area() << endl;


    return 0;
}

Ellipse::Ellipse(int x, int y, double a, double b)
{
    x_ = x;
    y_ = y;
    a_ = a;
    b_ = b;
}

double Ellipse::Area()
{
    return 3.14159 * a_ * b_;
}
