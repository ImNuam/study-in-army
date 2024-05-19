#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n;
int board[15][15];
int temp[15][15];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int dfs(pair<int, int> queen, int original[15][15], int count)
{
    if(queen.first>=n || queen.second >=n){
        return 0;
    }
    if (count == n)
    {
        return 1;
    }
    else
    {
        int temp[15][15];
        memcpy(temp, original, sizeof(temp));
        int ret = 0;
        for (int i = 0; i < 8; i++)
        {
            int x = queen.first;
            int y = queen.second;
            while (x >= 0 && y >= 0 && temp[x][y] != -1)
            {
                temp[x][y] = 1;
                x += dx[i];
                y += dy[i];
            }
        }
        for (int k = 0; k < n; k++)
        {   
            if(temp[k][count]==0)
                ret += dfs({k, count}, temp, count + 1);
             
        }
        return ret;
    }
}

int main()
{
    memset(board, -1, sizeof(board));
    memset(temp, -1, sizeof(temp));
    cin >> n;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        
            result+=dfs({i, 0}, board, 1);
        
    }
    cout <<result;
}