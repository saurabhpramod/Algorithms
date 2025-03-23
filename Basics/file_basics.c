#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100  // Max characters per line

int main() {
    FILE *fp;
    char filename[50];
    char buffer[MAX_LINE_LENGTH];
    int num_lines = 0;
    
    // Get the filename from the user
    printf("Enter the file name: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';  // Remove newline character

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return 1;
    }

    // Count the number of lines in the file
    while (fgets(buffer, MAX_LINE_LENGTH, fp) != NULL) {
        num_lines++;
    }
    
    // Move file pointer back to the beginning
    rewind(fp);

    // Allocate memory for an array of strings (2D array)
    char **arr = (char **)malloc(num_lines * sizeof(char *));
    for (int i = 0; i < num_lines; i++) {
        arr[i] = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
    }

    // Read file content into the allocated 2D array
    int i = 0;
    while (fgets(arr[i], MAX_LINE_LENGTH, fp) != NULL && i < num_lines) {
        arr[i][strcspn(arr[i], "\n")] = '\0';  // Remove newline character
        i++;
    }

    // Close the file
    fclose(fp);


    printf("Reading file content from 2d array: \n");
    for(int i=0;i<num_lines;i++)
    {  printf("\n");
        for(int j=0;j<100;j++)
        {
            printf("%c",arr[i][j]);
        }
    }

    // Free dynamically allocated memory
    for (int i = 0; i < num_lines; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}