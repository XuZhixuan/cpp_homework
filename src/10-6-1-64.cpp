#include <iostream>

using namespace std;

char *mystrspc(char *string, int n);

int flag = 0;

int main()
{
    int length;

    cin >> length;

    char* str_1 = new char[length + 1];
    str_1 = mystrspc(str_1, length);

    cout << '+';
    cout << str_1;
    cout << '+' << endl;

    char* str_2 = new char[length + 1];
    str_2 = mystrspc(str_2, length);

    cout << '+';
    cout << str_2;
    cout << '+' << endl;

    delete[] str_1;
    delete[] str_2;

    return 0;
}

char *mystrspc(char *string, int n)
{
    if (!flag)
    {
        for (int i = 0; i < n; i++)
        {
            string[i] = '*';
        }
        
        flag++;
    } else
    {
        for (int i = 1; i <= n; i++)
        {
            string[i - 1] = i % 10 ? i % 10 + '0': 'A' - 1 + i / 10;
        }
        
    }    

    return string;
}
