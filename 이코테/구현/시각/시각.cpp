#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int time = n*3600 + 59*60+59;
    int cnt= 0;
    for(int i = 0 ; i<=time; i++){
        if((i/3600)%10==3 || ((i%3600)/60)%10==3 || ((i%3600)/60)/10==3 || ((i%3600)%60)/10==3 || ((i%3600)%60)%10==3) cnt++;
    }
    cout << cnt;
}