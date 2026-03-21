#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  struct Node * next;
  int value;
};

struct Node * push(struct Node * p1, int value)
{
  struct Node* var = malloc(sizeof(struct Node));

  var->next = p1;
  var->value = value;

  return p1 = var;
}

/*
[NULL]
push 1[
  next = HEAD;
  value = 1;
]
push 2[
  next = HEAD-1; punta a node 1
  value = 2;
]
push 3[
  next = HEAD-2; punta a node 2
  value = 3;
]

pop(*HEAD);
*HEAD = p3; --> è come HEAD-3
valore = *HEAD.valore
*HEAD = *HEAD.next --> che è come HEAD-2 che punta a node 2

free(del vecchio *HEAD prima del *HEAD = *HEAD.next, siccome era stato allocato con malloc)
return valore;


peek(HEAD = p3)


*/

int pop2(struct Node ** p1)
{
    if (*p1 == NULL) return -1; // o un codice di errore

    struct Node * aaa = *p1; // questo è HEAD
    *p1 = aaa->next;
    int valore = aaa->value; // salvi il valore
    free(aaa); 
    return valore;
}

int peek(struct Node * p1)
{
  if (p1 == NULL) return -1; // o un codice di errore
  return p1->value;
}

void free_stack(struct Node * head)
{
  while (head != NULL)
  {
    struct Node * tmp = head->next;
    free(head);
    head = tmp;
  }
}

int main(int argc, char *argv[])
{
    struct Node * lista = NULL;
    lista = push(lista, 1);
    
    lista = push(lista, 2);
    lista = push(lista, 3);
    printf("Peek value before pop: %d\n", peek(lista));
    int valore = pop2(&lista);
    printf("Last value inserted: %d\n", peek(lista));
    printf("Peek value: %d\n", peek(lista));
    valore = pop2(&lista);
    printf("Peek2 value: %d\n", peek(lista));
    valore = pop2(&lista);
    printf("Peek3 value: %d\n", peek(lista));
    valore = pop2(&lista);

    free_stack(lista);

    // printf("Last value inserted: %d\n", lista->value);
    // printf("Peek value: %d\n", peek(lista));

    // int valore = pop(lista);
    // printf("Last value, now popped: %d\n", valore);
    // printf("Peek value: %d\n", peek(lista));
    // printf("Last value inserted: %d\n", lista->value);
    // valore = pop(lista);
    // printf("Last value, now popped: %d\n", valore);
    // printf("Peek value: %d\n", peek(lista));
    // printf("Last value inserted: %d\n", lista->value);
    // lista = push(lista, 27);
    // printf("Last value inserted: %d\n", lista->value);
    // printf("Peek value: %d\n", peek(lista));
    // valore = pop(lista);
    // printf("Last value, now popped: %d\n", valore);
    // printf("Peek value: %d\n", peek(lista));
    // printf("Last value inserted: %d\n", lista->value);


    // printf("Peek value: %d\n", peek(lista));
}
// int pop(struct Node * p1)
// {
//   struct Node* tmp = malloc(sizeof(struct Node));

//   tmp->value = p1->value;
//   tmp->next = p1->next;

//   *p1 = *tmp->next;

//   int tmp_valore = tmp->value;

//   free(tmp);

//   return tmp_valore;
// }