/* Example on how to read a file char by char and check horizontal and vertical sequences */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
    FILE *fp;
 
    char file[50]; 
    char ch; //to store char buffer
    char h;//char to be searched horizontally
    char v;// char to search vertically

   printf("Enter the file to read \n");  //accept the file to be read
   fgets(file,sizeof(file),stdin);
   file[strcspn(file, "\n")] = '\0';  //add whitespace 
   printf("You entered %s",file);

    printf("\n Enter the characters to search horizontally and vertically \n");
    scanf(" %c %c",&h,&v); //accept the characters to be searched
    getchar(); //consume whitespace
   
    fp = fopen(file, "r");  //open file in r mode
 
    if (fp == NULL){
        printf("Error: impossible to open the file file.txt\n");
        exit(1);
    }//check if file is empty

  
    printf("\n");
    fseek(fp, 0, SEEK_SET);//set pointer to beginning of file


    int arr[100][100]={0};  //array to store file contents line by line 
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
     
    }  //check file content char by char and shift rows on '\n'


    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            printf("%c",arr[i][j]);
        }
    }//print array contents


    int v_count=0;  //counter to count v sequences
    int h_count=0; //counter to count h sequences

    for(int i=0;i<100;i++)
    {
        

         for(int j=0;j<100;j++)
         { 
            if((arr[i][j])==v &&(arr[i+1][j])==v &&(arr[i+2][j])==v && (arr[i+3][j])==v &&(arr[i+4][j])==v)
            {
                    v_count++;
            }
            if((arr[i][j])==h &&(arr[i][j+1])==h &&(arr[i][j+2])==h && (arr[i][j+3])==h &&(arr[i][j+4])==h)
            {
                    h_count++;
            }
         }
    }//check if h or v seqeunces from array match 

    printf("The number of 5 consecutive horizontal sequences of %c: %d \n",h,h_count);//print number of sequences
    printf("The number of 5 consecutive vertical sequences of %c: %d \n",v,v_count);

    fclose(fp); //close file
 
    return 0;
}