#include <stdio.h>
#include <stdlib.h>

int main() {

    int x;
    int myArray[10];

    for (int i = 0; i < 10; i++){
        printf("\nPlease enter an integer: ");
        scanf("%d", &x);
        myArray[i] = x;
    }

    printf("\n");

    int max = abs(myArray[0]);
    int increasingOrder = 1; // Υποθέτω οτι ο πίνακας έιναι σε αύξουσα σειρα
    int decreasingOrder = 1; // Υποθέτω οτι ο πίνακας έιναι σε φθίνουσα σειρα
    for (int i = 1; i < 10; i++){
        if (myArray[i] > myArray[i-1]){
            decreasingOrder = 0;
        }
        if (myArray[i] < myArray[i-1]){
            increasingOrder = 0;
        }
        if (abs(myArray[i]) > abs(max)) {
            max = abs(myArray[i]);
        }
    }

    if (increasingOrder && decreasingOrder) {
        printf("Ο πίνακας έχει σε όλες τις θέσεις την ίδια τιμή (%d)", myArray[0]);
        printf("\nMax: %d", max);
    }
    else if (increasingOrder) {
        printf("Ο πίνακας είναι ταξινομημένος σε αύξουσα σειρά");
        printf("\nMax: %d", max);
    }
    else if (decreasingOrder) {
        printf("Ο πίνακας είναι ταξινομημένος σε φθίνουσα σειρά");
        printf("\nMax: %d", max);
    }
    else {
        printf("Ο πίνακας δεν είναι ταξινομημένος");
        printf("\nMax: %d", max);
    }

    printf("\n");

    return 0;
}