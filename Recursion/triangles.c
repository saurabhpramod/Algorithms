#include <stdio.h>
#include <string.h>
#include <ctype.h>  

void printRow(int n,int count)
{
    for(int i=0;i<count;i++)
    {
        printf("%d",n);
      
    }
  
    printf("\n");
}


void triangle(int n)
{
    
    if (n==0)
    return;


    triangle(n-1);
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