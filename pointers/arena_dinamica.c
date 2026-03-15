#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int intero = atoi(argv[1]);
    printf("intero = %d\n", intero);

    int * array = malloc(intero * 4);

    for (size_t i = 0; i < intero; i++)
    {
        *(array + i) = i;
    }
    for (size_t i = 0; i < intero; i++)
    {
        printf("aaa = %d\n", *(array + i));
    }

    

    free(array);

    int *newarray = realloc(array, intero*4*2);

    for (size_t i = 0; i < intero*2; i++)
    {
        *(newarray + i) = i;
    }
    for (size_t i = 0; i < intero*2; i++)
    {
        printf("aaa = %d\n", *(newarray + i));
    }

    free(newarray);
}