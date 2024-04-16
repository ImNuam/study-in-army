#include <iostream>
#include <vector>
using namespace std;
int sum_length(vector<int> &v, int index)
{
    int sum = 0;
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
    {
        if ((*iter) - index > 0)
            sum += (*iter) - index;
    }
    return sum;
}
int binary_search(vector<int> &v, int start, int end, int find)
{
    if (start >= end)
        return end;
    int index = (start + end) / 2;
    if (sum_length(v, index) < find)
        return binary_search(v, start, index-1, find);
    else if (sum_length(v, index) > find)
        return binary_search(v, index+1, end, find);
    else return index;
}

int main()
{
    int n, want;
    cin >> n >> want;
    vector<int> lengths(0, 4);
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (max < temp)
            max = temp;
        lengths.push_back(temp);
    }
    cout << binary_search(lengths, 0, max, want) << endl;
}