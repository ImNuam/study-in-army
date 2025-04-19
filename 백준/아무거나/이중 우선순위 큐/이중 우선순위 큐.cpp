//문제 제출할 때에는 시간 초과를 피하기 위해 optional을 사용하지 않음
#include <vector>
#include <optional>
#include <iostream>
#include <set>

using namespace std;

int T;
vector<optional<pair<int,int>>> results;
int findMax(multiset<int> my_set) 
{ 
 
    // Get the maximum element 
    int max_element; 
    if (!my_set.empty()) 
        max_element = *(my_set.rbegin()); 
 
    // return the maximum element 
    return max_element; 
}
int findMin(multiset<int> my_set) 
{ 
 
    // Get the minimum element 
    int min_element; 
    if (!my_set.empty()) 
        min_element = *my_set.begin(); 
 
    // return the minimum element 
    return min_element; 
} 

optional<pair<int ,int>> operate(int k){
    char op;
    multiset<int> ms;
    for(int i=0; i<k; i++){
        cin >> op;
        if(op=='I'){
            int temp;
            cin >> temp;
            ms.insert(temp);
        }
        else if(op=='D'){
            int temp;
            cin >> temp;
            if(!ms.empty()){
                if(temp==1){
                    ms.erase(findMax(ms));
                }
                else{
                    ms.erase(findMin(ms));
                }
            }
        }
    }
    if(ms.empty()){
        return std::nullopt;
    }
    else{
        return make_pair(findMax(ms), findMin(ms));
    }
}

int main(){
    ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
    cin>>T;
    for(int i=0; i<T; i++){
        int k;
        cin >> k;
        results.push_back(operate(k));
    }
    for(int i=0; i<results.size(); i++){
        if(results[i].has_value()){
            cout<< results[i].value().first << " " << results[i].value().second << endl;
        }
        else{
            cout <<"EMPTY" << endl;
        }
    }
}