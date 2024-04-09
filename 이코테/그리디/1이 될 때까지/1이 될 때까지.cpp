#include <iostream>

using namespace std;
int main(){
    int n, k; //n이 1로 만들 놈, k가 나눌 때 쓸 놈
    cin >> n >> k;
    int cnt = 0;
    while(n!=1){
        if(n%k!=0) n-=1;
        else n/=k;
        cnt++;
    }
    cout << cnt<< endl;
}