#include <iostream>
#include <queue>
using namespace std;

struct cmp{
    bool operator()(long long a, long long b){
        return a > b;
    }
};

priority_queue<long long, vector<long long>, cmp> q;
int n;
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }
    int sum=0;
    while(q.size()>1){
        int a=q.top();
        q.pop();
        int b=q.top();
        q.pop();
        sum+=a+b;
        q.push(a+b);
    }
    cout << sum;
}