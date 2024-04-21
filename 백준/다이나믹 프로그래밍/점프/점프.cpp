#include <iostream>
#include <string.h>
using namespace std;

long table[101][101];
long dp[101][101];
int t;
long recursive(int x, int y)
{
    long &ret = dp[x][y];
    if(table[x][y]==0 && x == t-1 && y== t-1) return 1;
    else if(table[x][y]==0 || table[x][y]==-1) return 0;
    if        
    (ret == -1)
    {
        ret = recursive(x + table[x][y], y) + recursive(x, y + table[x][y]);
    }
    return ret;
}

int main()
{
    for (int i = 0; i < 100; i++)
    {
        memset(dp[i], -1, sizeof(dp[i]));
        memset(table[i], -1, sizeof(table[i]));
    }
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
        {
            cin >> table[i][j];
        }
    }
    cout << recursive(0, 0) << endl;
}