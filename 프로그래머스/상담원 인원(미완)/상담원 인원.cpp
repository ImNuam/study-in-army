#include <string>
#include <vector>

using namespace std;

int solution(int k, int n, vector<vector<int>> reqs)
{
    int answer = 0;
    // 유형별 멘토를 하나씩 만든다.
    vector<int> mentos;
    for (int i = 0; i <= k; i++)
    {
        mentos[i] = 1;
    }
    // 유형별로 데이터를 구분한다.
    vector<vector<vector<int>>> mentis;
    for (vector<vector<int>>::iterator iter = reqs.begin(); iter != reqs.end(); iter++)
    {
        vector<int> menti = {0,}; //임시 방편
        mentis[(*iter)[2]-1].push_back({1,2,3}); //임시 방편
    } 
    // 유형별로 하나만 있을 때의 대기시간을 확인한다. 가장 긴 대기 시간을 갖고 있는 유형에게 인원을 주고 다시 대기 시간을 비교한다.

    return answer;
}