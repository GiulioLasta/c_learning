#include <stdio.h>

int swap(int *a, int *b)
{
    int tmp = *a;

    *a = *b;

    *b = tmp;

    return 0;
}

int main() {

    int intero1 = 12;
    int intero2 = 23;

    printf("Intero1: %d\n", intero1);
    printf("Intero2: %d\n", intero2);

    swap(&intero1, &intero2);

    printf("Intero1: %d\n", intero1);
    printf("Intero2: %d\n", intero2);

}