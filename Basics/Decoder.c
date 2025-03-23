#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>

void encoder()
{  

     char str[50]; 
     char updated[50];
     char result[50];
     int count=0;
   

     printf("Enter the string to encode: ");
     scanf("%s", str);
     printf("You entered: %s \n",str);
     
     for(int i=0;i<strlen(str);i++)
     {
       updated[i]= str[i];
     }


   for (int i=0;i<strlen(str);i++)
   {  
       if (updated[i]!= updated[i+1])
       {
            result[count]= updated[i];
            count ++;
       }
   } 

int outer=0;
int inner=0;
int freq=0;
printf("The encoded string is: ");

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

}

void decoder()
{
    char str[50]; 
    char updated[50];
    int count = 1; // default count is 1
    int len = 0;

    printf("Enter the string to decode: \n");
    scanf("%s", str);
    printf("You entered: %s \n", str);
    
    // Loop through the string and decode it
    for (int i = 0; i < strlen(str); i++) {
        // If the current character is a digit, it tells us how many times the previous character should be printed
        if (isdigit(str[i])) {
            count = str[i] - '0';  // Convert the character to the integer (for example '3' becomes 3)
        } else {
            // Print the character 'count' times
            for (int j = 0; j < count; j++) {
                printf("%c", str[i]);  // Print the character 'count' times
            }
            count = 1;  // Reset count after printing the character
        }
    }
    printf("\n"); // Newline at the end of the output
}


int main()
{
     int choice;

     printf("Enter your choice \n 1.Encode \n 2.Decode \n 3.Exit \n");
     scanf("%d",&choice);

     switch(choice)
     {
        case 1:
        encoder();
        break;

        case 2:
        decoder();
        break;

        case 3:
        printf("Exited successfully! \n");
        break;

        default:
        printf("Invalid choice! \n");

     }

  return 0;
}