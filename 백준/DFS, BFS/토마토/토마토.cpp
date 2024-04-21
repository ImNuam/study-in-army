#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int boxes[1000][1000];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<vector<pair<int, int>>> q;
int main()
{
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            boxes[i][j] = -1;
        }
    }
    int m, n;
    vector<pair<int, int>> start;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            boxes[i][j] = temp;
            if (temp == 1)
            {
                start.push_back({i, j});
            }
        }
    }
    q.push(start);
    int count = 0;
    while (!q.empty())
    {
        vector<pair<int, int>> head = q.front();
        q.pop();
        vector<pair<int, int>> tail;
        for (vector<pair<int, int>>::iterator iter = head.begin(); iter != head.end(); iter++)
        {
            int x = (*iter).first;
            int y = (*iter).second;
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if (boxes[nx][ny] == -1 || boxes[nx][ny] == 1)
                    continue;
                if (boxes[nx][ny] == 0)
                {
                    boxes[nx][ny] = 1;
                    tail.push_back({nx, ny});
                }
            }
        }
        if (!tail.empty())
        {
            q.push(tail);
            count++;
        }
    }
    for(int i=0; i<1000; i++){
        for(int j=0; j<1000; j++){
            if(boxes[i][j]==0){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << count << endl;
}