#include <stdio.h>

void bubbleSort(int arr[], int n){
    for (int i=0; i < n; i++){
        for (int j=0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                // swap
                arr[j] = arr[j] + arr[j+1];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j] = arr[j] - arr[j+1];
            }
        }
    }
}

int main(){
    int arr[] = {3, 1, 9, 8, 7, 2, 4, 10, 6, 5};
    int size = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, size);

    for(int i=0; i<size; i++){
        printf("%d", arr[i]);
    }

    return 0;
}
