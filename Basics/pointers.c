#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>

int main() {
    int *ptr;
    ptr = (int *)malloc(sizeof(int));  // Memory allocation for one integer
    
    if (ptr == NULL) {  // Check if memory allocation failed
        printf("Memory allocation failed\n");
        return 1;
    }

    *ptr = 42;  // Use the allocated memory
    printf("Value: %d\n", *ptr);

    int **ptrptr;
    ptrptr=&ptr;
    printf("The address of pointer is %p and the address of pointer to pointer is %p \n",ptr,ptrptr);
    printf("The address of next pointer is %p and the address of next pointer to pointer is %p \n",ptr+1,(ptrptr+1));
    printf("The size of pointer is %d bytes and the size of pointer to pointer is %d bytes \n",sizeof(ptr),sizeof(ptrptr));

    free(ptr);  // Free the memory when done

    return 0;
}
