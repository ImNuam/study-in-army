#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    vector<int> max;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
        max.push_back(temp);
    }
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 2; i + j < v.size(); j++)
        {
            if (max[i + j] < max[i] + v[i + j])
            {
                max[i + j] = max[i] + v[i + j];
            }
        }
    }
    int result = 0;
    for (int i = 0; i < max.size(); i++)
    {
        if (result < max[i])
            result = max[i];
    }
    cout << result << endl;
}