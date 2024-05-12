#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;  // n은 집 개수, c는 공유기 개수
int m = 0; // 최소값
int s, e;
vector<int> v;
vector<int> check;
int search(int first, int last)
{
    int mid = (v[last] - v[first]) / 2; // 기준값
    int idx = (last - first) / 2;
    do
    {
        if ( idx> 0&& abs(mid - v[idx]) > abs(mid - v[idx - 1]))
        {
            idx--;
            continue;
        }
        if ( idx < v.size()-1 && abs(mid - v[idx]) > abs(mid - v[idx + 1]))
        {
            idx++;
            continue;
        }
        break;
    } while (1);
    return idx;
}

int main()
{

    int result = 1e9 + 1;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for (int i = 2; i <= c; i++)
    {
        if (i == 2)
        {
            check.push_back(0);
            check.push_back(v.size() - 1);
            result = v[v.size()-1]-v[0];
        }
        else
        {
            int checkidx;
            for (int i = 0; i < check.size() - 1; i++)
            {
                int temp = search(check[i], check[i + 1]);
                int temp2;
                if ((temp2 = min(abs(v[temp]-v[check[i]]), abs(v[check[i+1]]-v[temp])))< result)
                {
                    checkidx = temp;
                    result = temp2;
                }
            }
            check.push_back(checkidx);
            sort(check.begin(), check.end());
        }
    }
    cout << result;
}