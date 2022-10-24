#include <iostream>
//#include <algorithm>
#include "sorting.hpp"
using namespace std;


void selectionSort(int arr[], int n){
    int minIndex = INT_MIN;

    for(int i=0; i < n; i++){
        for(int j=i+1; j < n; j++){
            if(arr[i] < arr[j]){
                minIndex = i;
            }
        }
        // swap
        sorting::swap(&arr[i], &arr[minIndex]);
    }
}


int main(){
    int arr[] = {3, 1, 9, 8, 7, 2, 4, 10, 6, 5};
    int lenarr = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, lenarr);
    sorting::printArray(arr, lenarr);

    return 0;
}
