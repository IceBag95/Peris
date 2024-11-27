#include <stdio.h>
#include <math.h>

int main() {

    int N;
    
    printf("How many prime numbers to calculate? ");

    do {
        printf("\nPlease enter possitive number: ");
        scanf("%d", &N);
    } while ( N <= 0 );

    int counter = 1;
    int n = 10;
    while (counter <= N) {
        int is_prime = 1;

        for (int i = 2; i <= sqrt(n); i++){
            if (n % i == 0) {
                is_prime = 0;
            }
        
        }

        if (is_prime == 1) {
            printf("\nPrime #%d: %d",counter, n);
            counter++;
        }

        n++;
    }

    printf("\n");
    return 0;
}
