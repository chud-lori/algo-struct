#include <iostream>

using namespace std;
namespace sorting{
    void printArray(int arr[], int size){
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void swap(int *x, int *y){
        int temp = *x;
        *x = *y;
        *y = temp;
    }
}
