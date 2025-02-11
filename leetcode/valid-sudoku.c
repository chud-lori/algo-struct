#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    //so instead of storing the real number like in python, in c it represents by 1 in 8 bits integer, so it checks based on position in the bits
    //
    int rows[9] = {0};    // Track numbers in each row
    int cols[9] = {0};    // Track numbers in each column
    int boxes[9] = {0};   // Track numbers in each 3x3 box

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                continue;
            }

            // convert to zero based (0-8)
            int val = board[i][j] - '1';
            // shift the 1 based on val
            // 1 << 4 --> 10000
            int mask = 1 << val;
            int box_idx = (i / 3) * 3 + j / 3;

            if (val < 0 || val > 8 ||
                (rows[i] & mask) ||
                (cols[j] & mask) ||
                (boxes[box_idx] & mask)) {
                return false;
            }

            // adding to the bits
            rows[i] |= mask;
            cols[j] |= mask;
            // when we add to existing e.g. 10000 (1 << 5)
            // let's say add (1 << 4) --> 11000
            boxes[box_idx] |= mask;
        }
    }

    return true;
}

// Utility function to print the Sudoku board
void printBoard(char** board) {
    printf("Sudoku Board:\n");
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {
            printf("---------------------\n");
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) {
                printf("| ");
            }
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    // Allocate memory for the board
    char** board = (char**)malloc(9 * sizeof(char*));
    for (int i = 0; i < 9; i++) {
        board[i] = (char*)malloc(9 * sizeof(char));
    }

    // Example 1: Valid Sudoku board (partially filled)
    char* validBoard[9] = {
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"
    };

    // Copy valid board data
    for (int i = 0; i < 9; i++) {
        strncpy(board[i], validBoard[i], 9);
    }

    // Test valid board
    printf("Testing Valid Board:\n");
    printBoard(board);
    int boardColSize = 9;
    bool isValid = isValidSudoku(board, 9, &boardColSize);
    printf("Is valid: %s\n\n", isValid ? "true" : "false");

    // Example 2: Invalid Sudoku board (duplicate in row)
    char* invalidBoard[9] = {
        "53..75...",  // Note: duplicate 5 in first row
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"
    };

    // Copy invalid board data
    for (int i = 0; i < 9; i++) {
        strncpy(board[i], invalidBoard[i], 9);
    }

    // Test invalid board
    printf("Testing Invalid Board:\n");
    printBoard(board);
    isValid = isValidSudoku(board, 9, &boardColSize);
    printf("Is valid: %s\n", isValid ? "true" : "false");

    // Free allocated memory
    for (int i = 0; i < 9; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}

