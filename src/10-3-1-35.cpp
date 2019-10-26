#include <iostream>

bool possible(int, int, int, int);

int main()
{
	using namespace std;

	int bricks;

	cin >> bricks;

	int people = bricks;

	int men, women, children;

	for (int men = 1; men <= people; men++)
	{
		women = 3 * bricks - (men + 2 * bricks) * 3.5 / 2.5;
		children = (men + 2 * bricks) / 2.5;
		if ((women < 0 || children < 0) || (women != (int)women || children != (int)children))
		{
			break;
		}
		else if (possible(men, women, children, bricks))
		{
			cout << men << ' ' << women << ' ' << children << endl;
		}
	}

	return 0;
}

bool possible(int men, int women, int children, int bricks)
{
	if (men * 4 + women * 3 + children * 0.5 == bricks)
	{
		return true;
	}

	return false;
}
