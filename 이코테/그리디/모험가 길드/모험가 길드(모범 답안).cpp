#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int memberCount = 0; // 모험가의 수
    cin >> memberCount;
    vector<int> stats; // 공포도
    for (int i = 0; i < memberCount; i++)
    {
        int temp;
        cin >> temp;
        stats.push_back(temp);
    }
    sort(stats.begin(), stats.end()); // 올림차순으로 정렬
    int count = 0;  // 그룹에 포함될 모험가 수
    int result = 0; // 최종 그룹 수
    for (vector<int>::iterator iter = stats.begin(); iter != stats.end(); iter++)
    {
        count++;
        if(count >=*iter){
            result++;
            count = 0;
        }
    }
    cout << result;
}