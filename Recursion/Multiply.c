
#include <stdio.h>


int mult(int a, int b) 
{
    // Base case: when b is 0, return 0
    if (a==0 || b == 0)
    return 0;
    
    if(b==1)
    return a;

    else if (b < 0) 
    return -a + mult(a, b+1);

    else if (b==-1)
    return -a;

    else 
    return a + mult(a, b - 1);
    
     
}

int main()
{
    int a,b;
    printf("Enter the integers to multiply: \n");
    scanf("%d%d",&a,&b);
    int result=mult(a,b);
    printf("Result: %d\n",result);
    return 0;
}