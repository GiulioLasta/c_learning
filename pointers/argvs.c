#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("Using number-of-rings = %s\n", argv[0]);
    printf("Using number-of-rings = %s\n", argv[1]);
    printf("Using number-of-rings = %s\n", argv[2]);



    printf("Using number-of-rings = %s\n", *argv);
    printf("Using number-of-rings = %c\n", **(argv+1));

    printf("array size = %d\n", argc - 1);
    
}