#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>
#include <time.h>


void bubble_sort(int *arr,int n)
{ 
  
    // Outer loop: for each pass through the array
    for (int i = 0; i < n - 1; i++) {
        // Inner loop: compare adjacent characters
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the current character is greater than the next
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}



void selection_sort(int *arr,int n)
{

    for(int i=0;i < n - 1;i++)
    {
        int min=i;

        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
            if (min!= i) // Only swap if a smaller element was found
            {
                int temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
            }
        

    }
}


void insertion_sort(int *arr,int n)
{
    for(int i=1;i<n;i++)
    {
        int temp=arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
       
        }
        arr[j+1]=temp;
    }

}

int main()
{   
    int *arr_a=NULL;
    int *arr_b=NULL;
    int *arr_c=NULL;
    int list_a[7]={9,4,7,2,3,4,2};
    int list_b[7]={12,23,34,11,5,54,24};
    int list_c[7]={93,43,21,34,8,2,4};
    arr_a=list_a;
    arr_b=list_b;
    arr_c=list_c;
    int num=7;

   // int val;
   // val = rand();
    clock_t tic = clock();
    selection_sort(arr_a,num);
    clock_t toc = clock();

    printf("\nSelection sorting: \n");
    for(int i=0;i<num;i++)
    {
        printf("%d ",arr_a[i]);
    }

    double time_spent_a = (double)(toc - tic) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_spent_a);


    clock_t start = clock();
    bubble_sort(arr_b,num);
    clock_t end = clock();

    printf("\nBubble sorting: \n");
    for(int i=0;i<num;i++)
    {
        printf("%d ",arr_b[i]);
    }

    double time_spent_b = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_spent_b);


    clock_t top = clock();
    insertion_sort(arr_c,num);
    clock_t down = clock();

    printf("\nInsertion sorting: \n");
    for(int i=0;i<num;i++)
    {
        printf("%d ",arr_c[i]);
    }

    double time_spent_c = (double)(down - top) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_spent_c);

    return 0;
}