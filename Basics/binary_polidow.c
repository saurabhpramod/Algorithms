#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int pow2(int exp);
int binary_to_decimal(char binary_string[]);

int main() {
    printf("Binary to decimal converter\n");
    printf("---------------------------\n");
    char binary_string[32];  // let's suppose we convert only 32-bit integers

    while(TRUE) {
        printf("Decimal number to convert: ");
        scanf("%s", binary_string);

        int result = binary_to_decimal(binary_string);
        if(result != -1) {
            printf("Binary: %s, Decimal: %d\n", binary_string, result);
        }
    }

    return 0;
}

int pow2(int exponent) {
    int result = 1;
    for(int i = exponent; i > 0; i--){
        result *= 2;
    }
    return result;
}

int binary_to_decimal(char binary_string[]){
    int len = strlen(binary_string);
    int decimal = 0;
    for (int i = 0; i < len; i++) {
        char bit = binary_string[i];

        // check for invalid input
        if (bit != '0' && bit != '1') {
            printf("Invalid input: %s\n", binary_string);
            return -1;
        }

        // calculate the power of 2 for the current position
        int exp = len - 1 - i;
        decimal += (bit - '0') * pow2(exp);
    }
    return decimal;
}