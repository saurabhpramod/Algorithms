#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

int main()
{
  
    char str[50]; 
    int str_new[12]; // Declare an array to store the string
    printf("Enter a number: ");
     fgets(str, sizeof(str), stdin);
  
    printf("You entered: %s\n", str);


    if (strlen(str)<2)
    {
        printf("The input is invalid: \n");
    }
    else
        for(int i=0;i<strlen(str);i++)
        {
            while (str[i] ==' ')
            {
                for(int j=i;j<strlen(str);j++)
                {
                str[j]=str[j+1];
            
                }
            }
        }
    printf("The updated input is %s:\n", str);
  
    int len= strlen(str);
    printf("The string length is %d: \n",len-1);
       if (len!=13)
          {
            printf(" The string length is invalid \n");
          }
          else 
          {
                printf("The string length is valid \n");

                
          }
    }

   int temp;
    for(int i=0;i<12;i++)
    {   

        temp = str[i] - '0';
     
        if(i%2 !=0)
        {
       
             temp=temp*2;
                 if (temp > 9)
                {  temp = temp-9;
                }
                
                        
       str_new[i]=temp;
       }

       if(i%2 ==0)
       {
        str_new[i]= temp;
       }
       
    }

      printf("The processed input is : ");

    for(int i =0;i<12;i++)
    {
    printf("%d ",str_new[i]);

    }

int res=0;
    for(int i=0;i<12;i++)
    {
        res= res+ str_new[i];
    }

    printf("\n The sum of the processed digits is : %d\n", res );


    if(res%10 == 0)
    {
        printf("The result is a Luhn number\n");
    }
    else 
    {
        printf("The result is not a Luhn number\n");
    }
    return 0;
}
