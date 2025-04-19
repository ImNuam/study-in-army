#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int check[100001];
vector<vector<int>> dp;
void verifyAndPush(int what, int depth)
{
    if (check[what] == 0)
    {
        dp[depth].push_back(what);
        check[what] = 1;
    }
}
int fn(int to, int depth)
{
    dp.push_back(vector<int>());
    for (int i = 0; i < dp[depth].size(); i++)
    {
        int from = dp[depth][i];
        if (from % 2 == 0)
        {
            int roop = from;
            while (roop > 0 && roop % 2 == 0)
            {
                verifyAndPush(roop / 2, depth);
                roop /= 2;
            }
        }
    }
        for (int i = 0; i < dp[depth].size(); i++)
        {
            int from = dp[depth][i];
            verifyAndPush(from + 1, depth + 1);
            if (from > 0)
            {
                verifyAndPush(from - 1, depth + 1);
            }
            if (from == to)
            {
                return depth;
            }
        }

        return fn(to, depth + 1);
    }

int main()
{
    memset(check, 0, sizeof(check));
    int start, end;
    cin >> start >> end;
    dp.push_back(vector<int>());
    dp[0].push_back(end);
    check[end] = 1;
    if (start >= end)
    {
        cout << start - end << endl;
    }
    else
    {
        cout << fn(start, 0) << endl;
    }
}