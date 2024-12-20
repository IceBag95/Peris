#include <stdio.h>
#include <string.h>


int main(){

    char myStr[50];
    printf("Please Insert a message: \n");
    int i = 0;
    char x = getchar();
    while(i < 50 && x != '\n'){
        myStr[i] = x;
        i++;
        x = getchar();
    }

    printf("%s \n",myStr);

    int length = strlen(myStr);
    int counter = 0;
    for (int i = 0; i < length; i++){
        if (    (myStr[i]   == 'H' || myStr[i]   == 'h') 
            &&  (myStr[i+1] == 'E' || myStr[i+1] == 'e')
            &&  (myStr[i+2] == 'L' || myStr[i+2] == 'l')
            &&  (myStr[i+3] == 'L' || myStr[i+3] == 'l')
            &&  (myStr[i+4] == 'O' || myStr[i+4] == 'o')) 
            {
                counter++;
            }
    }

    printf("Στο string: %s\n", myStr);
    printf("Βρήκαμε τη λέξη 'hello' %d φορές\n", counter);
    printf("Ανεξαρτήτως γραμματοσειράς (κεφαλαία ή μικρά)\n");



    return 0;
}