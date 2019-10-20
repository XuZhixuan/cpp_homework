#include <iostream>
#include <string>

using namespace std;

int count(string);
bool isLetter(char);

int main()
{
    string input;

    getline(cin, input);

    int words = count(input);

    cout << words << endl;
}

int count(string sentence)
{
    int length = sentence.length();

    bool in_word = false;
    
    int count = 0;

    for (int i = 0; i < length; i++)
    {
        if (isLetter(sentence[i]))
        {
            if (!in_word)
            {
                count++;
                in_word = !in_word;
            }else
            {
                continue;
            }
        }else
        {
            if (in_word)
            {
                in_word = !in_word;
            }            
        }        
    }   

    return count;
}

bool isLetter(char a)
{
    return (a > 64 && a < 91) || (a > 96 && a < 123);
}
