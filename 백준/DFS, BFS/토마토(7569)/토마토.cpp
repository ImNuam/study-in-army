#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
struct coordinate
{
    int x;
    int y;
    int z;
};
int m, n, h; // m이 가로, n이 세로, h가 높이
int tomatoes[101][101][101];
queue<coordinate> q;
int count = 1;
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

void bfs(int x, int y, int z)
{

    for (int i = 0; i < 6; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        int nz = z + dz[i];
        if (nx < 0 || nx >= m)
            continue;
        if (ny < 0 || ny >= n)
            continue;
        if (nz < 0 || nz >= h)
            continue;
        if (tomatoes[nx][ny][nz] == 0)
        {
            tomatoes[nx][ny][nz] = 1;
            q.push({nx, ny, nz});
        }
    }
}

int main()
{
    memset(tomatoes, -1, sizeof(tomatoes));
    cin >> m >> n >> h;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> tomatoes[k][j][i];
                if (tomatoes[k][j][i] == 1)
                {
                    q.push({k, j, i});
                }
            }
        }
    }

    int count = 0;
    while (!q.empty())
    {
        int len=q.size();
        for (int i = 0; i < len; i++)
        {
            coordinate tmp = q.front();
            q.pop();
            bfs(tmp.x, tmp.y, tmp.z);
        }
        count++;
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (tomatoes[k][j][i] == 0)
                {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << count-1 << endl;
    return 0;
}