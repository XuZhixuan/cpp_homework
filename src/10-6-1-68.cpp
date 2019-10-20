#include <iostream>
#include <cstring>

using namespace std;

void sort(int*, int);

int main()
{
    int len;

    cin >> len;

    int* list = new int[len];

    for (int i = 0; i < len; i++)
    {
        cin >> list[i];
    }

    sort(list, len);

    for (int i = 0; i < len; i++)
    {
        cout << list[i] << ' ';
    }
    
    cout << endl;
    
    return 0;
}

void sort(int* arr, int size)
{
    int temp;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }            
        }        
    }    
}
