#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "sort_util.h"
#include "list.h"


#define N 100



int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "usage: %s <filename> -<sorting_algorithm> -<slots>\n", argv[0]);
        return 1;
    }

    students_list_t* students = init_wrapper();
    load_data(argv[1], students);
    //sort_list(students, argv[2][1]);
    int slots = assign_slots(students, atoi(++argv[3]));
    display(students, slots);

    return EXIT_SUCCESS;
}