#include <iostream>

using namespace std;

int main()
{
    char* input = new char[100];

    cin.getline(input, 99);

    int total_count = 0;
    int lower_count = 0;
    int upper_count = 0;
    int digit_count = 0;
    int other_count = 0;

    char *i;

    for (i = input; *i != '\0'; i++)
    {
        total_count++;

        if (*i >= '0' && *i <= '9')
        {
            digit_count++;
            continue;
        }
        
        if (*i >= 'a' && *i <= 'z')
        {
            lower_count++;
            continue;
        }

        if (*i >= 'A' && *i <= 'Z')
        {
            upper_count++;
            continue;
        }

        other_count++;        
    }

    cout << upper_count << endl;
    cout << lower_count << endl;
    cout << digit_count << endl;
    cout << other_count << endl;
    cout << total_count << endl;

    delete[] input;

    return 0;
}
