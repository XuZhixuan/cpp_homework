#include <iostream>

using namespace std;

int cubic(int);
double cubic(double);

int main()
{
    int a;

    double b;

    cin >> a >> b;

    cout << cubic(a) << endl;
    cout << cubic(b) << endl;

    return 0;
}

int cubic(int in)
{
    return in * in * in;
}

double cubic(double in)
{
    return in * in * in;    
}
