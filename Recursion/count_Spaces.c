#include <stdio.h>
#include <string.h>

int countSpace(char *s)
{
    int count=0;
    if(*s =='\0')
    return 0;


    if(*s== ' ')
    {
        count++;
        return 1+ countSpace(s+1);
    }
    else 
    {
        return countSpace(s+1);
    }
}

int main()
{
    char *str=NULL;
    char arr[100];
    str=arr;
    printf("Enter a string:\n");
    fgets(str,sizeof(arr),stdin);
    int num_spaces= countSpace(str);

    printf("The number of white spaces: %d\n",num_spaces);
    return 0;
}