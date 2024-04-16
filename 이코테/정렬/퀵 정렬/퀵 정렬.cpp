#include <iostream>
#include <algorithm>
using namespace std;
void quickSort(int (&array)[10], int index, int end)
{
    if(index>=end) return;
    bool isChanged = false;
    int& pivot = array[index];
    while(!isChanged){
        int i =0, j=end;
        while(i<=end && array[i]<=pivot) i++;
        while(j>0 && array[j]>pivot) j--;
        if(i<j) swap(array[i], array[j]);
        else{
            swap(array[j], pivot);
            isChanged=true;
            quickSort(array, 0, j-1);
            quickSort(array, j+1, end);
        }
    }
}
int main()
{
    int array[] = {5, 7, 9, 0, 3, 1, 6, 2, 4, 8};
    quickSort(array, 0, 9);
    for(int i=0; i<10; i++){
        cout << array[i]<< endl;
    }
}