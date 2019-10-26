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
bool isLetter(char);
bool isNum(char);

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
		}
		else if (a[i] > b[i])
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
	int name_end = 0, phone_begin = 0;

	for (int ite = 0; ite < origin.length(); ite++)
	{
		if (!isLetter(origin[ite]) && !name_end)
		{
			name_end = ite;
		}

		if (isNum(origin[ite]) && !phone_begin)
		{
			phone_begin = ite;
		}
	}

	Contact result;

	result.name = origin.substr(0, name_end);
	result.phone = origin.substr(phone_begin, origin.length());

	return result;
}

bool isLetter(char a)
{
	return (a > 64 && a < 91) || (a > 96 && a < 123);
}

bool isNum(char a)
{
	return a >= '0' && a <= '9';
}
