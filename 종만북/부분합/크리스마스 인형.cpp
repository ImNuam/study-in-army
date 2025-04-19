#include <iostream>
#include <vector>
using namespace std;
int C;
int main(){
    cin >> C;
    for(int i=0; i<C; i++){
        int N, K;
        cin >> N >> K;
        vector<int> boxes(K);
        for(int j=0; j<N; j++){
            int tmp;
            cin >> tmp;
            boxes.push_back(tmp);
        }
        vector<int> psum(K);
        psum[0]=boxes[0];
        for(int j=1; j<N; j++){
            psum[j]=boxes[j]+psum[j-1];
        }
        int answer1=0;
        for(int j=0; j<N; j++){
            for(int k=0; k<j; k++){
                if(k==0){
                    if(psum[j]%K==0) answer1++;
                }
                else{
                    if((psum[j]-psum[k-1])%K==0) answer1++;
                }
            }
        }
        
    }
}