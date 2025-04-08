//Algorithm to count frequency of words from a file in another file 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100  // Max characters per line

int main()
{
    FILE *fpa, *fpb;
    char filename_a[50], filename_b[50], buffer[MAX_LINE_LENGTH];
    int num_lines_a = 0, num_lines_b = 0;

    // Get filenames
    printf("Enter the first file name: ");
    fgets(filename_a, sizeof(filename_a), stdin);
    filename_a[strcspn(filename_a, "\n")] = '\0';  

    printf("Enter the second file name: ");
    fgets(filename_b, sizeof(filename_b), stdin);
    filename_b[strcspn(filename_b, "\n")] = '\0';  

    // Open files
    if ((fpb = fopen(filename_b, "r")) == NULL) {
        printf("Error: Cannot open file %s\n", filename_b);
        return 1;
    }
    if ((fpa = fopen(filename_a, "r")) == NULL) {
        printf("Error: Cannot open file %s\n", filename_a);
        fclose(fpb);
        return 1;
    }

    // Count lines in both files
    while (fgets(buffer, MAX_LINE_LENGTH, fpb) != NULL) num_lines_b++;
    rewind(fpb);
    while (fgets(buffer, MAX_LINE_LENGTH, fpa) != NULL) num_lines_a++;
    rewind(fpa);

    // Allocate memory for file A
    char **arr_a = (char **)malloc(num_lines_a * sizeof(char *));
    for (int i = 0; i < num_lines_a; i++) {
        arr_a[i] = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
    }

    // Allocate memory for file B
    char **arr_b = (char **)malloc(num_lines_b * sizeof(char *));
    for (int i = 0; i < num_lines_b; i++) {
        arr_b[i] = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
    }

    // Read file A into array
    for (int i = 0; i < num_lines_a; i++) {
        fgets(arr_a[i], MAX_LINE_LENGTH, fpa);
        arr_a[i][strcspn(arr_a[i], "\n")] = '\0';  
    }
    fclose(fpa);

    // Read file B into array
    for (int i = 0; i < num_lines_b; i++) {
        fgets(arr_b[i], MAX_LINE_LENGTH, fpb);
        arr_b[i][strcspn(arr_b[i], "\n")] = '\0';  
    }
    fclose(fpb);

    // Print file contents
    printf("Reading file content from file A:\n");
    for (int i = 0; i < num_lines_a; i++) {
        printf("%s\n", arr_a[i]);
    }

    printf("\nReading file content from file B:\n");
    for (int i = 0; i < num_lines_b; i++) {
        printf("%s\n", arr_b[i]);
    }

    // Function to convert a string to lowercase
void toLowerCase(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

char **arr_c = NULL;  // Dynamic array of words
int word_count = 0;   // Track number of words

void add(char *word) {
    // Allocate space for new word
    arr_c = realloc(arr_c, (word_count + 1) * sizeof(char *));
    arr_c[word_count] = malloc(strlen(word) + 1);
    strcpy(arr_c[word_count], word);  // Copy word into array
    word_count++;
}


int match=0;
    printf("\nComparing words between files:\n");

    for (int i = 0; i < num_lines_a; i++) {
        char line_a[MAX_LINE_LENGTH];
        strcpy(line_a, arr_a[i]);  // Copy line to avoid modifying original

        char *word_a = strtok(line_a, " ");  // Tokenize first line from file A

        while (word_a != NULL) {
            toLowerCase(word_a);  // Convert word_a to lowercase

            for (int j = 0; j < num_lines_b; j++) {
                char line_b[MAX_LINE_LENGTH];
                strcpy(line_b, arr_b[j]);  // Copy line to avoid modifying original

                char *word_b = strtok(line_b, " ");  // Tokenize first line from file B

                while (word_b != NULL) {
                    toLowerCase(word_b);  // Convert word_b to lowercase

                    if (strcmp(word_a, word_b) == 0) {  // Compare words
                      //  printf("Match found: %s\n", word_a);
                        match++;
                        add(word_a);
                        
                    }
                    word_b = strtok(NULL, " ");  // Get next word from file B
                }
            }
            word_a = strtok(NULL, " ");  // Get next word from file A
        }
    }

    printf("The number of matches is :%d\n",match);
    int *frq=(int *)calloc(match, sizeof(int));

    for(int i=0;i<match;i++)
    {
        for(int j=i+1;j<match;j++)
        {
         if(strcmp(arr_c[i],arr_c[j])==0)
         {
            frq[i]++;       
         }
        }
    }

    

    for(int i=0;i<match;i++)
    {
        for(int j=i+1;j<match;j++)
        {
            if(strcmp(arr_c[i],arr_c[j])==0)
            {
                frq[j]=0;
            }
        }
    }

  int cnt=1;

  printf("Frequency of words:  \t\n");

    for(int i=0;i<match;i++)
    {   
        if(frq[i]>0)
        {
         printf(" %d. %s ------>%d\n",cnt,arr_c[i],frq[i]+1);
         cnt++;
     
        }
     }
   

  
    // Free memory
    for (int i = 0; i < num_lines_a; i++) 
    {free(arr_a[i]);}
    for (int i = 0; i < num_lines_b; i++)
    { free(arr_b[i]);}
    for (int i = 0; i < match; i++)
    { free(arr_c[i]);}

    free(arr_a);
    free(arr_b);
    free(frq);

    return 0;
}
