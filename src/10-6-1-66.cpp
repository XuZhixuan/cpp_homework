#include <iostream>
#include <cstring>

using namespace std;

char *myltrim(char *string);

int main()
{
    char* str_1 = new char[100];
    cin.getline(str_1, 99);

    cout << '[';
    cout << str_1;
    cout << ']' << endl;

    str_1 = myltrim(str_1);

    cout << '[';
    cout << str_1;
    cout << ']' << endl;

    return 0;
}

char *myltrim(char *string)
{
    int length = strlen(string);

    int count = 0;

    for (int i = 0; i < length; i++)
    {
        if (string[i] != ' ')
        {
            break;
        }

        count++;
    }

    string += count;

    return string;
}
