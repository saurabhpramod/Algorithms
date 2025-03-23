#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>


typedef struct student_s {
    int studentID;
    char name[100];
    char major[50];
    int year;
    float gpa;
    struct student_s * next;
    }student_t;
  

    student_t *student_new()
    {
        {
            // Allocate memory for a new student record
            student_t *current = (student_t *)malloc(sizeof(student_t));
            
            if (current == NULL) {
                // Check if memory allocation was successful
                printf("Memory allocation failed!\n");
                return NULL;
            }
        
            // Initialize all fields to default values (optional)
            current->studentID = 0;
            current->name[0] = '\0';  // Empty string
            current->major[0] = '\0';  // Empty string
            current->year = 0;
            current->gpa = 0.0;
            current->next = NULL; // Pointing to no next student initially
        
            return current;  // Return the pointer to the allocated student
        }
    }
 
    void student_add(student_t *head, char *name, char *major, int year, float gpa)
    {
        
       int len_student=strlen(name);
       int len_major=strlen(major);
        student_t *new_student=(student_t *)malloc(sizeof(student_t));
        if (new_student == NULL) 
        {
            printf("Memory allocation failed for new student.\n");
            return;
        }

        if(len_student<=100)
        {
        strcpy(new_student->name, name); 
        }
        else{
            printf("Name too long! \n");
        }

        if(len_major<=50)
        {
            strcpy(new_student->major, major);
        }
        else{
            printf("Major too long!\n");
        }
        new_student->year=year;
        new_student->gpa=gpa;
        new_student->next=NULL;
        
        
        if (head == NULL)
        {
            head = new_student;
        } 
        else
        {
            student_t *temp=head;
        
            while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new_student;

        }
      

    }


    void student_free(student_t *s)
    {
        free(s);
    }


    void student_delete(student_t *head, int id)
    {
        student_t *temp=head;
        student_t *prev=NULL;
          // Check if the list is empty
    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }

     // If the head node itself holds the ID to be deleted
     if (temp != NULL && temp->studentID == id) {
        head = temp->next;  // Change head to the next node
        student_free(temp);  // Free the memory of the deleted student
        printf("Student with ID %d deleted.\n", id);
        return;
    }

    // Traverse the list to find the student with the matching ID
    while (temp != NULL && temp->studentID != id) {
        prev = temp;
        temp = temp->next;
    }

    // If the student ID was not found
    if (temp == NULL) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    // Remove the student from the list
    prev->next = temp->next;
    student_free(temp);  // Free the memory of the deleted student
    printf("Student with ID %d deleted.\n", id);
     
    }


    void students_display(student_t *head)
    {
        student_t *temp=head;
        while(temp!=NULL)
        {
            printf("\n student ID:%d\n name:%s\n major:%s\n year:%d\n GPA:%.2f\n",temp->studentID,temp->name,temp->major,temp->year,temp->gpa);
        }
        temp=temp->next;
    }


    student_t *student_search(student_t *head, int id) 
    {
        student_t *temp=head;
        while(temp!=NULL&&temp->studentID!=id)
        {
            temp=temp->next;
        }
        if(temp!=NULL&&temp->studentID==id)
        {
            printf("\n student ID:%d\n name:%s\n major:%s\n year:%d\n GPA:%.2f\n",temp->studentID,temp->name,temp->major,temp->year,temp->gpa);
            return temp;
        }
        else
        {
            printf("Student ID:%d not found",id);
          return NULL;
        }
    }

int main()
{
    
    return 0;
}