#include <stdio.h>
#include "Fonctions.h"
//#include "Fonctions.c"

int main(){
    printf("hello world\n");
    COLUMN * mycol ;
    mycol = create_column("My column");
    printf("%s %d",mycol ->titre,mycol->taille_ph);
    int val = 5;

    if (insert_value(mycol, val)) {
        printf("Value added successfully to my column\n");
    }
    else
    {
        printf("Error adding value to my column\n");

    }




    return 0;
}

