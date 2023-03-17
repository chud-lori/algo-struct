#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int arr[], int n){
    int i, j;

    for (i = 0; i < n - 1; i++){
        // Last i element are already in place
        for(j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]) {
                // swap
                arr[j] = arr[j] + arr[j + 1];
                arr[j + 1] = arr[j] - arr[j + 1];
                arr[j] = arr[j] - arr[j + 1];
            }
        }
    }
}

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    int arr[] = {3, 1, 9, 8, 7, 2, 4, 10, 6, 5};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Unsorted array: ";
    printArray(arr, size);

    // sorting
    bubbleSort(arr, size);
    cout << endl;

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
