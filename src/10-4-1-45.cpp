#include <iostream>

using namespace std;

struct Coordinate
{
	int x;
	int y;
};

struct Circle
{
	Coordinate left_down;
	Coordinate right_up;
};

double square(Circle);

int main()
{
	Circle cir;

	cin >> cir.left_down.x;
	cin >> cir.left_down.y;
	cin >> cir.right_up.x;
	cin >> cir.right_up.y;

	cout << square(cir) << endl;

	return 0;
}

double square(Circle c)
{
	float square = (c.right_up.x - c.left_down.x) * (c.right_up.y - c.left_down.y);
	square /= 4;
	square *= 3.14159;

	return square;
}
