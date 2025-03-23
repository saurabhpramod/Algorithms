

#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>

char *morse[46];
char alpha[46];
int choice;

void encode(char input[])
{
    for(int i=0;i<strlen(input);i++)
    {
        for(int j=0;j<47;j++)
        {
           if(input[i]==alpha[j])
            {
              printf("%s ",morse[j]);
              break;
            }
        }
     }  
}

void decode(char input[])
{
    // Remove any trailing newline character from fgets input
    input[strcspn(input, "\n")] = '\0';

    // Split the Morse code input by spaces
    char *token = strtok(input, " ");  // Get the first Morse code symbol

    while (token != NULL)
    {
        // Check each Morse code symbol against the known Morse codes
        for (int k = 0; k < 46; k++)
        {
            if (strcmp(token, morse[k]) == 0)  // If match is found
            {
                printf("%c", alpha[k]);  // Print corresponding character
                break;
            }
        }
        token = strtok(NULL, " ");  // Get the next Morse symbol
    }
    printf("\n");
}

int main()
{

alpha[0]='A';
alpha[1]='B';
alpha[2]='C';
alpha[3]='D';
alpha[4]='E';
alpha[5]='F';
alpha[6]='G';
alpha[7]='H';
alpha[8]='I';
alpha[9]='J';
alpha[10]='K';
alpha[11]='L';
alpha[12]='M';
alpha[13]='N';
alpha[14]='O';
alpha[15]='P';
alpha[16]='Q';
alpha[17]='R';
alpha[18]='S';
alpha[19]='T';
alpha[20]='U';
alpha[21]='V';
alpha[22]='W';
alpha[23]='X';
alpha[24]='Y';
alpha[25]='Z';
alpha[26]='0';
alpha[27]='1';
alpha[28]='2';
alpha[29]='3';
alpha[30]='4';
alpha[31]='5';
alpha[32]='6';
alpha[33]='7';
alpha[34]='8';
alpha[35]='9';
alpha[36]='.';
alpha[37]=',';
alpha[38]=':';
alpha[39]='!';
alpha[40]='?';
alpha[41]='\'';
alpha[42]='-';
alpha[43]='/';
alpha[44]='@';
alpha[45]='=';


morse[0]=".-";
morse[1]="-...";
morse[2]="-.-.";
morse[3]="-..";
morse[4]=".";
morse[5]="..-.";
morse[6]="--.";
morse[7]="....";
morse[8]="..";
morse[9]=".---";
morse[10]="-.-";
morse[11]=".-..";
morse[12]="--";
morse[13]="-.";
morse[14]="---";
morse[15]=".--.";
morse[16]="--.-";
morse[17]=".-.";
morse[18]="...";
morse[19]="-";
morse[20]="..-";
morse[21]="...-";
morse[22]=".--";
morse[23]="-..-";
morse[24]="-.--";
morse[25]="--..";
morse[26]="-----";
morse[27]=".----";
morse[28]="..---";
morse[29]="...--";
morse[30]="....-";
morse[31]=".....";
morse[32]="-....";
morse[33]="--...";
morse[34]="---..";
morse[35]="----.";
morse[36]=".-.-.-";
morse[37]="--..--";
morse[38]="---...";
morse[39]="-.-.--";
morse[40]="..--..";
morse[41]=".----.";
morse[42]="-....-";
morse[43]="-..-.";
morse[44]=".--.-.";
morse[45]="-...-";


printf("\n Please enter your choice: \n 1.Encode\n 2.Decode\n 3.Exit \n");
scanf("%d",&choice);
printf("\n You entered: %d \n",choice);
getchar();

char input[50];
switch(choice)
{
    case 1: 
    printf("Please enter the string to encode \n");

    fgets(input,sizeof(input),stdin);

    for(int i=0;i<strlen(input);i++)
    {
        input[i]=toupper(input[i]);
    }
    input[strlen(input)]='\0';
   
    encode(input);

    break;

    case 2:
    printf("Please enter the string to decode \n");

    fgets(input,sizeof(input),stdin);

    decode(input);
    break;

    case 3:
    break;

    default:
    printf("Invalid choice! \n");
}

return 0;
}



