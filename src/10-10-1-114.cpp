#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a;
    double b;
  
    cin >> a >> b;
  
    for(int i = 1; i <=10; i++)
    {
        cout << setiosflags(ios::right);
        cout << setw(i) << a << endl;
    }
  
    for(int i = 1; i <=10; i++)
    {
        cout << setiosflags(ios::right);
        cout << setw(i) << b << endl;
    }
  
    return 0;
}
