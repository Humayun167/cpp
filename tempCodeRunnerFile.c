#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    FILE *inputFile; // File pointer for the input file
    FILE *outputFile; // File pointer for the output file
    char line[1000]; // Buffer to store each line read from the input file
    bool inCommentBlock = false; // Flag to indicate if we are inside a block comment

    // Open the input file in read mode
    inputFile = fopen("test.txt", "r");
    // Open the output file in write mode
    outputFile = fopen("output.txt", "w");

    // Check if both files are successfully opened
    if (inputFile != NULL && outputFile != NULL)
    {
        // Read each line from the input file
        while (fgets(line, sizeof(line), inputFile))
        {
            // Find the start of a block comment
            char *startComment = strstr(line, "/*");
            // Find the end of a block comment
            char *endComment = strstr(line, "*/");
            // Find the start of a line comment
            char *lineComment = strstr(line, "//");

            // If we are inside a block comment
            if (inCommentBlock)
            {
                // If the end of the block comment is found
                if (endComment)
                {
                    inCommentBlock = false; // Exit the block comment
                    // Copy the part of the line after the block comment
                    strcpy(line, endComment + 2);
                }
                else
                {
                    continue; // Skip the line if still inside a block comment
                }
            }

            // If the start of a block comment is found and it is before any line comment
            if (startComment && (!lineComment || startComment < lineComment))
            {
                inCommentBlock = true; // Enter the block comment
                *startComment = '\0'; // Terminate the line at the start of the block comment
            }
            // If a line comment is found
            else if (lineComment)
            {
                *lineComment = '\0'; // Terminate the line at the start of the line comment
            }

            // If not inside a block comment and the line is not empty
            if (!inCommentBlock && strlen(line) > 0)
            {
                // Write the line to the output file
                fprintf(outputFile, "%s", line);
            }
        }
        // Close the input file
        fclose(inputFile);
        // Close the output file
        fclose(outputFile);
    }
    else
    {
        // Print an error message if file opening failed
        printf("file open failed\n");
    }

    return 0; // Return 0 to indicate successful execution
}
