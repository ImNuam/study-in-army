#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; //예산요청 개수
int total; //전체 예산 금액
vector<int> prices; //예산들을 모은 집합
int main(){
    int checkPricesInTotal=0;
    cin >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        prices.push_back(tmp);
        checkPricesInTotal+=tmp;
    }
    sort(prices.begin(), prices.end());
    int low=0;
    int high=prices[prices.size()-1];
    cin >> total;
    int result;
    if(total>=checkPricesInTotal){
        cout << high << endl;
        return 0;
    }
    else{
        while(low<=high){
            int mid=(low+high)/2;
            int sum=0;
            for(int i=0; i<prices.size(); i++){
                if(prices[i]<=mid){
                    sum+=prices[i];
                }
                else{
                    sum+=mid;
                }
            }
            if(sum>total){
                high=mid-1;
            }
            else{
                result = mid;
                low=mid+1;
            }
        }
        cout << result << endl;
    }
}