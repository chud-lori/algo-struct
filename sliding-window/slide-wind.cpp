#include <iostream>
#include <algorithm>

using namespace std;

int findMax(int arr[], int lenarr, int k) {
    int maxVal = INT_MIN;
    int currentRunningSum = 0;

    int arrlength = lenarr;

    for (int i=0; i < arrlength; i++) {
        currentRunningSum += arr[i];
        cout << "i outside" << i << endl;
        if (i >= k - 1) {
            cout << "i inside" << i << endl;
            maxVal = std::max(maxVal, currentRunningSum);
            currentRunningSum -= arr[i - (k-1)];
        }
    }
    return maxVal;
}

int main(){
    int arr[10] = {4, 2, 1, 7, 8, 1, 2, 8, 1, 0}; // array data
    int k = 3; // jumlah urutan
    int lenarr = sizeof(arr)/sizeof(arr[0]);

    cout << findMax(arr, lenarr, k) << endl;


    return 0;
}
