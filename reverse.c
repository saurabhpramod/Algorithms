


#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 




int main()
{ 
    int arr[10];
    int *ptr_int= arr;

    printf("Enter a list of 10 numbers \n");
    for(int i=0;i<10;i++)
    {
            scanf("%d",&arr[i]);
    }
    

    printf("You entered: \n");
    for(int j=0;j<10;j++)
    {
        printf("%d \t", arr[j]);
    }


    printf("\n");

   
    int *ptr_start= ptr_int;
    int *ptr_end= (ptr_int+9);


   for (int i = 0; i < 5; i++) {  // Only need to loop for half the array
        // Swap values at ptr_start and ptr_end
        int temp = *ptr_start;       // Store value at ptr_start
        *ptr_start = *ptr_end;       // Assign value at ptr_end to ptr_start
        *ptr_end = temp;             // Assign stored value (temp) to ptr_end

        // Move the pointers towards each other
        ptr_start++;  // Increment to next element
        ptr_end--;    // Decrement to previous element
    }
        
    

    


    printf("The reversed list is :\n");
    for(int i=0;i<10;i++)
    {

        printf("%d \t", *(ptr_int+i) );


    }

  
    return 0;
}
   