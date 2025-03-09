#include <stdio.h>
#include <stdlib.h> 



int main()
{
        int num;            
        printf("Enter the dimension of the pascal triangle \n");
        scanf("%d", &num);
        int arr [num][num];


       for (int i=0;i<num;i++)
        {  
                    arr[i][0]=1;
                    arr[i][i]=1;     
        }

         for (int i = 2; i < num; i++) 
         { 

            {
        // Print leading spaces to center the numbers
        for (int j = 0; j < num - i - 1; j++)   
         {
            printf(" ");  // Add spaces before numbers
         }
                 for (int j = 1; j < i; j++)
                  {
           
                         arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
                  }
        }


          // Print the Pascal's triangle in pyramid shape
    for (int i = 0; i < num; i++) {
        // Print leading spaces to center the numbers
        for (int j = 0; j < num - i - 1; j++) {
            printf(" ");  // Add spaces before numbers
        }

        // Print the numbers in the current row
        for (int j = 0; j <= i; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");  // New line after each row
    }}



return 0;
}

