#include <stdio.h>

int main() {

    int intero = 12;
    char *carattere = "a";
    double dd = 12345678.12345678;

    printf("Intero: %d\n", intero);
    printf("carattere: %s\n", carattere);
    printf("dd: %f\n", dd);



    printf("Address Intero: %p\n", &intero);
    printf("Address carattere: %p\n", &carattere);
    printf("Address dd: %p\n", &dd);


    printf("Size Intero: %ld\n", sizeof(intero));
    printf("Size carattere: %ld\n", sizeof(carattere));
    printf("Size dd: %ld\n", sizeof(dd));

}