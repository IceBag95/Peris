#include <stdio.h>
#include <math.h>

int main() {

    int x;
    
    printf("How many prime numbers to calculate? ");

    do {
        printf("\nΠαρακαλώ εισάγετε θετικό αριθμό: ");
        scanf("%d", &x);
    } while ( x <= 0 );

    int counter = 1;
    int i = 2;
    while (counter <= x) {
        int is_prime = 1;

        for (int j = 2; j <= sqrt(i); j++){

            if (i % j == 0) {
                is_prime = 0;
            }
        }

        if (is_prime == 1) {
            printf("\nPrime #%d: %d",counter, i);
            counter++;
        }

        i++;
    }

    return 0;
}
