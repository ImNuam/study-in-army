#include <iostream>
#include <vector>
using namespace std;

int n, m;          // n : 나무의 수, m : 필요한 나무의 길이
vector<int> trees; // 제곧내
int main()
{
    cin >> n >> m;
    int last = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if (last < tmp)
        {
            last = tmp;
        }
        trees.push_back(tmp);
    }
    int start = 0;
    long long mid, result;
    while (start <= last)
    {
        mid = (start + last) / 2;
        long long cut = 0;
        for (int i = 0; i < n; i++)
        {
            if (trees[i] - mid >= 0)
            {
                cut += trees[i] - mid;
            }
        }
        if (cut < m)
        { // 부족하면 더 내린다
            last = mid-1;
        }
        else
        {
            result=mid;
            start = mid+1;
        }
    }
    cout << result << endl;
}