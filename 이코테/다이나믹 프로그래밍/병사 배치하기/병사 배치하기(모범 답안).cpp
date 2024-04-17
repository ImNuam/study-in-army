#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    reverse(v.begin(), v.end());
    int dp[2000];
    for (int i = 0; i < n; i++)
        dp[i] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[j] < v[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int maxValue = 0;
    for(int i=0; i<n; i++) maxValue=max(maxValue, dp[i]);
    cout << n-maxValue << '\n';
}