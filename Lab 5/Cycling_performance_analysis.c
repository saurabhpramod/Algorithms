#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>
#include <float.h>
typedef struct {
    char *name;
    int identifier;
    int lap;
    float *time;
} cyclist;


void list(cyclist *cyclists,int num_cyclists)
{
    printf("Cyclist details: \n");

    for(int i=0;i<num_cyclists;i++)
    {
        printf(" Name: %s \t Identifier: %d \t Laps: %d \n Lap times: \t\n",cyclists[i].name,cyclists[i].identifier,cyclists[i].lap);
        for(int j=0;j<cyclists[i].lap;j++)
        {
            printf(" %.2f \n",cyclists[i].time[j]);
        }
        printf("\n");
    }
}

void detail(cyclist *cyclists, int num_cyclists, char name[30])
{
    printf("Searching for cyclist %s\n ",name );
    int found=0;
    for(int i=0;i<num_cyclists;i++)
    {
        if(strcmp(cyclists[i].name, name)==0)
        {
            found=1;
            printf("\nName: %s \nIdentifier: %d\nLaps: %d \nLap times: \n", cyclists[i].name,cyclists[i].identifier,cyclists[i].lap);
            for(int j=0;j<cyclists[i].lap;j++)
            {
                printf(" %.2f \n",cyclists[i].time[j]);
            }
            break;
        }
        
    }
    if(found==0)
    {
        printf("Cyclist not found!\n");
    }
   

}

void best(cyclist *cyclists,int num_cyclists)
{   
   float *average=(float *)malloc(num_cyclists*sizeof(float));
 float sum=0;
    for(int i=0;i<num_cyclists;i++)
    {
        for(int j=0;j<cyclists[i].lap;j++)
        {
            sum+=cyclists[i].time[j];
        }
        average[i]=sum/(cyclists[i].lap);
        printf("\nName: %s\nAverage: %.2f \n",cyclists[i].name,average[i]);
        sum=0;

    }

   float min=FLT_MAX;
   int best=0;
  
    for(int i=0;i<num_cyclists;i++)
    {   
       if(average[i]<min)
       {
          min=average[i];
          best=i;
       }
    }
    printf("\n");
    printf("\n");

    printf("Best average: " );
    printf("\nName: %s\nIdentifier: %d\nLaps: %d\n", cyclists[best].name,cyclists[best].identifier,cyclists[best].lap);
    printf("Lap times: \n");

    for(int i=0;i<cyclists[best].lap;i++)
    {
        printf("%.2f\n",cyclists[best].time[i]);
    }

    printf("\nAverage: %.2f\n",average[best]);
    printf("\n");
    free(average);

}


int main()
{
    FILE *fp;
    int choice;
    int num_cyclists;
    fp=fopen("01_cyclist.txt", "r");
    

    if (fp == NULL){
        printf("Error: impossible to open the file file.txt \n");
        exit(1);
    }

    printf("Now reading from file: \n");

    printf("\n");
    fseek(fp, 0, SEEK_SET);

    printf("Enter choice: \n");
   printf("\n 1.List\n 2.Detail\n 3.Best\n 4.Stop\n");
    scanf("%d",&choice);
    printf("You entered: %d", choice);
   getchar();

   fscanf(fp,"%d", &num_cyclists);
   printf("\nNumber of cyclists : %d \n",num_cyclists);
   fgetc(fp);

   cyclist *cyclists =malloc(num_cyclists * sizeof(cyclist));

   if (cyclists == NULL) 
   {
    perror("Memory allocation failed for cyclists array");
    fclose(fp);
    return 1;
   }

   printf("Memory allocated successfully! \n");

   printf("\n");
   printf("\n");

   for(int i=0;i<num_cyclists;i++)
   {
   char name[30];
   char line[100];
   int size;
   int identifier;
   int laps;

   fgets(line, sizeof(line), fp);

   size =strcspn(line, " ");
   strncpy(name, line, size);
   name[size] = '\0';
   //printf("Name : %s\n",name);
   cyclists[i].name = malloc((strlen(name) + 1) * sizeof(char));
   strcpy(cyclists[i].name, name);

   char *ptr = line + size + 1;  // Skip over the space after the name

   // Step 3: Extract the identifier (second word, an integer)
   size = strcspn(ptr, " ");  // Find the next space
   
   sscanf(ptr, "%d", &identifier);  // Read the integer identifier
  // printf("Identifier: %d\n", identifier);
   cyclists[i].identifier= identifier;

  
   ptr = strchr(ptr, ' ') + 1;   // Skip over the space after the name
  // Step 5: Extract the number of laps (third word, an integer)
  sscanf(ptr, "%d", &laps);    // Read the integer laps

  cyclists[i].lap=laps;
  float *time=(float *)malloc(laps*sizeof(float));
  cyclists[i].time = malloc(laps * sizeof(float));

 
  fgets(line, sizeof(line), fp);
 

   char *token = strtok(line, " ");   // Tokenize the line based on space
   int k=0;

    // Loop to extract all tokens (integers) from the line
    while (token != NULL) 
    {
        sscanf(token, "%f", &time[k]);  // Convert the token to an integer and store in the array
        k++;                           // Increment the index of the array
        token = strtok(NULL, " ");     // Get the next token
    }
    
  

    for(int j=0;j<laps;j++)
    {
        cyclists[i].time[j]= time[j];
    }


   }


    switch(choice)
    {
        case 1:
        list(cyclists,num_cyclists);
        break;

        case 2:
        char name[30];
        printf("Enter the cyclist name: \n");
        fgets(name,sizeof(name),stdin);
        size_t len = strlen(name);
        if (len > 0 && name[len - 1] == '\n') {
            name[len - 1] = '\0';  // Replace newline with null terminator
        }
      
        detail(cyclists,num_cyclists, name);
        break;

        case 3:
        best(cyclists,num_cyclists);
        break;

        case 4:
        printf("Exited successfully! \n");
        break;

        default:
        printf("Invalid choice!\n");
        break;

        for (int i = 0; i < num_cyclists; i++) {
            free(cyclists[i].name);
            free(cyclists[i].time);
        }
    
        free(cyclists);
        fclose(fp);
    }



    return 0;
}