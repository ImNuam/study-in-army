#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int leftBound(vector<int> &v, int start, int end, int find)
{
    if (start == end)
    {
        return start;
    }
    int index = (start + end) / 2;
    if (v[index] >= find)
        leftBound(v, start, index, find);
    else if (v[index] < find)
        leftBound(v, index + 1, end, find);
}
int rightBound(vector<int> &v, int start, int end, int find)
{
    if (start == end)
    {
        return start;
    }
    int index = (start + end) / 2 +1;
    if (v[index] > find)
        rightBound(v, start, index-1, find);
    else if (v[index] <= find)
        rightBound(v, index , end, find);
}
int main()
{    
    int n, x;
    cin >> n >> x;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    int start = 0, end = n - 1;
    cout << rightBound(v, start, end, x)-leftBound(v, start, end, x) + 1<< endl;
    // 특정 수를 찾는다.
    // 왼쪽에서 특정 수가 안 나올 때까지
}