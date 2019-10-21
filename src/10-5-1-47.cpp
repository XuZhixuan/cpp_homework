#include <iostream>
#include <cstring>

using namespace std;

void mystrrev(char string[]);

int main()
{
    char* input = new char[100];

    cin.getline(input, 99);

    mystrrev(input);

    cout << input << endl;

    delete[] input;

    return 0;
}

void mystrrev(char string[])
{
    int length = strlen(string);
    int count = length / 2;

    char temp;

    for (int i = 0; i < count; i++)
    {
        temp = string[i];
        string[i] = string[length - 1 - i];
        string[length - 1 - i] = temp;
    }

    return;    
}
