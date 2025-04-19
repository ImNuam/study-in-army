#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <cfloat>
#include <deque>

using namespace std;
class Solution {
public:
    bool isHappy(string check, char letter){
        int count =0;
        if(check.size()<3){
            return true;
        }
        for(int i=0; i<3; i++){
            if(check[i]==letter){
                count++;
            }
        }
        if(count==3) return false;
        else return true;
    }
    string longestDiverseString(int a, int b, int c) {
        string ret="";
        if(a>0){
            string check1=longestDiverseString(a-1, b, c);
            string check2 = 'a' + check1;
            if(isHappy(check2, 'a') && ret.size()<check2.size()){
                ret=check2;
            }
            else if(ret.size()<check1.size()) ret=check1;
        }
        if(b>0){
            string check1=longestDiverseString(a, b-1, c);
            string check2 = 'b'+ check1;
            if(isHappy(check2, 'b') && ret.size()<check2.size()){
                ret=check2;
            }
            else if(ret.size()<check1.size()) ret=check1;
        }
        if(c>0){
            string check1=longestDiverseString(a, b, c-1);
            string check2 = 'c' + check1;
            if(isHappy(check2, 'c') && ret.size() < check2.size()){
                ret=check2;
            }
            else if(ret.size()<check1.size()) ret=check1;
        }
        return ret;
    }
};
int main()
{
    
    Solution solution;
    vector<int> a={3,1,4,2};
    int p = 6;
    cout << solution.longestDiverseString(1,1,7) << endl;
}

class AllOne {
public:
    unordered_map<string, int> keyToCount;
    unordered_map<int, string> countToKey;
    AllOne() {
        
    }
    
    void inc(string key) {
        if (keyToCount.find(key) != keyToCount.end()) {
            keyToCount[key]++;
            countToKey[keyToCount[key]] = key;
        } else {
            keyToCount[key] = 1;
            countToKey[1]=key;
        }
    }

    
    void dec(string key) {
        
    }
    
    string getMaxKey() {
        
    }
    
    string getMinKey() {
        
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */