#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>


int main()
{
    char str[50];
    char small[50];
    printf("Enter a string : ");
    fgets(str,sizeof(str), stdin);
   // printf("You entered : %s \n", str);

    void toLower(char str[])
    {
        for(int i=0;i<strlen(str);i++)
        {
           str[i]=tolower(str[i]);
        }
        
    }
    toLower(str);
    

    char *token;
    char word[50][50];
    token=strtok(str," ");
    int k=0;
    
    while(token!= NULL)
    {  
        
          for(int j=0;j<strlen(token);j++)
          {
            word[k][j]= token[j];
          }

          word[k][strlen(token)] ='\0';
          token=strtok(NULL," ");

          if(token != NULL && strlen(token)>0) 
          {
            k++;

          }
          
          

    }
       


    printf("The tokens : \n");
    
    int frq[50]={0};


    for(int i=0;i<k;i++)
    {
          printf("%d --------> %s \n", i+1, word[i]);
        
    }

    for(int i=0;i<k-1;i++)
    {
        for(int j=i+1;j<k;j++)
        {
            if(strcmp(word[i],word[j])==0)
            {   
                  frq[i]++;
            }
        }
    }

   
    int found[50]={0};

    for(int i=0;i<k-1;i++)
    {
        for(int j=i+1;j<k;j++)
        {
            if(strcmp(word[i],word[j])==0)
            {
                found[j]=1;
            }
        }
    }

    printf("\n");
    printf("\n");
    printf("\n");

   printf("Word frequency: \n");

    for(int i=0;i<k;i++)
    {
        if(found[i]==0)
        {
            printf("%s -----> %d \n",word[i],frq[i]+1);
        }
    }


    
    return 0;

}