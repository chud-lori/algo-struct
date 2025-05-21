#include <stdio.h>

void printMatrix(int matrix[4][4], int n, int m) {
    printf("Adjacency Matrix:\n");
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printConnections(int matrix[4][4], int n, int m, char vertex[4], int v) {
    printf("Connections for each vertex:\n");
    for(int i = 0; i < v; ++i) {
        printf("%c: ", vertex[i]);
        for(int j = 0; j < v; ++j) {
            if (matrix[i][j]) {
                printf("%c ", vertex[j]);
            }
        }
        printf("\n");
    }
}

int main() {
    char vertex[4] = {'A', 'B', 'C', 'D'};
    int matrix[4][4] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 0},
        {1, 0, 0, 0}
    };

    printMatrix(matrix, 4, 4);
    printConnections(matrix, 4, 4, vertex, 4);

    return 0;
}
