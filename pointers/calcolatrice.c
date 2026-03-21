#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Operation {
  int (*fpop)(int, int);
  char operator;
};

int sum(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int main(int argc, char *argv[])
{
    int (*fpsum)(int, int) = sum;
    int (*fpsub)(int, int) = sub;

    struct Operation array[2] = {
        {sum, '+'},
        {sub, '-'}
    };

    char operator = '-';

    for (size_t i = 0; i < 2; i++)
    {
        if(array[i].operator == operator) {
            printf("%d\n", array[i].fpop(1,2)); 
        }
    }
    return 1;
}