#include <iostream>
#include <vector>
#include <queue>

#define INF INT32_MAX

using namespace std;
vector<pair<int, int>> v[801];
int n, e;
int startToFirst, startToSecond, firstToSecond, firstToEnd, secondToEnd;

struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

vector<int> dijikstra(int from)
{
    vector<int> ret(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (i == from)
        {
            ret[i] = 0;
        }
        else
        {
            ret[i] = INF;
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    q.push({from, 0});
    while (!q.empty())
    {
        pair<int, int> current = q.top();
        q.pop();
        for (int i = 0; i < v[current.first].size(); i++)
        {
            if (ret[v[current.first][i].first] > ret[current.first] + v[current.first][i].second)
            {
                ret[v[current.first][i].first] = ret[current.first] + v[current.first][i].second;
                q.push({v[current.first][i].first, ret[current.first] + v[current.first][i].second});
            }
        }
    }
    return ret;
}
int isPossibleFirstSecond()
{
    if (!(startToFirst == INF || secondToEnd == INF))
    {
        return 1;
    }
    else
        return 0;
}
int isPossibleSecondFirst()
{
    if (!(startToSecond == INF || firstToEnd == INF))
    {
        return 1;
    }
    else
        return 0;
}
int main()
{
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        v[from].push_back({to, weight});
        v[to].push_back({from, weight});
    }
    int first, second;
    cin >> first >> second;
    vector<int> start = dijikstra(1);
    vector<int> end = dijikstra(n);
    vector<int> fromFirst = dijikstra(first);
    startToFirst = start[first];
    startToSecond = start[second];
    firstToSecond = fromFirst[second];
    firstToEnd = end[first];
    secondToEnd = end[second];
    if (firstToSecond == INF || (!isPossibleFirstSecond() && !isPossibleSecondFirst()))
    {
        cout << -1 << endl;
    }
    else if (!isPossibleFirstSecond() && isPossibleSecondFirst())
    {
        cout << startToSecond + firstToSecond + firstToEnd << endl;
    }
    else if (isPossibleFirstSecond() && !isPossibleSecondFirst())
    {
        cout << startToFirst + firstToSecond + secondToEnd << endl;
    }
    else if (isPossibleFirstSecond() && isPossibleSecondFirst())
    {
        cout << min(startToFirst + firstToSecond + secondToEnd, startToSecond + firstToSecond + firstToEnd) << endl;
    }
}