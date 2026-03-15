#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char stringa1[] = "aaaaaa";
    char stringa2[] = "bbbbbb";

    // size_t length1 = sizeof(stringa1) / sizeof(stringa1[0]); // 6 + 1 /0
    // size_t length2 = sizeof(stringa2) / sizeof(stringa2[0]);// 6 + 1 /0
    size_t length1 = sizeof(stringa1) / sizeof(stringa1[0]) - 1; // 6 + 1 /0
    size_t length2 = sizeof(stringa2) / sizeof(stringa2[0]) -1;// 6 + 1 /0
    printf("%ld\n", sizeof(stringa1[0]));

    // char *stringa3 = malloc((length1+length2)*sizeof(stringa1[0]));
    char *stringa3 = malloc((length1+length2+1));

    printf("%ld\n", length1);
    printf("%ld\n", length2);
    printf("%ld\n", length1+length2);
    printf("%ld\n", (length1+length2)*sizeof(stringa1[0]));


    printf("%ld\n", sizeof(stringa3));
    printf("%ld\n", sizeof(*stringa3));

    for (size_t i = 0; i < length1; i++)
    {
        stringa3[i] = stringa1[i];
    }
    // printf("%s\n", stringa3);
    for (size_t i = 0; i < length2; i++)
    {
    printf("%ld\n", i+length1);
        stringa3[i+length1] = stringa2[i];
    }

    
    
    printf("%s\n", stringa3);

    free(stringa3);
}