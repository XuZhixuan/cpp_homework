/**
 * Author: XuZhixuan
 * E-mail: sxxuzhixuan@hotmail.com
 * 
 * 由于未知原因，本题暂时无法通过
 **/

#include <iostream>
#include <string>

using namespace std;

struct Contact
{
	string name;
	string phone;
};

Contact transformer(string);
int findNum(string);
void sort(Contact*, int);
bool higher(string, string);

int main()
{
	Contact* c = new Contact[5];
	string input;

	for (int i = 0; i < 5; i++)
	{
		getline(cin, input);
		c[i] = transformer(input);
	}

	sort(c, 5);

    for (int i = 4; i >= 0; i--)
    {
        cout << c[i].name << ' ' << c[i].phone << endl;
    }
    
    delete[] c;

	return 0;
}

bool higher(string a, string b)
{
    int length = min(a.length(), b.length());

    for (int i = 0; i < length; i++)
    {
        if (a[i] < b[i])
        {
            return true;
        } else if (a[i] > b[i])
        {
            return false;
        }
        
    }

    return false;    
}


void sort(Contact* contacts, int size)
{
    Contact temp;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (higher(contacts[j].name, contacts[j + 1].name))
            {
                temp = contacts[j];
                contacts[j] = contacts[j + 1];
                contacts[j + 1] = temp;
            }            
        }        
    }    
}

Contact transformer(string origin)
{
	int pos = 0;
	Contact result;

	pos = findNum(origin) - 1;
	result.name = origin.substr(0, pos);
	result.phone = origin.substr(pos + 1, origin.length());

	return result;
}

int findNum(string input)
{
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] > 47 && input[i] < 58)
        {
            return i;
        }        
    }
    return -1; 
}
