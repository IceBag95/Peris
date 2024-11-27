#include <stdio.h>

int main() {

    // δηλώνω τη μεταβλητή στην οποία θέλω να αποθηκεύσω την είσοδο του χρήστη
    int x;

    // διαβάζω επαναληπτικά μέχρι ο αρθμός να είναι θετικός
    do {
        printf("\nPlease enter a possitive number: ");
        scanf("%d", &x);
    } while (x <= 0);


    // Πάω να μετρήσω πόσα ψηφία έχει ο αριθμός 

    while ( x >= 10 ) {
    
        int digit_counter = 1; //Σίγουρα ο αριθμός θα έχει ένα ψηφίο άρα ξεκινάω από το 1
        int divisor = 10; // θα το δούμε αναλυτικά σήμερα το γιατί
        
        // Βρίσκω πόσα ψηφία έχει ο αριθμός διαιρώντας τον συνεχώς με μεγαλύτερα πολ/σια του 10
        while (x != x % divisor) {
            divisor = divisor * 10;
            digit_counter++;
        }

        // Το πολ/σιο του 10 που δεν μπορεσε να διαιρέσει τον x σταμάτησε την επανάληψη.
        // Για να συνεχίσω, δεν χρειάζομαιπολ/σιο του 10 που σταμάτησε την επανάληψη, αλλά το ακριβώς προηγούμενο.
        divisor = divisor / 10;
        
        printf("\nGiven number: %d", x);
        printf("\nNumber has %d digits", digit_counter);
        printf("\nMax divisor: %d", divisor);
        printf("\n");

        
        int sum = 0; // αρχίζω ένα άθροισμα για να προσθέσω όλα τα ψηφία που θα υπολογίζω

        // Ξεκινάω από το μεγαλύτερο πολλαπλάσιο του 10 που διαιρεί τον αριθμό. 
        // Διαιρώ το x με αυτό το πολλαπλάσιο και πάιρνω το ψηφίο που θέλω. 
        // το προσθέτω στο sum
        // Στη συνέχεια κρατάω το υπόλοιπο της διαίρεση (που είναι τα υπόλοιπα ψηφία του αριθμου που έμειναν)
        // Διαιρώ το πολ/σιο του 10 που χρησιμοποιησα στη διαίρεση, με 10 για να πάρω το προηγούμενο πολ/σιο. 
        // συνεχίζω την επανάληψη μεχρι να τελειώσει
        // Η επανάληψη τρέχει για όλα τα ψηφία (γι αυτό υπολόγισα το digit_counter)
        for (int i = 0; i < digit_counter; i++) { 
            sum = sum + (x / divisor);
            x = x % divisor;
            divisor = divisor / 10;
            printf("\nIteration: %d", i+1);
            printf("\nDigit to be added to sum: %d", (x / divisor));
            printf("\n");
        }     

        printf("\n\nCurrent sum of digits: %d", sum);
        printf("\n\n");

        x = sum;
    }

    // Εμφανίζω το sum
    printf("\n\nFinal sum of digits: %d", x);
    printf("\n\n");

    return 0;
}