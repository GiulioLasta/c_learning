#include <stdio.h>
#include <stdlib.h>

int main()
{
    int intero1[12];

    intero1[0] = 12;
    intero1[1] = 23;
    intero1[2] = 34;

    printf("Intero1: %d\n", intero1[0]);
    printf("Intero2: %d\n", intero1[1]);
    printf("Intero3: %d\n", intero1[2]);
    size_t length = sizeof(intero1) / sizeof(intero1[0]);


    for (size_t i = 0; i < length; i++)
    {
        intero1[i] = 0;
    }
    
    *(intero1) = 45;
    *(intero1+1) = 56;
    *(intero1+2) = 65;
    *(intero1+22) = 99;


    printf("Intero1: %d\n", intero1[0]);
    printf("Intero2: %d\n", intero1[1]);
    printf("Intero3: %d\n", intero1[2]);
    printf("Intero3: %d\n", intero1[22]);

    printf("size of type array: %ld\n", sizeof(intero1));
    printf("size of array: %ld\n", length);
    printf("size of int: %ld\n", sizeof(length));

    int * pointer = malloc(sizeof *pointer);

    printf("pointer: %ls\n", pointer);
    printf("pointer address: %p\n", &pointer);

    *pointer = 1;
    printf("pointer: %ls\n", pointer);
    printf("pointer before cycle: %d\n", *pointer);
    for (size_t i = 0; i < length; i++)
    {
        if(*(intero1+i) > 0) {
            printf("intero1: %d\n", *(intero1+i));
            printf("pointer: %d\n", *pointer);
            *pointer = *pointer + *(intero1+i);
        }
    }


    printf("pointer: %d\n", *pointer);
    printf("pointer address: %p\n", &pointer);
    printf("pointer: %ls\n", pointer);
    
}