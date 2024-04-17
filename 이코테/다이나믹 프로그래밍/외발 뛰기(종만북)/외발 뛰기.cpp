#include <iostream>
#include <vector>
using namespace std;
/*
bool jump(int y, int x){ //재귀 알고리즘(메모이제이션을 안 쓴 버전)
    //기저 사례 1. 게임판을 벗어난 경우
    if(y>=n|| x>=n) return false;
    //기저 사례 2. 마지막 칸에 도착한 경우
    if(y==n-1 && x==n-1) return true;
    int jumpSize=board[x][y];
    return jump(y+jumpSize, x) || jump(y, x+jumpSize);
}
*/
bool jump(vector<vector<int>> board, vector<vector<int>> cache, int x, int y)
{
    int n = board.size();
    if (x >= n || y >= n)
        return false;
    if (x == n - 1 && y == n - 1)
        return true;
    // 메모이제이션
    int &ret = cache[x][y];
    if (ret != -1)
        return ret;
    int jumpSize = board[x][y];
    return ret = ((jump(board, cache, x + jumpSize, y) || jump(board, cache, x, y + jumpSize)));
}
int main()
{
    cin.sync_with_stdio(false);
    int test;
    cin >> test;
    vector<vector<vector<int>>> board(test);
    vector<vector<vector<int>>> cache(test);
    for (int i = 0; i < test; i++)
    {
        int size;
        cin >> size;
        for (int j = 0; j < size; j++)
        {
            board[i].push_back(vector<int>(size));
            cache[i].push_back(vector<int>(size, -1));
            for (int k = 0; k < size; k++)
            {
                int input;
                cin >> input;
                board[i][j][k] = input;
            }
        }
    }
    for (int i = 0; i < test; i++)
    {
        if(jump(board[i],cache[i], 0, 0)) cout <<"YES"<<endl;
        else cout <<"NO" <<endl;
    }
}