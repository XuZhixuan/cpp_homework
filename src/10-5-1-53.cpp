#include <iostream>

using namespace std;

int ack(int, int);

int main()
{
    int m, n;

    cin >> m >> n;

    cout << ack(m, n) << endl;

    return 0;
}

int ack(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }

    if (m > 0)
    {
        if (n == 0)
        {
            return ack(m - 1, 1);
        }
        
        if (n > 0)
        {
            return ack(m - 1, ack(m, n - 1));
        }        
    }        
    return -1;
}
