#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first < b.first;
    }
} compPair;

struct cmpInt
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int n, k;
priority_queue<int, vector<int>, less<int>> q;
vector<pair<int, int>> gems;
vector<int> bags;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int w, v;
        cin >> w >> v;
        gems.push_back({w, v});
    }
    for (int i = 0; i < k; i++)
    {
        int w;
        cin >> w;
        bags.push_back(w);
    }
    sort(bags.begin(), bags.end());
    sort(gems.begin(), gems.end(), compPair);
    long long max = 0;

    int j = 0;

    for (int i = 0; i < bags.size(); i++)
    {
        while (j < gems.size() && bags[i] >= gems[j].first)
        {
            q.push(gems[j].second);
            j++;
        }
        if(!q.empty()){
        max += q.top();
        q.pop();
        }
    }

    std::cout << max << endl;
}