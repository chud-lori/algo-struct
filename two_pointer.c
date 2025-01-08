#include <stdio.h>
#include <stdbool.h>


// function prototype
int naive(int arr[], int size, int val);
bool tp(int arr[], int size, int val);


int main(void) {
    int arr[] = {10, 20, 35, 50, 75, 80};
    int size = sizeof(arr) / sizeof(arr[0]);

    tp(arr, size, 30);

    return 0;


}

int naive(int arr[], int size, int val) {
    for(int i=0; i < size; i++) {
        for(int j=0; j < size; j++) {

            // as equal i and j means same element
            if(i == j) {
                continue;
            }

            // pair exists
            if ((arr[i] + arr[j]) == val) {
                return arr[i] + arr[j];
            }

            if (arr[i] + arr[j] > val) {
                break;
            }
        }
    }

    return 0;
}

// two pointer used to find sum pair
bool tp(int arr[], int size, int val) {
    // first pointer
    int i = 0;
    // second pointer
    int j = size - 1;

    while (i < j) {
        int sum_arr = arr[i] + arr[j];
        // if we find a pair
        if (sum_arr == val) {
            printf("found: %d %d\n", arr[i], arr[j]);
            return true;
        }
        // if sum of element of current pointer  is less, move higher value by increase i++
        else if (sum_arr < val) {
            i += 1;
        }
        // if sum of element of current pointer is more, move lower value by decrease j--
        else {
            j -= 1;
        }

    }

    return false;

}
