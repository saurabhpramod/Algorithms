#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>


int main()
{
    char str[50];
    char small[50];
    char *token;
    char word[50][50];
    int k=0;
    char delimiters[] = " ,.!?;:-—\n\"\'*";

    printf("Enter a string \n");
    fgets(str,sizeof(str), stdin);
    printf("You entered %s \n", str);
    
  
    void toLower(char str[])
    {
        for(int i=0;i<strlen(str);i++)
        {
           str[i]=tolower(str[i]);
        }
        
    }
    toLower(str);

    


    

    token=strtok(str,delimiters);


    while(token!= NULL)

    {  
        for(int j=0;j<strlen(token);j++)
        
        {

            word[k][j]= token[j];
            
        }
        word[k][strlen(token)] ='\0';
        token=strtok(NULL,delimiters);
        k++;
    
    }


    int count[50]={0};
    for(int i=0;i<k;i++)
    {
        for(int j=i+1; j<k;j++)
        {
            if(strcmp(word[i], word[j])==0) 
            {
                count[i]++;
            }
        }
    }

    int found[50]={0};

    for(int i=0;i<k;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(strcmp(word[i],word[j])==0)
            {
                found[i]++;
            }
        }
    }


       printf("The word frequency is: \n");

         for(int i=0;i<k;i++)
          {
            if(found[i]==0)
             {
                 printf("%s \t %d \n", word[i], count[i]+1 );
             }
          }
    
    
    return 0;

}