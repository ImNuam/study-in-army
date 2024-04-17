#include <iostream>
#include <vector>
#include <string.h>
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
int board[100][100];
int cache[100][100];
bool jump(int x, int y, int n)
{
    
    if (x >= n || y >= n)
        return false;
    if (x == n - 1 && y == n - 1)
        return true;
    // 메모이제이션
    int& ret = cache[x][y];
    if (ret != -1)
        return ret;
    int jumpSize = board[x][y];
    return ret = ((jump(x + jumpSize, y, n) || jump(x, y + jumpSize, n)));
}
int main()
{
    cin.sync_with_stdio(false);
    int test;
    cin >> test;
    vector<string> s;
    memset(cache, -1, 40000);
    for (int i = 0; i < test; i++)
    {
        int size;
        cin >> size;
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                cin >> board[j][k];
            }
        }
        if(jump(0, 0, size)) s.push_back("YES");
        else s.push_back("NO");
    }
    for(int i=0; i<s.size(); i++){
        cout << s[i] << endl;
    }
}