#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    string s;
    cin >> s;
    int col = s[0] - 'a' + 1;
    int row = s[1]-'0';
    //오른쪽 위부터 차례로
    vector<int> dcol = {1, 2, 2, 1, -1, -2, -2, -1};
    vector<int> drow = {-2, -1, 1, 2, 2, 1, -1, -2};
    int count = 0;
    for(int i = 0; i< 8; i++){
        int ncol = col + dcol[i];
        int nrow = row + drow[i];
        if(ncol<1 || ncol>8 || nrow<1 || nrow>8) continue;
        count++;
    }
    cout << count << endl;
}