#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    int result = 0;
    for (int j = 2; j < n; j++)
    {
        int m = max(v[j - 1], v[j - 2] + v[j]);
        v[j] = m;
        if (result < m)
            result = m;
    }
    cout << result << endl;
}