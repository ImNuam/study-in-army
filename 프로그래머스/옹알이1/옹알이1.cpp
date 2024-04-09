#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> babbling)
{
    int answer = 0;
    vector<string> words = {"aya", "ye", "woo", "ma"};
    for (int i = 0; i < babbling.size(); i++)
    {
        string sentence = babbling[i];
        for (int k = 0; k < words.size(); k++)
        {
            string checking = sentence.substr(0, words[k].size());
            if(checking.compare(words[k])==0){
                sentence = sentence.substr(words[k].size(), sentence.size());
                k = -1;
            }
            continue;
        }
        if(sentence.size()==0) answer++;
    }
    return answer;
}
int main()
{
    vector<string> babbling = {"aya", "yee", "u", "maa", "wyeoo"};
    cout << solution(babbling) << endl;
}