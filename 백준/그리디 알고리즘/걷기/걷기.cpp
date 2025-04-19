#include <iostream>

using namespace std;

int main(){
    long long destx, desty; //목적지의 x좌표 y좌표
    long long w, s; // 걸어서 w, 대각선 s
    cin >> destx >> desty >> w>> s;
    if(s>=2*w){
        cout << w*(destx+desty);
    }
    else{
        if((destx+desty)%2==0){
            cout << min(max(destx,desty)*s, min(destx,desty)*s + abs(destx-desty)*w);
        }
        else{
            cout << min(min(destx, desty)*s + abs(destx-desty)*w, (max(destx, desty)-1)*s+w);
        }
    }
}
