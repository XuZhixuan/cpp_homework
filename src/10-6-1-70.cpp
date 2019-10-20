#include <iostream>
#include <cmath>

using namespace std;

inline bool has_same_symbol(double, double);

double quadratic_function(double);
double sin_function(double);

double (*fun_1)(double);
double (*fun_2)(double);

double euqation(double (*func)(double), double a, double b, double eps=1.0e-7);

int main()
{
    double upper_bound_1, lower_bound_1, upper_bound_2, lower_bound_2;
    
    fun_1 = quadratic_function;    
    fun_2 = sin_function;

    cin >> lower_bound_1 >> upper_bound_1 >> lower_bound_2 >> upper_bound_2;

    cout << euqation(fun_1, lower_bound_1, upper_bound_1) << endl;

    cout << euqation(fun_2, lower_bound_2, upper_bound_2) << endl;
    
    return 0;
}

double quadratic_function(double x)
{
    return x * x + 2 * x - 3;
}

double sin_function(double x)
{
    return sin(x);
}

double euqation(double (*func)(double), double a, double b, double eps)
{
    double n = (a + b) / 2;
    
    while (abs(func(n)) > eps)
    {
        if (!has_same_symbol(func(a), func(n)))
        {
            b = n;
        } else if (!has_same_symbol(func(n), func(b)))
        {
            a = n;
        }

        n = (a + b) / 2;        
    }

    return n;
    
}

inline bool has_same_symbol(double a, double b)
{
    return (a >= 0 && b >= 0) || (a < 0 && b < 0);
}
