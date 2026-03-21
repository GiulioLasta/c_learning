#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contatto {
  int numero;
  char cognome[25];
  char nome[25];
};

void printRubrica(struct Contatto *rubrica, int size_rubrica)
{
    for (size_t i = 0; i < size_rubrica; i++)
    {
        printf("Contatto %ld:\n", i);
        printf("Numero %d:\n", rubrica[i].numero);
        printf("Nome %s:\n", rubrica[i].nome);
        printf("Cognome %s:\n", rubrica[i].cognome);
    }
}

char* searchRubricaNome(struct Contatto *rubrica, int size_rubrica, char search[])
{
    for (size_t i = 0; i < size_rubrica; i++)
    {
        if(strstr(rubrica[i].nome, search))
        {
            return strstr(rubrica[i].nome, search);
        }
    }
}

char* searchRubricaCognome(struct Contatto *rubrica, int size_rubrica, char search[])
{
    for (size_t i = 0; i < size_rubrica; i++)
    {
        if(strstr(rubrica[i].cognome, search))
        {
            return strstr(rubrica[i].cognome, search);
        }
    }
}

struct Contatto* searchContattoNome(struct Contatto *rubrica, int size_rubrica, char search[])
{
    for (size_t i = 0; i < size_rubrica; i++)
    {
        if(strstr(rubrica[i].nome, search))
        {
            return &rubrica[i];
        }
    }
}

int main(int argc, char *argv[])
{
    struct Contatto rubrica[3] = {
        { 123, "Lasta", "Giulio" },
        { 1233, "Lasta1", "Francesco" },
        { 1234, "Lasta2", "Luigi" }
    };

    printRubrica(rubrica, 3);
    char * pointer_to_result = searchRubricaNome(rubrica, 3, "Giulio");
    
    printf("Pointer to result1: %s\n", pointer_to_result);
    printf("Pointer to result1: %s\n", pointer_to_result-25);
    printf("Pointer to result1: %d\n", *(int*)(pointer_to_result-29));


    char * pointer_to_result_cognome = searchRubricaCognome(rubrica, 3, "Lasta");
    
    printf("Pointer to result2: %s\n", pointer_to_result_cognome);
    printf("Pointer to result2: %d\n", *(pointer_to_result_cognome-6));

    struct Contatto * pointer_to_result_contatto = searchContattoNome(rubrica, 3, "Giulio");
    
    printf("Pointer to result3: %s\n", pointer_to_result_contatto->cognome);
    printf("Pointer to result3: %s\n", pointer_to_result_contatto->nome);
    printf("Pointer to result3: %d\n", pointer_to_result_contatto->numero);
}


// [ 100101010100 LASTA 01010010 GIULIO  ]