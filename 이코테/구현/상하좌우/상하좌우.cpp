#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int x = 1; // 시작 행
    int y = 1; // 시작 열
    int n = 0; // 공간 크기(정사각형 크기)
    cin >> n;
    vector<char> plan; // 움직이는 계획
    char * s;
    cin.getline(s);// string 받고 나눠야됨

    for (vector<char>::iterator iter = plan.begin(); iter != plan.end(); iter++)
    {
        switch (*iter)
        {
        case 'L':
            if(y>1) y-1; break;
        case 'R':
            if(y<n) y+1; break;
        case 'U':
            if(x>1) x-1;  break;
        case 'D':
            if(x<n) x+1; break; 
        }
    }
    cout << x << ' ' << y << endl;
}