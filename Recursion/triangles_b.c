#include <stdio.h>
#include <string.h>
#include <ctype.h>  

void printRow(int n,int count)
{
   if (count==0)
   return;

   printf("%d",n);
   printRow(n, count-1);
   
}


void triangle(int n)
{
    
    if (n==0)
    return;


    triangle(n-1);
    printf("\n");
    printRow(n,n);
  
}

int main()
{
    int num;
    printf("Enter the number of rows: ");
    scanf("%d",&num);
    triangle(num);
    return 0;
}