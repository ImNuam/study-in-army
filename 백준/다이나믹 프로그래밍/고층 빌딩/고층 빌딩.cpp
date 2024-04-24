#include <iostream>
#include <string.h>

using namespace std;

int k=0, f=1;
int n, l, r;
long long dp[101][101][101];
long long recursive(int c, int x, int y)
{
    long long &ret = dp[c][x][y];
    if (ret != -1)
        return ret;
    if (c == 0)
    {
        if (x == l && y == r)
            ret = 1;
        else
            ret = 0;
    }
    else
    {
        ret = recursive(c - 1, x + 1, y) + recursive(c - 1, x, y + 1) + (n-c-1) * recursive(c-1, x, y);
        
    }
    ret = ret % 1000000007;
    return ret;
}

int main()
{
    cin >> n >> l >> r;
    memset(dp, -1, sizeof(dp));
    cout << recursive(n - 1, 1, 1) << endl;
}