#include <iostream>
#include<vector>
using namespace std;


int m, n; //m은 사람 수, n은 파티 수
int alreadyKnowCount; //원래 알던 사람 수
int know[51]={0, }; //아는 사람들
vector<vector<int>> party;
int main(){
    cin >> m >> n; 
    cin >> alreadyKnowCount;
    
    for(int i=0; i<alreadyKnowCount; i++){
        int tmp;
        cin >> tmp;
        know[tmp]=1;
    }
    for(int i=0; i<n; i++){
        int cnt;
        cin >> cnt;
        party.push_back(vector<int>(cnt+1));
        for(int j=1; j<=cnt; j++){
            int person;
            cin >> person;
            party[i][j]=person;
        }
    }
    int ret=0;
    for(int t=0; t<n; t++){
    for(int i=0; i<n; i++){
        for(int j=1; j<party[i].size(); j++){
            if(know[party[i][j]]==1){
                for(int k=1; k<party[i].size(); k++){
                    know[party[i][k]]=1;
                }
            }
        }
    }
    }
    
    for(int i=0; i<n; i++){
        for(int j=1; j<party[i].size(); j++){
            if(know[party[i][j]]==1){
                break;
            }
            if(j==party[i].size()-1) ret++;
        }
        
    }
    cout << ret << endl;
}