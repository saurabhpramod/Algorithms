/* Example on how to read a file row-by-row */
 
#include <stdio.h>
#include <stdlib.h>
 
#define LEN 50 // Length of the row
 
int main()
{
    FILE *fp;
 
    char row[LEN+1]; /* To read strings of maximum length of 50 characters,
                        an array of characters of dimension 51 must be declared,
                        because after the string the termination character '\0' must be stored */
    char ch;
    int intValue;
    float floatValue;
 
    /* Reading the content of the file file.txt */
    /* Opening the file */
    printf("READING source.txt\n");
    fp = fopen("source.txt", "r");
 
    /* Control if the file has been opened without errors */
    if (fp == NULL){
        printf("Error: impossible to open the file file.txt\n");
        exit(1);
    }
 
    // docs to fgets(): `https://android.googlesource.com/platform/bionic/+/ics-mr0/libc/stdio/fgets.c`
    /* Reading the file row-by-row */
    printf("Reading row-by-row:\n");
    while (fgets(row, LEN, fp) != NULL) {
       printf("READ: %s\n", row);
    }

    // Just checking out the number in the variable LEN
    printf("%d, %d", LEN, LEN+1);

    rewind(fp);

    fclose(fp); /* Closing the file */
 
    return 0;
}
