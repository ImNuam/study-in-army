#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int memberCount;   // 모험가 수
    vector<int> stats; // 공포도 그룹
    int count = 0;     // 답
    cin >> memberCount;
    for (int i = 0; i < memberCount; i++)
    {
        int temp = 0;
        cin >> temp;
        stats.push_back(temp);
    }
    sort(stats.begin(), stats.end());
    for (vector<int>::iterator iter = stats.begin(); iter != stats.end(); iter++)
    {
        int cnt = *iter; // 반복 횟수
        count++;
        while (cnt != 1)
        {
            cnt--;
            if (*(iter + 1) > (*iter))
                cnt = cnt + (*(iter + 1)) - (*iter);
            iter++;
            if (iter == stats.end())
            {
                iter--;
                count--;
                break;
            }
        }
    }
    cout << count;
}
// 매번 cnt로 확인
// 모범 답안 : 현재 그룹에 포함된 모험가의 수와 "현재 확인하고 있는 공포도"를 비교
