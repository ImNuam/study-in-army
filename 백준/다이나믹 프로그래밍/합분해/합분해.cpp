#include <iostream>
#include <cstring>
using namespace std;

long long dp[201][201];
int n, k;
int di = 1e9;
long long recursive(int dest, int count)
{
    if(dest<0){
        return 0;
    }
    long long &ret = dp[dest][count];
    if(ret!= -1){
        return ret;
    }
    if (count == 1)
    {
        ret = 1;
    }
    else
    {
        ret = 0;
        for (int i = 0; i <= dest; i++)
        {
            ret += recursive(i, count - 1);
        }
        ret %= di;
    }
    return ret;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    cout << recursive(n, k) << endl;
}