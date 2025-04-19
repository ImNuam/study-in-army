#include <iostream>
#include <cstring>
using namespace std;
pair<int, int> people[16];
int n;
int dp[16];
int dfs(int i)
{
    int &ret = dp[i];
    if (ret != -1)
    {
        return ret;
    }
    if(i>=n){
        return 0;
    }
    else
    {
        if (i<n && people[i].first + i - 1<n)
        {

            ret = max(dfs(i+1),people[i].second+dfs(i+people[i].first));
            return ret;
        }
        else{
            ret = dfs(i+1);
            return ret;
        }
    }
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t, p;
        cin >> t >> p;
        people[i] = {t, p};
    }
    for (int i = 0; i < n; i++)
    {
        dfs(i);
    }
    cout << dp[0] << endl;
}