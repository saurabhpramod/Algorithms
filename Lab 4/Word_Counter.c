#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

int main()
{
    char str[50];
    printf("Please enter a string \n");
    fgets(str,sizeof(str),stdin);
    printf("You entered %s\n", str);
    int count=0;
    char updated[50];
   // char small[50];

    for(int i=0;i<strlen(str);i++)
    {
        if ((str[i]>='a' && str[i]<='z')||(str[i]>='A' && str[i]<='Z') ||(str[i]==' '))     
      {     
            updated[count]= str[i];
            count++;
        
       }
    }

        printf("The updated string with letters is:%s\n", updated);

        for(int i=0;i<strlen(updated);i++)
        {
            if(updated[i]>= 65 && updated[i]<= 90)
            {
                updated[i]= updated[i]+32;
            }
        }
        printf("The updated string in small caps is:%s\n", updated);


           /* for(int i=0;i<strlen(str);i++)
            {
                 if( ( (updated[i]==' ') && (updated[i+1]==' ') )||( (updated[i]==' ') && (updated[i-1]==' ') ) )
            {
                for(int j=i;j<strlen(str);j++)
                {
                    
                   updated[j]=updated[j+1];
                  
                }
            }
           
            }*/


            for(int i=0;i<strlen(str);i++)
            {
                while (updated[i]==' ' && updated[i+1]==' ')
            {
                for(int j=i;j<strlen(str);j++)
                {
                    
                   updated[j]=updated[j+1];
                  
                }
            }
           
            }
             printf("The updated string without spaces is:%s\n", updated);




            int pos_prev=0;
            int pos_next=0;
            char word[50];
            int index=0;

            /* for(int i=0;i<strlen(updated);i++)
             {

                if (updated[i]==' ')
                {       
                    for(int j=i;j<strlen(str);j++)
                        {while []
                        pos_next=i;
                        for(int j= pos_prev;j<pos_next;j++)
                        {
                            word[]=updated[j];
                        }
                        index ++;
                        pos_prev=pos_next;

                }

             }

            
             printf("The number of words in the updated string are %d\n", index);*/


          /*  char spaces[50];
            int j=0;
            for(int i=1;i<strlen(updated)-1;i++)
            {
               if ((updated[i]==' ')&& (updated[i+1]!= ' '))
               {
                spaces[j]=i;
                j++;
               }
                
            }
            printf("The number of words is %d:", strlen(spaces)-1);
             printf("The spaces are at position \n");
            for(int j=0;j<strlen(spaces);j++)
            {

             printf("%d \t", spaces[j]);
            }*/ 
           char word[50][50];
           int next=0;
           int prev=0;
           int k=0;
           int l=0;

            for(int i=0;i<strlen(updated);i++)
            {           
                if(updated[i]==' ')
                {
                   for(int j=i+1;j<strlen(updated);j++)
                   {
                    if (updated[j]== (' ' || '\0'))
                    {       
                        for(int k=i;k<j;k++)
                        {
                                word[l][]
                        }
                    }
                   }
                }

            }





    return 0;
}