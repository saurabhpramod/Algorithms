#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sort(int *arr,int n){ 
    // Outer loop: for each pass through the array
    for (int i = 0; i < n - 1; i++) {
        // Inner loop: compare adjacent characters
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the current character is greater than the next
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
	int *arr = NULL;
	int buffer;
	int n = 0;
	int capacity = 10;  // Initial capacity of the array

	// Dynamically allocate memory for an array of 10 integers initially
	arr = (int *)malloc(capacity * sizeof(int));
	if (arr == NULL) {
		printf("Memory allocation failed\n");
		return 1;
	}

	printf("Enter an array of integers (enter a non-integer to stop):\n");

	// Read integers from the user
	while (1) {
		if (scanf("%d", &buffer) == 1) { // If input is valid
			if (n == capacity) {
				// If capacity is full, reallocate memory to double the size
				capacity *= 2;
				int *newArr = (int *)realloc(arr, capacity * sizeof(int));
				if (newArr == NULL) {
					printf("Memory reallocation failed\n");
					free(arr);  // Free original memory before returning
					return 1;
				}
				arr = newArr;
			}
			// Store the valid integer in the array
			arr[n++] = buffer;
		} else {
			// If input is invalid (non-integer), flush the buffer
			while (getchar() != '\n');  // Flush the input buffer
			break;  // Stop input if invalid input is encountered
		}
	}

	// If no valid integers were entered, show a message
	if (n > 0) {
		// Print the array to verify
		printf("You entered: ");
		for (int i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");

		// Sort the array
		sort(arr, n);

		// Print the sorted array
		printf("The sorted array: ");
		for (int i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	} else {
		printf("No valid integers were entered.\n");
	}

	// Free the allocated memory
	free(arr);

	return 0;
}
