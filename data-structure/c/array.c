#include <stdio.h>
#define ROW 10
#define COL 5

int main(void) {

    int oned_arr[ROW] = {0,1,2,3,4,5,6,7,8,9};

    printf("1D Array\n");
    for(int i=0; i < ROW; i++) {
        printf("%d", oned_arr[i]);
    }
    printf("\n\n");

    printf("2D Array\n");
    //int twod_arr[5][2] = {{1,2}, {3,4}, {5,6}, {7,8}, {9,0}};
    int twod_arr[ROW][COL];

    for(int i=0; i < ROW; i++) {
        for(int j=0; j < COL; j++) {
            twod_arr[i][j] = '.';
            printf("%c" , twod_arr[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    return 0;

}

