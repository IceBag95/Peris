#include <stdio.h>

int main() {

    int x;
    do{
        printf("\nPlease enter a possitive number: ");
        scanf("%d", &x);
    }while (x <= 0);

    int digit_counter = 1;
    int divisor = 10;
    while (x != x % divisor) {
        divisor = divisor * 10;
        digit_counter++;
    }

    divisor = divisor / 10;
    
    printf("\nGiven number: %d", x);
    printf("\nNumber has %d digits", digit_counter);
    printf("\nMax divisor: %d", divisor);
    printf("\n");

    int sum = 0;
    for (int i = 0; i < digit_counter; i++) {
        int digit_extracted = x / divisor;
        sum = sum + (x / divisor);
        x = x % divisor;
        divisor = divisor / 10;
        printf("\nIteration: %d", i+1);
        printf("\nDigit to be added to sum: %d", digit_extracted);
        printf("\n");
    }     

    printf("\n\nSum of digits: %d", sum);
    printf("\n\n");
    return 0;
}