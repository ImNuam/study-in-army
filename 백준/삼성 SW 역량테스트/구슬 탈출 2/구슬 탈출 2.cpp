/*
문제 해결 방안
1. 판을 이차원 배열 char 형으로 받는다.
2. 최소 횟수를 구해야 하니까 너비 탐색 쓰자.
3. 큐로 탐색할 놈들을 입력받는다.
4. 탐색할 때마다 for문 돌리는 걸로
*/
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
char board[10][10];


queue<pair<pair<int, int>, pair<int, int>>> q;
set<pair<pair<int, int>, pair<int, int>>> s;
pair<int, int> hole;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int t;

void move(pair<int, int> red, pair<int, int> blue, int d)
{
    bool putR = false; // 공이 들어갔는가?
    bool putB = false;

    while (1)
    {
        bool moved = false;
        pair<int, int> nextR = {red.first + dx[d], red.second + dy[d]};
        if (board[nextR.first][nextR.second] != '#' && (nextR != blue || putR))
        {
            red = nextR;
            moved = true;
            if (red == hole)
                putR = true;
        }
        pair<int, int> nextB = {blue.first + dx[d], blue.second + dy[d]};
        if (board[nextB.first][nextB.second] != '#' && (nextB != red || putR))
        {
            blue = nextB;
            moved = true;
            if (blue == hole)
                putB = true;
        }
        if (!moved)
        {
            break;
        }
    }
    if (putR && !putB)
    {
        cout << t << endl;
        exit(0);
    }
    if (!putB&& s.find({red, blue}) == s.end())
    {
        q.push({red, blue});
        s.insert({red, blue});
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    pair<int, int> red, blue;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
                red = {i, j};
            if (board[i][j] == 'B')
                blue = {i, j};
            if (board[i][j] == 'O')
                hole = {i, j};
        }
    }
    q.push({red, blue});
    for (t = 1; t <= 10; t++)
    {

        for (int len = q.size(); len > 0; len--)
        {
            pair<int, int> nRed;
            pair<int, int> nBlue;

            nRed = q.front().first;
            nBlue = q.front().second;
            q.pop();
            for (int dir = 0; dir < 4; dir++)
            { // 상하좌우 순으로 ㄱㄱ

                move(nRed, nBlue, dir);
            }
        }
        if (t == 10)
        {
            cout << -1 << endl;
            return 0;
        }
    }
}
