#include <stdio.h>   // For file I/O (fopen, fread, fclose, ferror, perror, remove)
#include <stdlib.h>  // For exit, malloc (though not used for main data buffer here)
#include <string.h>  // For string manipulation (e.g., memset, though not strictly needed here)

// Define the size of the buffer we will use to read data in chunks.
// This is crucial for memory efficiency.
#define CHUNK_SIZE 1024 // 1 KB per chunk

// Define the simulated size of our "large file".
// This file will be 5MB (1024 bytes/KB * 5000 chunks = 5,120,000 bytes).
// We will process this file without loading all 5MB into memory at once.
#define LARGE_FILE_SIZE (CHUNK_SIZE * 5000)

/**
 * @brief Creates a dummy file of a specified size, filled with alternating 'a' and 'b' characters.
 * This simulates a large data source for our streaming example.
 * @param filename The name of the file to create.
 * @param size The desired size of the file in bytes.
 */
void create_dummy_file(const char* filename, long size) {
    // Open the file in binary write mode ("wb").
    // If the file exists, it will be truncated; otherwise, a new file is created.
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error creating dummy file"); // Print system error message
        exit(EXIT_FAILURE); // Exit the program if file creation fails
    }

    char data_char = 'a'; // Starting character to fill the file
    // Write characters one by one to the file until the desired size is reached.
    for (long i = 0; i < size; i++) {
        fputc(data_char, file); // Write a single character to the file
        // Alternate characters every 100 bytes to make the content slightly varied
        if (i % 100 == 0) {
            data_char = (data_char == 'a') ? 'b' : 'a';
        }
    }

    fclose(file); // Close the file stream, flushing any buffered data to disk
    printf("Created dummy file '%s' of size %ld bytes.\n", filename, size);
}

/**
 * @brief Main function to demonstrate reading a file in chunks (streaming).
 */
int main() {
    const char* filename = "large_dummy_file.txt";
    create_dummy_file(filename, LARGE_FILE_SIZE); // Create our simulated large file

    FILE* file = NULL;
    // Declare a fixed-size buffer on the stack. This buffer will hold one chunk of data at a time.
    char buffer[CHUNK_SIZE];
    size_t bytes_read; // Variable to store the number of bytes read in each call to fread
    long total_bytes_processed = 0; // Accumulator for total bytes processed
    int chunk_count = 0;           // Counter for the number of chunks processed

    printf("\n--- Demonstrating Chunked File Reading in C ---\n");
    printf("Configured chunk size: %d bytes\n", CHUNK_SIZE);
    printf("Simulated file size: %ld bytes\n\n", LARGE_FILE_SIZE);

    // 1. Open the file stream for reading in binary mode ("rb").
    // This establishes a connection to the file on disk.
    file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file"); // Print error if file cannot be opened
        return EXIT_FAILURE;          // Exit with an error code
    }

    // 2. The core streaming loop: Read and process data in chunks.
    // fread attempts to read CHUNK_SIZE bytes into 'buffer'.
    // It returns the actual number of bytes read, which might be less than CHUNK_SIZE
    // if it reaches the end of the file or an error occurs.
    // The loop continues as long as bytes_read is greater than 0.
    while ((bytes_read = fread(buffer, 1, CHUNK_SIZE, file)) > 0) {
        chunk_count++;
        total_bytes_processed += bytes_read;

        printf("Chunk %d: Read %zu bytes. Total processed: %ld bytes.\n",
               chunk_count, bytes_read, total_bytes_processed);

        // --- Simulate processing the current chunk ---
        // This is where your application-specific logic would go.
        // The key is that you are working ONLY with the data currently in 'buffer'.
        // Once this block finishes, 'buffer' can be reused for the next chunk.

        // Example: Count occurrences of a specific character ('a') in the current chunk
        int a_count = 0;
        for (size_t i = 0; i < bytes_read; i++) {
            if (buffer[i] == 'a') {
                a_count++;
            }
        }
        printf("  (Simulated processing: Found %d 'a's in this chunk)\n", a_count);
        // End of chunk processing simulation
    }

    // 3. Check for any errors that might have occurred during the fread loop,
    // other than reaching the end of the file (EOF).
    if (ferror(file)) {
        perror("Error reading file"); // Print error if a read error occurred
    } else {
        printf("\nEnd of file reached. All chunks processed.\n");
    }

    // 4. Close the file stream. This releases the file handle and any associated resources.
    fclose(file);

    // Clean up: Remove the dummy file created for the demonstration.
    remove(filename);

    printf("\n--- Summary ---\n");
    printf("Total chunks processed: %d\n", chunk_count);
    printf("Total bytes processed: %ld\n", total_bytes_processed);
    printf("Maximum memory used for data buffering at any single time: %d bytes (equal to CHUNK_SIZE)\n", CHUNK_SIZE);
    printf("Crucially, the entire %ld bytes file was NOT loaded into memory at once.\n", LARGE_FILE_SIZE);

    return EXIT_SUCCESS; // Indicate successful execution
}

