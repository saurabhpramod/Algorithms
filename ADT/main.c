#include <stdio.h>
#include <time.h>
#include <string.h>
#include "list.h"
#include "task.h"

#define MAX_DESCR 100

void simulate(list_t *);
void time_to_string(long int, char *);
void clear_input_buffer();

int main() {

    list_t * l = list_new();
    int flag = 1; 
    int option;
    int id;
    int priority;
    char description[MAX_DESCR];
    while(flag) {
        printf("Task Manager\n");
        printf("--------------------------------\n");
        printf("Type 1 to add a task\n");
        printf("Type 2 to find a task by ID\n");
        printf("Type 3 to remove a task by ID and display it\n");
        printf("Type 4 to display all tasks\n");
        printf("Type 5 to modify the priority of an existing task\n");
        printf("Type 6 to exit and simulate task execution\n");
        printf("--------------------------------\n");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                // Create a new task and set its priority and description
                task_t *t0 = task_new();
                if (t0 == NULL) {
                    printf("Error: Unable to create new task.\n");
                    break;
                }

                printf("Insert priority: ");
                if (scanf("%d", &priority) != 1) {
                    printf("Error: Invalid priority input.\n");
                    clear_input_buffer();
                    task_free(t0);
                    break;
                }
                getchar(); 

                task_set_priority(t0, priority);

                printf("Insert description: ");
                fgets(description, 100, stdin);
                if (description[strlen(description) - 1] == '\n') {
                    description[strlen(description) - 1] = '\0';
                }
                task_set_description(t0, description);

                list_insert(l, t0, task_compare_priority);
                break;
            }

            case 2: {
                // Search for a task by ID and print it
                printf("Insert ID: ");
                if (scanf("%d", &id) != 1) {
                    printf("Error: Invalid ID input.\n");
                    break;
                }
                
                task_t *found_task = list_search(l, &id, task_compare);
                if (found_task == NULL) {
                    printf("Task with ID %d not found.\n", id);
                } else {
                    task_print(found_task, stdout);
                }
                break;
            }

            case 3: {
                // Remove a task by ID and print it
                printf("Insert ID: ");
                if (scanf("%d", &id) != 1) {
                    printf("Error: Invalid ID input.\n");
                    break;
                }

                task_t *removed_task = list_remove(l, &id, task_compare);
                if (removed_task == NULL) {
                    printf("Task with ID %d not found.\n", id);
                } else {
                    task_print(removed_task, stdout);
                    task_free(removed_task); // Free memory of removed task
                }
                break;
            }

            case 4:
                // Print all tasks in the list
                list_print(l, stdout, task_print);

                break;

            case 5: {
                // Update a task's priority and description while keeping the same ID
                printf("Insert ID: ");
                if (scanf("%d", &id) != 1) {
                    printf("Error: Invalid ID input.\n");
                    break;
                }
                getchar();  // Consume the newline

                task_t *temp_task = list_search(l, &id, task_compare);
                if (temp_task == NULL) {
                    printf("Task with ID %d not found.\n", id);
                    break;
                }

                // Copy the existing description of the task
                strncpy(description, task_get_description(temp_task), sizeof(description) - 1);
                description[sizeof(description) - 1] = '\0';

                // Remove the old task
                task_t *old_task = list_remove(l, &id, task_compare);
                if (old_task == NULL) {
                    printf("Error: Task removal failed.\n");
                    break;
                }

                // Create a new task with updated priority
                task_t *new_task = task_new();
                if (new_task == NULL) {
                    printf("Error: Unable to create new task.\n");
                    task_free(old_task);
                    break;
                }


                printf("Insert new priority: ");
                if (scanf("%d", &priority) != 1) {
                    printf("Error: Invalid priority input.\n");
                    clear_input_buffer();
                    task_free(old_task);
                    task_free(new_task);
                    break;
                }
                task_set_priority(new_task, priority);
                task_set_description(new_task, description);

                // Insert the new task into the list and free the old task's memory
                list_insert(l, new_task, task_compare_priority);
                task_free(old_task);
                break;
            }

            case 6:
                // Exit the loop by setting the flag to 0
                flag = 0;
                break;

            default:
                // Handle invalid options
                printf("Invalid option\n");
                break;
        }
    }

        // Call the simulation and release all memory
        simulate(l);
        list_free(l, task_free);
        return 0;
}

void simulate(list_t * task_list){
    task_t * curr_task;
    printf("Task Execution Simulation Starting...\n");
    time_t timestamp = time(NULL);
    char timestamp_str[30];
    int task_num = 1;
    while((curr_task = (task_t *)list_front(task_list)) != NULL)
    {
        printf("%d. Executing task\n", task_num++);
        time_to_string(timestamp, timestamp_str);
        printf("\tStarting UTC Time:\t%s\n", timestamp_str);
        printf("\tTask data: ");
        task_print(curr_task, stdout);
        list_remove(task_list, curr_task, task_compare);
        timestamp += task_get_duration(curr_task);
        time_to_string(timestamp, timestamp_str);
        printf("\tEnding UTC Time:\t%s\n", timestamp_str);
        task_free(curr_task);
        printf("Task completed and removed from the list.\n\n");
    }
}

void time_to_string(long int timestamp, char * buffer){
    struct tm *utc_time;
    utc_time = gmtime(&timestamp);
    strftime(buffer, 30, "%Y-%m-%d %H:%M:%S UTC", utc_time);
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);  // Pulisce fino al newline o EOF
}