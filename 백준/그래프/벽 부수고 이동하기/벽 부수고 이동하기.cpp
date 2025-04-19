#include <iostream>
#include <cstring>

using namespace std;

int table[1002][1002];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int fn(int x, int y, bool didBreak)
{
}

int bfs(int x, int y){
    
}

int main()
{
    memset(table, -1, sizeof(table));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%1d", &table[i][j]);
        }
    }
    
}