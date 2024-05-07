#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> v;

int exec(int x, int y, int z)
{
    
}

int zigzag()
{
    int ret = 0;
    for (int a = 1; a < v.size(); a++)
    {
        int max = 0;
        for (int b = 1; b < v.size(); b++)
        {
            for (int c = b; c < v.size(); c++)
            {
                int check = exec(a, b, c);
                if (max < check)
                    max = check;
            }
        }
        ret += max;
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    cout << zigzag() << endl;
}