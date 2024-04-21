#include <iostream>
#include <string.h>
using namespace std;

int price[1001];
int dp[1001];

int recursive(int n)
{
    int &ret = dp[n];
    if (ret != -1)
        return ret;
    ret = price[n];
    for (int i = 1; i <= n / 2; i++)
    {
        int comp = recursive(i) + recursive(n - i);
        ret = max(ret, comp);
    }
    return ret;
}

int main()
{
    int t;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= t; i++)
    {
        cin >> price[i];
    }
    cout << recursive(t) << endl;
}