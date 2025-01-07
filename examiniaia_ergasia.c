#include <stdio.h>
#include <stdlib.h>

int _int_input(){
    int x;
    scanf("%d", &x);
    return x;
}

void show_menu(){
    printf("1. Εμφάνιση λίστας αριθμών\n");
    printf("2. Υπολογισμός μέγιστου και ελάχιστου\n");
    printf("3. Υπολογισμός μέσου όρου και διαμέσου\n");
    printf("4. Δημιουργία λίστας με πολλαπλάσια ενός αριθμού (επιλέγεται από τον χρήστη)\n");
    printf("5. Έξοδος\n");

}

int users_choice(){
    int x;
    do {
        x = _int_input();
    } while (x < 1 || x > 5);
    
    return x;
}

void print_my_list(int* my_arr, int size){
    printf("[");
    for (int i = 0; i < size; i ++){
        int x = my_arr[i];
        printf("%d, ", x);
    }
    printf("]\n");
}


void print_min_max(int* my_arr, int size){
    int max = my_arr[0];
    int min = my_arr[0];
    for (int i = 1; i < size; i++){
        if (max < my_arr[i]) {
            max = my_arr[i];
        }
        if (min > my_arr[i]) {
            min = my_arr[i];
        }
    }

    printf("Max: %d\nMin: %d", max, min);
    
}

void print_median_and_average(int* my_arr, int size){

    int s = 0;
    for (int i = 0; i < size; i++){
        s += my_arr[i];
    }
    float aver = s / size;

    printf("Average: %f\n", aver);

    // Για να βρω τον διάμεσο, πρέπει πρώτα να ταξηνομίσω τον πίνακα. Επειδή ο πίνακας περνιέται τη συνάρτηση με pointer (άρα 
    // διαχειρίζομαι το original πίνακα) θα κάνω ένα αντίγραφο και θα ταξινομήσω αυτό. Δεν έχει σημασία η φορά για τον υπολογισμό 
    // του διάμεσου, εγώ εδώ θα την κάνω αύξουσα.
    int my_copy[size];
    
    for (int i = 0; i < size; i++){
        my_copy[i] = my_arr[i];
    }

    for (int i = 1; i < size; i++) {
        for (int j = size - 1; j > i-1; j--) {
            if (my_copy[j] < my_copy[j - 1]) { 
                int temp = my_copy[j];
                my_copy[j] = my_copy[j - 1];
                my_copy[j - 1] = temp;
            }
        }
    }       

    // Ο διάμεσος υπολογίζεται ως εξής:
    //   1. Αν η λίστα είναι μονή σε αριθμό στοιχείων, τότε πέρνω το μεσαίο στοιχείο (εξού και διάμεσος).
    //      Αυτό θα είναι το my_copy[size / 2].
    //   2. Αν η λίστα είναι ζυγή σε αριθμό στοιχείων, τότε παίρνω το μέσο όρο των δυο "μεσαίων" στοιχείων. Πχ αν η λίστα είναι
    //      [2, 4, 6, 8, 10, 12] τα δύο "μεσαία" στοιχεία είναι το 6 και το 8. Αυτό υπολογίζεται ως 
    //      int (size / 2) - 1 και int (size / 2) αντίστοιχα. Από αυτά τα στοιχεία βγάζω το μέσο όρο τους.
    //      Άρα θέλω τα my_copy[int (size / 2)] και my_copy[int (size/2) + 1]. Ο μέσος όρος αυτών των στοιχείων υπολογίζεται ως
    //      (my_copy[size / 2] + my_copy[size/2 - 1]) / 2 και είναι η διάμεσος.


    if (size % 2 == 1) {
        int median = my_copy[size / 2];
        printf("Διάμεσος: %d\n", median);
    } else {
        float median = (my_copy[size / 2 - 1] + my_copy[size / 2]) / 2.0;
        printf("Διάμεσος: %f\n", median);
    }

}

void print_multiples_list(int* my_arr, int size, int base){

    int counter = 0;
    for (int i = 0; i < size; i++){
        if (my_arr[i]%base == 0){
            counter++;
        }
    }

    if (counter == 0){
        printf("Δεν βρέθηκαν πολ/σια του %d στη λίστ.\n", base);
    }
    else{
        int multiples_list[counter];

        int idx = 0;
        for (int i = 0; i < size; i++){
            if (my_arr[i]%base == 0){
                multiples_list[idx] = my_arr[i];
                idx++;
            }
        }

        print_my_list(multiples_list, idx);
    }
}


int main(){

    printf("Καλως ήρθατε στην εξαμηνιαία εργασία μου.\n\n");

    int my_list[50];
    int x;
    int counter = 0;
    int stop = 0; // Το stop σταματάει την διαδικασία εισαγωγής αριθμών στη λίστα.
    
    // Γέμισμα λίστας
    printf("Παρακαλώ εισάγετε στη λίστα το πολύ 50 θετικούς αριθμούς.\n");
    printf("Για να τερματίσετε τη διαδικασία νωρίτερα πατήστε -1\n");

    do{
        printf("Παρακαλώ εισάγετε αριθμό: ");
        x = _int_input();
        if (x != -1 && x > 0){
            my_list[counter] = x;
            counter++;
            printf("Περιεχόμενο λίστας: %d/50\n\n", counter);
        }
        else if (x == -1){
            stop = !stop;
        }
        else {
            printf("ΠΡΟΣΟΧΗ: Ο αριθμός πρέπει να είναι θετικός (ή -1 αν θέλετε να τερματίσετε τη διαδικασία)\n");
        }
    }while(counter < 50 && !stop);

    int size = counter;

    // Το stop πλέον σημαίνει τέλος προγράμματος. Αν επιλεχθεί από τον χρήστη το 5 το stop γίνεται 1 και το πρόγραμμα τελειώνει
    stop = 0;

    // Το πρόγραμμα παρουσιάζει επαναληπτικά τις επιλογές στο χρήστη μέχρι αυτός να πατήσει το 5. Τότε το stop γίνεται 0 και το
    // πρόγραμμα σταματάει. Όσο τρέχει το πρόγραμμα ο χρήστης διαλέγει μια από τις επιλογές και το πρόγραμμα καλέι την αντίστοιχη
    // συνάρτηση που υλοποιεί αυτή την ενέργεια (πχ με το 1 καλεί την print_my_list η οποία εμφανίζει τη λίστα των αριθμών κλπ...)
    do
    {
        show_menu();
        printf("Επιλέξτε ενέργεια εισάγοντας τον αντίστοιχο αριθμό: \n");
        int choice = users_choice(); 
        if (choice == 1) 
            print_my_list(my_list, size);
        else if (choice == 2) 
            print_min_max(my_list, size);
        else if (choice == 3)
            print_median_and_average(my_list, size);
        else if (choice == 4){
            printf("Παρακαλώ εισάγετε αριθμό με βάση τον οποίο θα αναζητηθούν τα πολλαπλάσια: \n");
            int number = _int_input();
            print_multiples_list(my_list, size, number);
        }
        else 
            stop = 1;    
    }while (!stop);
    
        printf("\n\nΤερματισμός προγράμματος\n");    

    return 0;
}