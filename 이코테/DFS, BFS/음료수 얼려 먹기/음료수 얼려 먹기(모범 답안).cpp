/*
내가 고칠 점들
1. 일단 전역 변수 혐오를 코테할 때는 잠시 내려두자
    인자의 개수를 줄이기 위해 필수적인 것 같다.
2. 합칠 수 있는 조건들, 변수들은 합치자(ex. visited나 조건들)

*/

#include <iostream>
using namespace std;

int n, m;
int graph[1001][1001];

bool dfs(int x, int y)
{
    if (x <= -1 || x >= n || y <= -1 || y >= m)
    {
        return false;
    }
    if (graph[x][y] == 0)
    {
        graph[x][y] = 1;
        dfs(x - 1, y);
        dfs(x + 1, y);
        dfs(x, y - 1);
        dfs(x, y + 1);
        return true;
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &graph[i][j]);
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dfs(i, j))
            {
                result += 1;
            }
        }
    }
    cout << result << endl;
}