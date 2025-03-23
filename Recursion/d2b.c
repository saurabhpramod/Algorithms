#include <stdio.h>
#define MAX_S 20
#define MAX_BITS 10
#define TRUE 1


void d2b(int d, int * b, int * n)
{
    if (d==0 )
        return;
    
    b[*n]=d%2;
    *n+=1;
    return d2b(d/2,b,n);

}


int main()
{   int n=0;
    int decimal;
    int binary[MAX_BITS]={0};

    //decimal=200;

    printf("Enter the decimal to convert in range 0 to 1023:\n");
    scanf("%d",&decimal);
    if(decimal>1023)
    {
        printf("Invalid input, please enter an integer within the specified range! \n");
        return 0;
    }
    d2b(decimal, binary, &n);

    printf("Result of binary conversion: \n");
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }
    return 0;
}