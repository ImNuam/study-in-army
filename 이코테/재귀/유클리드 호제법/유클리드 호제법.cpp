#include <iostream>
using namespace std;
int gcd(int input1, int input2)
{
    if (input1 % input2 == 0)
    {
        return input2;
    }
    else
    {
        return gcd(input2, input1 % input2);
    }
}
int main()
{
    int input1, input2;
    cin >> input1 >> input2;
    cout << gcd(input1, input2) << endl;
}