#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int an = -1, am = -1; // 목적지의 좌표
int result[1001][1001];
vector<vector<int>> stage;
queue<pair<int, int>> q;
int verify(pair<int, int> p)
{
    if (p.first >= stage.size() || p.first < 0 || p.second >= stage[0].size() || p.second < 0 || result[p.first][p.second] == 0 || result[p.first][p.second]!=-1)
    {
        return 0;
    }

    return 1;
}

int main()
{
    memset(result, -1, sizeof(result));
    int n, m; // n이 세로, m이 가로
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        stage.push_back(vector<int>());
        for (int j = 0; j < m; j++)
        {
            int tmp;
            cin >> tmp;
            stage[i].push_back(tmp);
            if (tmp == 2)
            {
                an = i;
                am = j;
            }
            if (tmp == 0)
            {
                result[i][j] = 0;
            }
        }
    }
    q.push(make_pair(an, am));
    result[an][am]=0;
    while (!q.empty())
    {

        if (verify(make_pair(q.front().first + 1, q.front().second)))
        {
            q.push(make_pair(q.front().first + 1, q.front().second));
            result[q.front().first + 1][q.front().second] = result[q.front().first][q.front().second] + 1;
        }
        if (verify(make_pair(q.front().first - 1, q.front().second)))
        {
            q.push(make_pair(q.front().first - 1, q.front().second));
            result[q.front().first - 1][q.front().second] = result[q.front().first][q.front().second] + 1;
        }
        if (verify(make_pair(q.front().first, q.front().second + 1)))
        {
            q.push(make_pair(q.front().first, q.front().second + 1));
            result[q.front().first][q.front().second + 1] = result[q.front().first][q.front().second] + 1;
        }
        if (verify(make_pair(q.front().first, q.front().second - 1)))
        {
            q.push(make_pair(q.front().first, q.front().second - 1));
            result[q.front().first][q.front().second - 1] = result[q.front().first][q.front().second] + 1;
        }
        q.pop();
    }
    for (int i = 0; i < stage.size(); i++)
    {
        for (int j = 0; j < stage[i].size(); j++)
        {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
}