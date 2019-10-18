#include <iostream>
#include <string>

using namespace std;

struct Contact
{
	string name;
	string phone;
};

Contact transformer(string);

int main()
{
	Contact* c = new Contact[5];
	string input;

	for (int i = 0; i < 5; i++)
	{
		getline(cin, input);
		c[i] = transformer(input);
	}

	// TODO 完成排序函数与输出

	return 0;
}

Contact transformer(string origin)
{
	char separator = ' ';
	int pos = 0;
	Contact result;

	pos = origin.find(separator, pos);
	result.name = origin.substr(0, pos);
	result.phone = origin.substr(pos + 1, origin.length());

	return result;
}
