#include <stdio.h> // Include the standard input/output library

// Function prototype for countStatistics, which takes a filename as a parameter
void countStatistics(const char *filename);

int main() {
    // Declare a constant character pointer variable 'filename' and assign it the name of the file
    const char *filename = "example.txt"; // Replace "example.txt" with your filename
    
    // Print a header indicating the start of file statistics calculation
    printf("File Statistics:\n");
    
    // Call the countStatistics function, passing the filename as an argument
    countStatistics(filename);
    
    // Return 0 to indicate successful execution of the program
    return 0;
}

// Definition of the countStatistics function
void countStatistics(const char *filename) {
    // Attempt to open the file specified by 'filename' in read mode ('r')
    FILE *file = fopen(filename, "r");
    
    // Check if the file failed to open (returns NULL)
    if (file == NULL) {
        // If the file did not open successfully, print an error message and exit the function
        printf("Failed to open %s\n", filename);
        return;
    }

    // Initialize counters for characters, words, and lines
    int chCount = 0; // Characters
    int wordCount = 0; // Words
    int lineCount = 0; // Lines

    // Read the file character by character until EOF (End Of File) is encountered
    int c;
    while ((c = fgetc(file)) != EOF) {
        // Increment the character count for each character read
        chCount++; 

        // Check if the character is a space, tab, or newline (indicating the end of a word)
        if (c == ' ' || c == '\t' || c == '\n') {
            // Increment the word count
            wordCount++;
        } 
        // Specifically check for newline characters to count lines
        else if (c == '\n') {
            lineCount++;
        }
    }

    // Close the file after reading
    fclose(file);

    // Print the total number of characters, words, and lines found in the file
    printf("Characters: %d\n", chCount);
    printf("Words: %d\n", wordCount + 1); // Add 1 because we increment on spaces but not at the end of the last word
    printf("Lines: %d\n", lineCount + 1); // Add 1 because we increment on newlines but not after the last line
}