#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int n, m;
int stage[8][8];
int check[8][8];
int virus[64][2];
int num = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int>> q;
int canBlock(int i)
{
    if (stage[i / m][i % m] == 0)
    {
        return 1;
    }
    else
        return 0;
}
void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny < m && ny >= 0 && check[nx][ny] == 0)
        {
            check[nx][ny] = 2;
            dfs(nx, ny);
        }
    }
}
int block(int i, int j, int k)
{
    int ret = 0;
    if (canBlock(i) && canBlock(j) && canBlock(k))
    {
        memcpy(check, stage, sizeof(stage));
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < m; y++)
            {

                check[i / m][i % m] = 1;
                check[j / m][j % m] = 1;
                check[k / m][k % m] = 1;
                for (int l = 0; l < num; l++)
                {
                    dfs(virus[l][0], virus[l][1]);
                }
            }
        }
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < m; y++)
            {
                if (check[x][y] == 0)
                {
                    ret++;
                }
            }
        }
        return ret;
    }
    else
        return 0;
}

int main()
{
    cin >> n >> m;
    int result = 0;
    memset(stage, -1, sizeof(stage));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> stage[i][j];
            if (stage[i][j] == 2)
            {
                virus[num][0] = i;
                virus[num][1] = j;
                num++;
            }
        }
    }
    for (int i = 0; i < n * m - 2; i++)
    {
        for (int j = i + 1; j < n * m - 1; j++)
        {
            for (int k = j + 1; k < n * m; k++)
            {
                result = max(result, block(i, j, k));
            }
        }
    }
    cout << result << endl;
}
