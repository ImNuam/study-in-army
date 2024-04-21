#include <iostream>
#include <vector>

using namespace std;

int table[51];
vector<vector<int>> dp(51);
int n, start, m;

int recursive(int n)
{
    if (n == 0)
    {
        dp[n].push_back(start);
        return start;
    }
    else
    {
        int result = -1;
        int temp1, temp2;
        for (vector<int>::iterator iter = dp[n - 1].begin(); iter != dp[n - 1].end(); ++iter)
        {
            if ((temp1 = (*iter) - table[n]) >= 0)
            {
                dp[n].push_back(temp1);
                result = max(result, temp1);
            }
            if ((temp2 = (*iter) + table[n]) <= m)
            {
                dp[n].push_back(temp2);
                result = max(result, temp2);
            }
        }
        dp[n-1].clear();
        return result;
    }
}

int main()
{
    cin >> n >> start >> m;
    dp[0] = vector<int>();
    for (int i = 1; i <= n; i++)
    {
        cin >> table[i];
        dp[i] = vector<int>();
    }
    for (int i = 0; i < n; i++)
        recursive(i);
    std::cout << recursive(n) << endl;
}