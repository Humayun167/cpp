#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void removeComments(FILE *inputFile, FILE *outputFile) {
    char line[1000];
    bool inCommentBlock = false;

    while (fgets(line, sizeof(line), inputFile)) {
        char *startComment = strstr(line, "/*");
        char *endComment = strstr(line, "*/");
        char *lineComment = strstr(line, "//");

        if (inCommentBlock) {
            if (endComment) {
                inCommentBlock = false;
                strcpy(line, endComment + 2);
            } else {
                continue;
            }
        }

        if (startComment && (!lineComment || startComment < lineComment)) {
            inCommentBlock = true;
            *startComment = '\0';
        } else if (lineComment) {
            *lineComment = '\0';
        }

        if (!inCommentBlock && strlen(line) > 0) {
            fprintf(outputFile, "%s", line);
        }
    }
}

int main() {
    FILE *inputFile = fopen("test.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (inputFile && outputFile) {
        removeComments(inputFile, outputFile);
        fclose(inputFile);
        fclose(outputFile);
    } else {
        printf("file open failed\n");
    }

    return 0;
}
