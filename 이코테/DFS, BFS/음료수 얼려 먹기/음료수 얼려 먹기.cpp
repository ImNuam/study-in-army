#include <iostream>
#include <vector>
using namespace std;

void checkIceCream(vector<vector<int>> container, int row, int column, vector<vector<bool>>& visited){
    visited[row][column]=true;
    if(column>0 &&container[row][column-1] == 0 && !visited[row][column-1]) checkIceCream(container, row, column-1, visited);
    if(column+1<container[row].size() && container[row][column+1]==0 && !visited[row][column+1]) checkIceCream(container, row, column+1, visited);
    if(row>0 && container[row-1][column]==0 && !visited[row-1][column]) checkIceCream(container, row-1, column, visited);
    if(row+1<container.size() && container[row+1][column] ==0 && !visited[row+1][column]) checkIceCream(container, row+1, column, visited);
}

int iceCreamCount(vector<vector<int>> container, vector<vector<bool>> visited){
    int count =0;
    for(int i = 0; i<container.size(); i++){
        for(int j=0; j<container[i].size(); j++){
            if( container[i][j] == 0 && !visited[i][j]) {checkIceCream(container, i, j, visited); count++;}
        }
    }
    return count;
}
int main(){
    int row, column;
    cin >> row >> column;
    vector<vector<int>> iceContainer;
    vector<vector<bool>> visited;
    for(int i = 0; i < row; i++){
        iceContainer.push_back(vector<int>(column));
        visited.push_back(vector<bool>(column));
        for(int j=0; j < column; j++){
            int input;
            cin >> input;
            if(input>1 || input<0) return 0;
            iceContainer[i][j]=input;
            if(input ==1) visited[i][j] = true;
            else if (input == 0 ) visited[i][j] = false;
        }
    }

    cout << iceCreamCount(iceContainer, visited) << endl;

}