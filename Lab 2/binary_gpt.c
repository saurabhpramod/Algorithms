#include <stdio.h>

// Function to calculate base raised to the power of n
int power(int base, int n) {
    int res = 1;
    for (int i = 0; i < n; i++) {
        res *= base;  // Multiply base by itself n times
    }
    return res;
}

int main() {
    int num;
    int bin;
    int dec = 0;

    printf("Please enter the number of digits \n");
    scanf("%d", &num);
    printf("The number of digits is %d\n", num);

    int arr[num];  // Array to hold binary digits

    printf("Please enter the binary number \n");
    scanf("%d", &bin);
    
    // Store the digits in reverse order
    for (int i = 0; i < num; i++){
        arr[i] = bin % 10;   // Extract the least significant digit
        bin = bin / 10;      // Remove the least significant digit
    }

    // Print the binary number stored in arr[] (in reverse order)
    printf("The binary number is: ");
    for (int i = num - 1; i >= 0; i--) {
        printf("%d", arr[i]);  // Print in the correct order
    }
    printf("\n");

    // Convert the binary number to decimal
    for (int i = 0; i < num; i++) {
        int exp = power(2, i);  // Calculate 2^i
        int res = exp * arr[i]; // Multiply by the corresponding binary digit
        dec += res;             // Add to the result
    }

    // Output the final decimal result
    printf("The result in decimal is: %d\n", dec);

    return 0;
}
