#include <stdio.h>
#include <string.h>
#include <ctype.h>  

int isPalindrome(char * s, int l)
{
    if (l==0||l==1)
    return 1;

    if(*s!=s[l-1])
    return 0;

    return isPalindrome(s+1,l-2);
}

void toLower(char *s)
{
    while(*s!= '\0')
   
   { 
     *s=tolower(*s);
      s++;
   }
}

void removeSpaces(char *s)
{  
    int j=0;
    int len=strlen(s);
    char buffer[len];
    char *temp=s;

    while(*temp != '\0' )
    {
        if(*temp != ' ')
        {
            
            buffer[j]= *temp;
            j++;
        }
        temp++;
       
    }
    
    buffer[j] = '\0'; 
    strcpy(s,buffer);
}


void removePunct(char *s)
{   
    int j=0;
    int len=strlen(s);
    char buffer[len];
    char *temp=s;

    while(*temp != '\0' )
    {
        if(isalnum(*temp))
        {
            buffer[j]=*temp;
            j++;
        }
        temp++;
       
    }
    buffer[j] = '\0'; 
    strcpy(s,buffer);
}
int main()
{
    char *str=NULL;
    char arr[100];
    str=arr;
    printf("Enter a string: \n");
    fgets(arr, sizeof(arr), stdin);
    arr[strcspn(arr, "\n")] = '\0';


    toLower(str);
   // printf("The updated string from toLower:%s\n",str);
    removeSpaces(str);
   // printf("The updated string from removeSpaces:%s\n",str);
    removePunct(str);
   // printf("The updated string from removePunct:%s\n",str);
   

    int len=strlen(arr);
    int pal=isPalindrome(str,len);

    if(pal==0)
    {
        printf("The string is not Palindrome!\n");
    }
    else
    {
      printf("The string is Palindrome!\n");
    }
    return 0;
}