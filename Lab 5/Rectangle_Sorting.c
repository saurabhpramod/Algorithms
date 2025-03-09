#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>
#include <float.h>
#include <math.h>
typedef struct {
    char *name;
    float vertex_x1;
    float vertex_y1;
    float vertex_x2;
    float vertex_y2;
} rectangle;

void make(rectangle* rectangles,int lines)
{

int found[lines];
for(int i=0;i<lines;i++)
{
    found[i]=0;
}
    for(int i=0;i<lines-1;i++)
    {
        for(int j=i+1;j<lines;j++)
        {
            if(strcmp(rectangles[i].name,rectangles[j].name)==0)
            {   

                rectangles[i].vertex_x2=rectangles[j].vertex_x1;
                rectangles[i].vertex_y2=rectangles[j].vertex_y1;
                found[j]++;

            }

        }
    }
    printf("Now reading from function: \n");
    for(int i=0;i<lines;i++)
    {
        if (found[i]==0)
        
        printf("\nRectangle name:%s \nvertex x1:%.2f \nvertex x2:%.2f \nvertex y1:%.2f \nvertex y2:%.2f \n",rectangles[i].name,rectangles[i].vertex_x1,rectangles[i].vertex_x2,rectangles[i].vertex_y1,rectangles[i].vertex_y2);
        
    
    }

}

void area(rectangle *rectangles,int lines)
{
    int num=lines/2;
    float *area=(float *)malloc(sizeof(float)*num);
   
    for(int i=0;i<num+1;i++)
    {   
       
            area[i]=fabs(((rectangles[i].vertex_x1)-(rectangles[i].vertex_x2))*((rectangles[i].vertex_y1)-(rectangles[i].vertex_y2)));
    

    }
    printf("\nNow calculating area....\n");
    for(int i=0;i<num;i++)
    {
        printf("\nName:%s \nArea: %.2f",rectangles[i].name,(area[i]));
        printf("\n");
    }


}


int main()
{
    FILE *fp;
    fp=fopen("02_rectangles.in", "r");
    

    if (fp == NULL){
        printf("Error:Cannot open 02_rectangles.in\n");
        exit(1);
    }

    printf("Now reading from file: \n");

    printf("\n");
    fseek(fp, 0, SEEK_SET);

    

    char line[100];
    int lines=0;
    char *name_temp;
    float vertex_x_temp;
    float vertex_y_temp;

    while(fgets(line,sizeof(line),fp)!=NULL)
    {
        lines++;
    }

    rewind(fp);

    rectangle *rectangles=malloc(lines* sizeof(rectangle));
    printf("Memory allocated successfully!\n");

    for(int i=0;i<lines;i++)
    {

    fgets(line,sizeof(line),fp);

    char *token=strtok(line, " ");
    
    if(token!=NULL)
    {
      name_temp=token;
    }

    token=strtok(NULL, " ");

  
    if (token != NULL) {
        // Convert the token to a float
        vertex_x_temp = atof(token);  // atof() converts a string to a float
       
    } 
    token=strtok(NULL, " ");
    if (token != NULL) {
        // Convert the token to a float
        vertex_y_temp = atof(token);  // atof() converts a string to a float
        
    } 

    rectangles[i].name=(char *)malloc(strlen(name_temp)+1);
    strcpy(rectangles[i].name,name_temp);

    printf("\nRectangle name: %s\n",rectangles[i].name);
   
    rectangles[i].vertex_x1=vertex_x_temp;
    printf("Vertex: %f\n",rectangles[i].vertex_x1);
    rectangles[i].vertex_y1=vertex_y_temp;
    printf("Vertex: %f\n",rectangles[i].vertex_y1);


}
 make(rectangles,lines);
 area(rectangles,lines);
    
    return 0;
}