#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int cases;
    char tmp;
    string brackets;
    cin >> cases;
    for (int time = 0; time < cases; time++)
    {    
        stack<char> s;
        cin >> brackets;
        for (int i = 0; i < brackets.length(); i++)
        {
            if (brackets[i] == '(' || brackets[i] == '[' || brackets[i] == '{')
            {
                s.push(brackets[i]);
            }
            else if (brackets[i] != ')' && brackets[i] != '}' && brackets[i] != ']')
            {
                cout << "NO" << endl;
                break;
            }
            else{
                if(brackets[i]==')' && s.top()=='('){
                    s.pop();
                }
                if(brackets[i]=='}' && s.top()=='{'){
                    s.pop();
                }
                if(brackets[i]==']' && s.top()=='['){
                    s.pop();
                }
            }
        }
        if(s.empty()){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}