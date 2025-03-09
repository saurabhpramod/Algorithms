#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

// Sort a row in ascending order (bubble sort)
void sort_row(int *arr, int n)
 {
    for (int i = 0; i < n - 1; i++)
     {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//Sort a column in ascending order (bubble sort)
void sort_col(int **arr, int n, int k) 
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++)
         {
            if (arr[j][k] > arr[j+1][k]) 
                {
                    int temp = arr[j][k];
                    arr[j][k] = arr[j+1][k];
                    arr[j+1][k] = temp;
                }
            }
        }
    }


int main() {
    FILE *fp;
    char filename[50];
    char buffer[MAX_LINE_LENGTH];
    int num_lines = 0;
    int col_max = 0;

    // Get the filename from the user
    printf("Enter the file name: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';  // Remove newline character

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return 1;
    } else {
        printf("File opened successfully: %s\n", filename);
    }

    // Count the number of lines in the file
    while (fgets(buffer, MAX_LINE_LENGTH, fp) != NULL) {
        num_lines++;
    }

    // Check if the file is empty
    if (num_lines == 0) {
        printf("The file is empty.\n");
        fclose(fp);
        return 1;
    }

    //printf("Number of lines in the file: %d\n", num_lines);

    // Allocate memory for an array of strings (2D array)
    char **arr = (char **)malloc(num_lines * sizeof(char *));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        fclose(fp);  // Close the file if memory allocation fails
        return 1;
    }

    // Allocate memory for each line in arr
    for (int i = 0; i < num_lines; i++) {
        arr[i] = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
        if (arr[i] == NULL) {
            printf("Memory allocation for line %d failed.\n", i);
            // Free previously allocated memory before returning
            for (int j = 0; j < i; j++) {
                free(arr[j]);
            }
            free(arr);
            fclose(fp);
            return 1;
        }
    }

    // Read file content into the allocated 2D array
    int i = 0;
    rewind(fp);  // Move the file pointer back to the beginning
    while (fgets(arr[i], MAX_LINE_LENGTH, fp) != NULL && i < num_lines) {
        arr[i][strcspn(arr[i], "\n")] = '\0';  // Remove newline character
        i++;
    }

    // Close the file after reading
    fclose(fp);

    // Allocate memory for the integer matrix
    int **matrix = (int **)malloc(num_lines * sizeof(int *));
    for (int i = 0; i < num_lines; i++)
    {
        matrix[i] = (int *)malloc(MAX_LINE_LENGTH * sizeof(int));
        if (matrix[i] == NULL)
        {
            printf("Memory allocation for matrix line %d failed.\n", i);
            fclose(fp);
            return 1;
        }
    }

    // Process the tokens in each line to populate the matrix
    for (int i = 0; i < num_lines; i++) 
    {
        int col = 0;
        char *token = strtok(arr[i], " \t");  // Tokenize by spaces and tabs
         while (token != NULL)
          {
            int num = atoi(token);  // Convert the token to an integer
            
            if (num != 0 || strcmp(token, "0") == 0) 
            {  // Ensure 0 is considered valid
                matrix[i][col] = num;
                col++;
            } 
            else 
            {
                printf("Warning: Non-integer token found: %s\n", token);
            }
            token = strtok(NULL, " \t");  // Get the next token
         }

        if (col > col_max)
        {
            col_max = col;  // Update col_max to the maximum number of columns
        }
    }

    // Printing the matrix with integers from the file
    printf("\nThe matrix with integers from the file:\n");
    for (int i = 0; i < num_lines; i++) 
    {
        for (int j = 0; j < col_max; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Sort the matrix by each column
  for (int i = 0; i < col_max; i++) 
   {
        sort_col(matrix, num_lines, i);  // Sort matirx by each column
   }
  // for (int i = 0; i < num_lines; i++) 
 //  {
  //      sort_col(matrix, num_lines, i);  // Sort matirx by each column
 //  }

   

    // Print the sorted matrix
    printf("\nThe sorted matrix (sorted by columns):\n");
    for (int i = 0; i < num_lines; i++) 
    {
        for (int j = 0; j < col_max; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

  // Writing sorted matrix to a new file
  FILE *output_fp = fopen("output.out", "w");
  if (output_fp == NULL) {
      printf("Error: Cannot create or open output file.\n");
      return 1;
  }

  // Write the sorted matrix to the output file
  for (int i = 0; i < num_lines; i++) {
      for (int j = 0; j < col_max; j++) {
          fprintf(output_fp, "%d\t", matrix[i][j]);  // Write each element
      }
      fprintf(output_fp, "\n");  // Newline after each row
  }

  // Close the output file after writing
  fclose(output_fp);
  printf("Sorted matrix written to 'output.out'.\n");
    // Free dynamically allocated memory
    for (int i = 0; i < num_lines; i++)
    {
        free(arr[i]);
        free(matrix[i]);
    }
    free(arr);
    free(matrix);

    return 0;
}
