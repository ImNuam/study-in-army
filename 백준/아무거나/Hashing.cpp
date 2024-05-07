#include <iostream>
using namespace std;

long long square(int a, int n){
    long long result=1;
    for(int i=0; i<n; i++){
        result*=a;
        result %= 1234567891;
    }
    return result;
}
int main(){
    int count;
    cin >> count;
    char string[51];
    for(int i=0; i<count; i++){
        cin >> string[i];
    }
    long long result = 0;
    for(int i=0; i<count; i++){
        result+=((string[i]-'a'+1) * square(31, i));
        result %= 1234567891;
    }
    cout << result;
}