#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int array[] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[i - 1 - j] > array[i - j])
            {
                swap(array[i - 1 - j], array[i - j]);
            }
        }
    }
    for(int i =0; i<10; i++){
        cout << array[i] << ' ';
    }
}