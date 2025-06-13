#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a maximum line length for reading CSV lines
#define MAX_LINE_LENGTH 1024

// Structure to hold an entry in the binary index file
typedef struct {
    long dni;
    long offset; // Byte offset in the personas.csv file
} IndexEntry;

// Comparison function for qsort to sort IndexEntry by DNI
int compareIndexEntries(const void *a, const void *b) {
    IndexEntry *entryA = (IndexEntry *)a;
    IndexEntry *entryB = (IndexEntry *)b;
    if (entryA->dni < entryB->dni) {
        return -1;
    } else if (entryA->dni > entryB->dni) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *csvFile = NULL;
    FILE *idxFile = NULL;
    char line[MAX_LINE_LENGTH];
    IndexEntry *index = NULL;
    int indexCount = 0;
    int capacity = 10; // Initial capacity for the dynamic array of index entries

    // 1. Open "personas.csv" for reading
    csvFile = fopen("personas.csv", "r");
    if (csvFile == NULL) {
        perror("Error opening personas.csv");
        return EXIT_FAILURE;
    }

    // 2. Skip the header line
    if (fgets(line, sizeof(line), csvFile) == NULL) {
        fprintf(stderr, "Error reading header from personas.csv or file is empty.\n");
        fclose(csvFile);
        return EXIT_FAILURE;
    }

    // Allocate initial memory for the index
    index = (IndexEntry *)malloc(capacity * sizeof(IndexEntry));
    if (index == NULL) {
        perror("Error allocating memory for index");
        fclose(csvFile);
        return EXIT_FAILURE;
    }

    // 3. Iterate through "personas.csv" to build the in-memory index
    printf("Building in-memory index...\n");
    while (fgets(line, sizeof(line), csvFile) != NULL) {
        // Get the current byte offset before processing the line
        long currentOffset = ftell(csvFile) - strlen(line); // Adjust for the line just read

        // Dynamically resize the index array if needed
        if (indexCount >= capacity) {
            capacity *= 2; // Double the capacity
            IndexEntry *temp = (IndexEntry *)realloc(index, capacity * sizeof(IndexEntry));
            if (temp == NULL) {
                perror("Error reallocating memory for index");
                // Clean up before exiting
                free(index);
                fclose(csvFile);
                return EXIT_FAILURE;
            }
            index = temp;
        }

        // Parse the DNI from the line and store it with the offset
        // We'll implement parseDNIFromLine() next
        long dni = 0;
        if (parseDNIFromLine(line, &dni)) {
            index[indexCount].dni = dni;
            index[indexCount].offset = currentOffset;
            indexCount++;
        } else {
            fprintf(stderr, "Warning: Could not parse DNI from line: %s", line);
        }
    }
    printf("Finished building index. Total entries: %d\n", indexCount);

    // 4. Sort the in-memory index
    printf("Sorting index by DNI...\n");
    qsort(index, indexCount, sizeof(IndexEntry), compareIndexEntries);
    printf("Index sorted.\n");

    // 5. Open "personas.idx" for writing in binary mode
    idxFile = fopen("personas.idx", "wb");
    if (idxFile == NULL) {
        perror("Error opening personas.idx");
        free(index);
        fclose(csvFile);
        return EXIT_FAILURE;
    }

    // 6. Write the sorted index to "personas.idx"
    printf("Writing index to personas.idx...\n");
    size_t written = fwrite(index, sizeof(IndexEntry), indexCount, idxFile);
    if (written != indexCount) {
        fprintf(stderr, "Error writing all index entries to personas.idx. Written %zu of %d\n", written, indexCount);
        // Continue cleanup, but note the error
    } else {
        printf("Index successfully written to personas.idx.\n");
    }

    // 7. Close files and free memory
    fclose(csvFile);
    fclose(idxFile);
    free(index);

    printf("Program finished successfully.\n");

    return EXIT_SUCCESS;
}

// --- Helper function to parse DNI from a CSV line ---
// Declaration, definition will follow after this main structure.
// This function needs to be defined before main or declared.
int parseDNIFromLine(const char *line, long *dni);
