#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int m, n;
int table[501][501];
int dp[501][501];

unsigned long long recursive(int x, int y)
{
    if (x == 0 && y == 0)
        return 1;
    if (table[x][y] == -1)
        return 0;

    int &ret = dp[x][y];
    if (ret != -1)
        return ret;
    
    else
    {

        ret = 0;
        if (table[x][y] < table[x - 1][y])
        {
            ret = ret + recursive(x - 1, y);
        }
        if (table[x][y] < table[x + 1][y])
        {
            ret = ret + recursive(x + 1, y);
        }
        if (table[x][y] < table[x][y - 1])
        {
            ret = ret + recursive(x, y - 1);
        }
        if (table[x][y] < table[x][y + 1])
        {
            ret = ret + recursive(x, y + 1);
        }
        return ret;
    }
}

int main()
{
    cin >> m >> n;
    memset(table, -1, sizeof(table));
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> table[i][j];
        }
    }
    cout << recursive(m - 1, n - 1) << endl;
}