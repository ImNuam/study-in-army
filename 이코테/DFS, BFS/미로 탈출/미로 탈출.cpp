#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int maze[200][200];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp;
            scanf("%1d", &temp);
            maze[i][j] = temp;
        }
    }
    queue<pair<int, int>> q;
    pair<int, int> start(0, 0);
    q.push(start);
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int prev = 1;
    for (int count = 1;; count++)
    {
        int j = prev;
        prev = 0;
        for (int i = 0; i < j; i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            if (x == n - 1 && y == m - 1)
            {
                cout << count << endl;
                return 0;
            }
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                else if (maze[nx][ny] == 1)
                {
                    q.push({nx, ny});
                    prev++;
                    maze[nx][ny]=0;
                }
            }
            // }
            // if (x > 0 && maze[x - 1][y] == 1)
            // {
            //     q.push(pair<int, int>(x - 1, y));
            //     prev++;
            // }
            // if (y < m - 1 && maze[x][y + 1] == 1)
            // {
            //     q.push(pair<int, int>(x, y + 1));
            //     prev++;
            // }
            // if (x < n - 1 && maze[x + 1][y] == 1)
            // {
            //     q.push(pair<int, int>(x + 1, y));
            //     prev++;
            // }
            // if (y > 0 && maze[x][y - 1] == 1)
            // {
            //     q.push(pair<int, int>(x, y - 1));
            //     prev++;
            // }
            // maze[x][y] = 0;
            q.pop();
        }
    }
}
