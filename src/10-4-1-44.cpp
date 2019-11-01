/*
* Author: XuZhixuan
* Email: sxxuzhixuan@hotmail.com
*
* 测试成功，未提交
*
*/

#include <iostream>

using namespace std;

struct Triangle
{
	int** content;
	int limit;
};

void generate(Triangle);
void print_triangle(Triangle);
void deconstruct(Triangle);
int get_content(Triangle, int, int);

int main()
{
	int limit;

	cin >> limit;

	int** triangle = new int*[limit];

	Triangle t;
	t.content = triangle;
	t.limit = limit;

	for (int i = 0; i < limit; i++)
	{
		triangle[i] = new int[i + 1];
	}

	//Initializing
	triangle[0][0] = 1;

	//Generating
	generate(t);

	print_triangle(t);
	
	//Delete to privent memory leak
	deconstruct(t);

	return 0;
}

int get_content(Triangle t, int a, int b)
{
	if (a < 0 || a > t.limit)
	{
		return 0;
	}

	if (b < 0 || b > a)
	{
		return 0;
	}

	return t.content[a][b];
}

void generate(Triangle triangle)
{
	for (int i = 1; i < triangle.limit; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			triangle.content[i][j] = get_content(triangle, i - 1, j - 1) + get_content(triangle, i - 1, j);
		}
	}	
}

void print_triangle(Triangle triangle)
{
	for (int i = 0; i < triangle.limit; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << triangle.content[i][j] << (j == i ? '\n' : ' ');
		}
	}
}

void deconstruct(Triangle triangle)
{
	for (int i = 0; i < triangle.limit; i++)
	{
		delete[] triangle.content[i];
	}

	delete[] triangle.content;
}
