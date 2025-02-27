/* Example on how to read a file row-by-row */
 
#include <stdio.h>
#include <stdlib.h>
 
#define LEN 100 // Length of the row
 
int main()
{
    FILE *fp;
 
    char ch;
 
   printf("Enter the file to read \n");
   fgets(file,sizeof(file),stdin);
   file[strcspn(file, "\n")] = '\0';

    printf("READING %s \n",file);
    fp = fopen(file, "r");
 
    if (fp == NULL){
        printf("Error: impossible to open the file file.txt\n");
        exit(1);
    }


    printf("\n");
    fseek(fp, 0, SEEK_SET);


    int arr[100][100]={0};
    int j=0;
    int k=0;

    printf("Now reading from 2D array\n");
    ch=fgetc(fp);
   
    while(ch!=EOF)
    { 

        if(ch=='\n')
        {   
            arr[j][k]='\n';
            j++;
            k=0;
          
        }
        else 
        {
            arr[j][k]=ch;
            k++;
          
        }
        ch=fgetc(fp);
     
    }


    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            printf("%c",arr[i][j]);
        }
    }


    int v_count=0;
    int h_count=0;

    for(int i=0;i<100;i++)
    {
        

         for(int j=0;j<100;j++)
         { 
            if((arr[i][j])=='v' &&(arr[i+1][j])=='v' &&(arr[i+2][j])=='v'&& (arr[i+3][j])=='v'&&(arr[i+4][j])=='v')
            {
                    v_count++;
            }
            if((arr[i][j])=='h' &&(arr[i][j+1])=='h' &&(arr[i][j+2])=='h'&& (arr[i][j+3])=='h'&&(arr[i][j+4])=='h')
            {
                    h_count++;
            }
         }
    }

    printf("The number of horizontal sequences : %d \n",h_count);
    printf("The number of vertical sequences : %d \n",v_count);

    fclose(fp); 
 
    return 0;
}
