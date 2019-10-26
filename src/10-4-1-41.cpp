#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> list;

    int temp;

    while (true)
    {
        cin >> temp;

        if (temp < 0)
        {
            break;
        }

        list.push_back(temp); 
    }

    sort(list.begin(), list.end());

    int sum = 0;

    for (vector<int>::size_type i = 0; i < list.size(); i++)
    {
        sum += list[i];
    }
    
    cout << list.size() << endl;
    cout << list[list.size() - 1] << endl;
    cout << *list.begin() << endl;
    cout << sum / list.size() << endl;

    return 0;
}
