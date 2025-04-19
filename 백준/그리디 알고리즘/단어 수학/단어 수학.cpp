#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
vector<string> words;
vector<int> lens;
map<char, int> m;
int n;
priority_queue<int> q;
struct
{
    bool operator()(string a, string b)
    {
        return a.length() < b.length();
    }
} cmp;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        words.push_back(tmp);
    }
    sort(words.begin(), words.end(), cmp);
    for(int i=0; i<words.size(); i++){
        for(int j=0; j<words[i].length(); j++){
            if(m.find(words[i][j])==m.end()){
                m[words[i][j]]=pow(10, words[i].length()-j-1);
                
            }
            else{
                m[words[i][j]]+=pow(10, words[i].length()-j-1);
            }
        }
    }

    int sum=0;
    int num=9;
    for(map<char, int>::iterator iter=m.begin(); iter!=m.end(); iter++){
        q.push((*iter).second);
    }
    while(!q.empty()){
        sum+=num*q.top();
        q.pop();
        num--;
    }
    cout << sum;
}