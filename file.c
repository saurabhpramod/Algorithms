/* Example on how to read a file row-by-row */
 
#include <stdio.h>
#include <stdlib.h>
 
#define LEN 100 // Length of the row
 
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
    fp = fopen("01_text.in", "r");
 
    // Control if the file has been opened without errors */
    if (fp == NULL){
        printf("Error: impossible to open the file file.txt\n");
        exit(1);
    }
 
    // docs to fgets(): `https://android.googlesource.com/platform/bionic/+/ics-mr0/libc/stdio/fgets.c`
    /* Reading the file row-by-row */
   // printf("Reading row-by-row:\n");
   // while (fgets(row, LEN, fp) != NULL) {
  //     printf("READ: %s\n", row);
   // }

    // Just checking out the number in the variable LEN
   // printf("%d, %d", LEN, LEN+1);
   // int j=0;
   printf("Reading from file : \n");
  for(int i=0;i<LEN;i++)
    {
        
        ch=fgetc(fp);
        row[i]=ch;
        printf("%c",ch);
    }
 

    int temp=0;

    printf("Now reading from row: \n");
    for(int i=0;i<LEN;i++)
    {
        printf("%c",row[i]);
        temp++;
    }
    int count=0;

    printf("Number of iterations :%d\n",temp);

    for(int i=0;i<LEN;i++)
    {
        if((row[i]=='h')&&(row[i+1]=='h')&&(row[i+2]=='h')&&(row[i+3]=='h')&&(row[i+4]=='h'))
        {
            count++;
        }
    }
    printf("The number of repetitions is: %d",count);

    printf("\n");

    for(int i=0;ch!='\n';i++)
    {
        
        ch=fgetc(fp);
        row[i]=ch;
        printf("%c",row[i]);
    }


    

  /*  int count =0;
    for(int i=0;i<LEN;i++)
    {
        if(fgetc(fp))
        {
            count++;
        }
    }
*/

   // rewind(fp);
   //printf("The file output is :%d",ch);

    fclose(fp); /* Closing the file */
 
    return 0;
}