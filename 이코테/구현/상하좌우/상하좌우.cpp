#include <vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    int x = 1; // 시작 행
    int y = 1; // 시작 열
    int n = 0; // 공간 크기(정사각형 크기)
    cin >> n;
    cin.ignore();
    vector<char> plan; // 움직이는 계획
    do {
        char ch;
        cin >> ch;
        plan.push_back(ch);
        
    }while(getc(stdin)==' ');
    for (vector<char>::iterator iter = plan.begin(); iter != plan.end(); iter++)
    {
        char check = *iter;
        switch (check)
        {
        case 'L':
            if(y>1) y=y-1; continue;
        case 'R':
            if(y<n) y=y+1; continue;
        case 'U':
            if(x>1) x=x-1;  continue;
        case 'D':
            if(x<n) x=x+1; continue;
        }
    }
    std::cout << x << ' ' << y << endl;
}