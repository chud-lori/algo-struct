#include <stdio.h>
#include <stdlib.h>

void printMatrixdd(int matrix[4][4], int n, int m) {
    printf("Adjacency Matrix:\n");
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printMatrix(int** matrix, int n, int m) {
    printf("Adjacency Matrix:\n");
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printConnections(int** matrix, char** vertices, int num_vertices) {
    printf("Connections for each vertex:\n");

    for(int i = 0; i < num_vertices; ++i) {
        printf("%s: ", vertices[i]);
        for(int j = 0; j < num_vertices; ++j) {
            if (matrix[i][j]) {
                printf("%s ", vertices[j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int num_vertices = 4;
    // allocate memory for vertices
    char* vertices[] = {"A", "B", "C", "D"};

    // allocate memory for adjacency matrix
    int matrix[4][4] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 0},
        {1, 0, 0, 0}
    };

        // To pass a 2D array to a function in C, you often need to pass it as a pointer to pointers
    // or specify the size of the inner dimension. For simplicity in this example,
    // we'll cast it to a bool** for demonstration, but for production code,
    // proper dynamic allocation and passing of the matrix would be preferred.
    // A more robust way to pass a 2D array to a function is to specify the column size,
    // e.g., void print_connections(bool matrix[][MAX_COLS], char** vertices, int num_vertices)

    // For this example, let's create a dynamic 2D array to match the function signature
    int** dynamic_matrix = (int**) malloc(num_vertices * sizeof(int*));
    for (int i = 0; i < num_vertices; i++) {
        dynamic_matrix[i] = (int*) malloc(num_vertices * sizeof(int));
        for (int j = 0; j < num_vertices; j++) {
            dynamic_matrix[i][j] = matrix[i][j];
        }
    }

    printMatrix(dynamic_matrix, 4, 4);
    printConnections(dynamic_matrix, vertices, num_vertices);

    // free the dynamically allocated memory
    for (int i = 0; i < num_vertices; i++) {
        free(dynamic_matrix[i]);
    }
    free(dynamic_matrix);

    return 0;
}

/*
 * Level 1: `dynamic_matrix` (int**)
         Points to the base of an array of pointers.
         +-----------+
         | dynamic_matrix |
         +-----------+
              |
              V  (points to a block of int* addresses)
         +-----------+
         | dynamic_matrix[0] (int*) --> points to Row 0 data
         +-----------+
         | dynamic_matrix[1] (int*) --> points to Row 1 data
         +-----------+
         | dynamic_matrix[2] (int*) --> points to Row 2 data
         +-----------+
         ...

Level 2: `dynamic_matrix[i]` (int*)
         Each of these elements points to a row's data.
         (Let's take `dynamic_matrix[1]` as an example)
         +-----------+
         | dynamic_matrix[1] |
         +-----------+
              |
              V  (points to a block of int values for Row 1)
         +---+---+---+---+---+
         | val | val | val | val | val |   <-- This is Row 1's actual data
         +---+---+---+---+---+

Level 3: `dynamic_matrix[i][j]` (int)
         This is the specific value within a row.
         (Let's take `dynamic_matrix[1][2]` as an example)
         +---+---+---+---+---+
         | val | val | val | val | val |
         +---+---+---+---+---+
                   ^
                   |
                   (This is the specific int value at column 2 of row 1)
*/



/*
You've hit on a very insightful question! It does look weird at first glance, especially if you're used to how other languages might handle multi-dimensional arrays, or even how C handles statically declared ones.

The core reason we often resort to int** (pointer-to-pointer) for dynamic 2D arrays in C (and often in C++ before std::vector became prevalent) is primarily due to:

Dynamic Sizing (Runtime Dimensions):

In C, when you declare int matrix[4][4];, the dimensions (4 and 4) must be known at compile time. The compiler lays out this entire 4×4 block of memory as a single, contiguous block (e.g., [0][0], [0][1], ..., [0][3], [1][0], ... [3][3]). It then uses simple arithmetic to calculate the memory address for matrix[i][j].
If you want to create a matrix where the number of rows and columns (num_vertices in your example) is determined while the program is running (e.g., read from user input, a file, or calculated based on some runtime condition), you cannot use the int matrix[num_vertices][num_vertices]; syntax (unless your compiler specifically supports C99 Variable Length Arrays as an extension, which is not standard C++ and has limitations).
Since malloc can only allocate a contiguous block of memory of a specified size, and you can't easily tell malloc to return a pointer to a "true" 2D array (like int (*)[num_vertices]), we build the 2D structure out of 1D arrays.
Lack of Built-in "True" Dynamic 2D Array Type:

C and C++ don't have a direct, built-in language feature for a "dynamically sized 2D array where all elements are guaranteed to be contiguous in memory" that you can just malloc once and access with [][] syntax directly without knowing dimensions at compile time.
The int** approach is a simulation or emulation of a 2D array using pointers and separate 1D arrays for each row.
Why not a single allocation for a contiguous 2D array?
You can allocate a truly contiguous 2D array dynamically in C, but it's a bit more cumbersome to access with [][] without casting:

C

// Method A: Single contiguous block, then manual indexing
int* contiguous_matrix = (int*)malloc(rows * cols * sizeof(int));
// To access element (i, j): contiguous_matrix[i * cols + j]
// This is how statically declared 2D arrays actually work under the hood.

// Or, Method B: Single contiguous block, then array of pointers for convenience
int* data = (int*)malloc(rows * cols * sizeof(int));
int** matrix_pointers = (int**)malloc(rows * sizeof(int*));
for (int i = 0; i < rows; i++) {
    matrix_pointers[i] = &(data[i * cols]); // Point each row pointer to the correct start
}
// Now you can access matrix_pointers[i][j]
// You only free `data` and `matrix_pointers` at the end.
Why is int** (Method B/what you have) more common than int* (Method A) for dynamic 2D arrays, despite the extra memory allocations and potential non-contiguity of rows?

Readability and Familiarity:

The int** approach allows you to use the familiar matrix[i][j] syntax, which closely resembles static 2D array access. This often makes the code easier to read and write once you understand the underlying pointer mechanics.
If you used the single int* allocation (Method A), you'd have to manually calculate i * cols + j every time, which can be error-prone and less intuitive for many programmers.
Jagged Arrays (Arrays of different length rows):

The int** structure naturally supports jagged arrays, where each row can have a different number of columns. This is because each dynamic_matrix[i] points to its own independent 1D array.
A truly contiguous allocation (like Method A) forces all rows to have the same length.
Simplicity of Row-by-Row Operations:

If you need to pass a single row to a function, dynamic_matrix[i] is already an int*, which is exactly what a function expecting a 1D array would need. This is very convenient.
The "Weirdness" is a C Compromise:
The int** method is a common compromise in C for dynamic 2D arrays:

It allows for runtime-determined dimensions.
It maintains the familiar [][] syntax.
It uses standard malloc calls.
The trade-off is the extra memory allocations (one for the array of pointers, and one for each row) and the potential for rows to be non-contiguous in memory (though modern memory allocators might try to place them close). This can sometimes lead to slightly worse cache performance compared to a truly contiguous single block, but for many applications, the difference is negligible and outweighed by the flexibility and coding convenience.
C++ Modern Approach (std::vector<std::vector<int>>)
In modern C++, you'd typically avoid raw int** and malloc/free altogether for dynamic arrays and instead use std::vector<std::vector<int>>. This handles all the memory management, allocation, and deallocation automatically, provides contiguous memory within each row, and offers a more robust and safer interface.

C++

#include <vector>
#include <iostream>

void printMatrixCpp(const std::vector<std::vector<int>>& matrix) {
    std::cout << "Adjacency Matrix (C++ Vector):\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}

// int main() {
//     int num_vertices = 5;
//     std::vector<std::vector<int>> matrix(num_vertices, std::vector<int>(num_vertices));
//     // Now you can access matrix[i][j] just like before,
//     // but all memory management is handled by std::vector.
//     printMatrixCpp(matrix);
//     return 0;
// }
This is the "array of arrays" you likely wished for, but it's provided by the C++ Standard Library, not a raw language feature in the same way malloc is. Each std::vector<int> guarantees its elements are contiguous, and std::vector<std::vector<int>> stores the std::vector<int> objects themselves contiguously.

So, the int** structure is a very C-idiomatic way to manage dynamic 2D arrays when you're sticking to C or earlier C++ practices.



*/
