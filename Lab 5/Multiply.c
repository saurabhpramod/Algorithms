
#include <stdio.h>


int multiply(int a, int b) 
{
    // Base case: when b is 0, return 0
    if (b == 0)
    {
        return 0;
    }
    // Recursive case: a * b is a + (a * (b - 1))
    return a + multiply(a, b - 1);
}

int main()
{
    int result=multiply(5,6);
    printf("Result: %d\n",result);
    return 0;
}