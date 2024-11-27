#include <stdio.h>

int main() {

    int x;

    do {
        printf("\nPlease enter a possitive number: ");
        scanf("%d", &x);
    } while (x <= 0);

    while ( x >= 10 ) {
    
        int digit_counter = 1;
        int divisor = 10;
        
        while (x != x % divisor) {
            divisor = divisor * 10;
            digit_counter++;
        }

        divisor = divisor / 10;
        
        int sum = 0;
        for (int i = 0; i < digit_counter; i++) { 
            sum = sum + (x / divisor);
            x = x % divisor;
            divisor = divisor / 10;
        }

        x = sum;
    }

    printf("\n\nFinal sum of digits: %d", x);
    printf("\n\n");

    return 0;
}