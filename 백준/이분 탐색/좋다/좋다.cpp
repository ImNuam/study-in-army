#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n; //수의 개수
vector<int> v; //수를 넣을 벡터
int main(){

    cin >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int ret=0;
    for(int i=0; i<v.size(); i++){
        int lo=0, hi=v.size()-1;
        while(lo<hi){
            int check=v[lo]+v[hi];
            if(check==v[i]){
                if(i!=hi && i!=lo){
                ret++;
                break;
                }
                else if(lo==i) lo++;
                else if(hi==i) hi--;
            }
            else if(check<v[i]){
                lo++;
            }
            else{
                hi--;
            }
        }
    }
    cout << ret;
}