#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 


int main()
{
     char str[50]; 
     char updated[50];
     char result[50];
     int count=0;

     printf("Enter a string: ");
     scanf("%s", str);
     printf("You entered: %s\n", str);


     int len=strlen(str);
     printf("The length of the string is :%d\n", len);


     for(int i=0;i<len;i++)
     {
       updated[i]= str[i];
        }
   for (int i=0; i<len;i++)
   {  
       if (updated[i]!= updated[i+1])
       {
            result[count]= updated[i];
            count ++;
       }
   } 

//printf("The updated string is %s\n", result);

int outer=0;
int inner=0;
int freq=0;
for(int i = outer;i<strlen(result);i++)
{
   for (int j=inner;j<strlen(updated);j++)
   {
        if (result[i]==updated[j])
        {
           inner++;
           freq++;
        }
        else 
        {
            outer ++;
            
        }

   }

   if(freq>1)
   {
      printf( "%c%d",result[i],freq);
     
   }
   if (freq==1)
      {
        printf("%c", result[i]);
      }

           freq=0; 
}
  return 0;
}