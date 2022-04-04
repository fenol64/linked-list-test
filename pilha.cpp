#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int num;
  struct Node *prox;
};
typedef struct Node node;
struct Fila
{

  int capacidade;
  float *dados;
  int primeiro;
  int ultimo;
  int nItens;
};
int tam;

int main(void)
{
  node *array = (node *)malloc(sizeof(node));
  if (!array)
  {
    printf("memoria cheia!\n");
    exit(1);
  }
  else
  {
    start(array);
    int opt;

    do
    {
      opt = menu();
      optionHandler(array, opt);
    } while (opt);

    free(array);
    return 0;
  }
}

void start(node *array)
{
  array->prox = NULL;
  tam = 0;
}

int menu(void)
{
  int opt;

  printf("Escolha a opção\n");
  printf("0. Sair\n");
  printf("1. Zerar array\n");
  printf("2. Exibir array\n");
  printf("3. PUSH\n");
  printf("4. POP\n");
  printf("opção: ");
  scanf("%d", &opt);

  return opt;
}

void optionHandler(node *array, int op)
{
  node *tmp;
  switch (op)
  {
  case 0:
    freeMemory(array);
    break;

  case 1:
    freeMemory(array);
    start(array);
    break;

  case 2:
    show(array);
    break;

  case 3:
    push(array);
    break;

  case 4:
    tmp = pop(array);
    if (tmp != NULL)
      printf("Retirado: %3d\n\n", tmp->num);
    break;

  default:
    printf("Comando invalido\n\n");
  }
}

int vazia(node *array)
{
  if (array->prox == NULL)
    return 1;
  else
    return 0;
}

node *createElement()
{
  node *novo = (node *)malloc(sizeof(node));
  if (!novo)
  {
    printf("memoria cheia!\n");
    exit(1);
  }
  else
  {
    printf("Novo elemento: ");
    scanf("%d", &novo->num);
    return novo;
  }
}

void show(node *array)
{
  if (vazia(array))
  {
    printf("array vazia!\n\n");
    return;
  }

  node *tmp;
  tmp = array->prox;
  printf("array:");
  while (tmp != NULL)
  {
    printf("%5d", tmp->num);
    tmp = tmp->prox;
  }
  printf("\n        ");
  int count;
  for (count = 0; count < tam; count++)
    printf("  ^  ");
  printf("\nOrdem:");
  for (count = 0; count < tam; count++)
    printf("%5d", count + 1);

  printf("\n\n");
}

void freeMemory(node *array)
{
  if (!vazia(array))
  {
    node *proxNode,
        *atual;

    atual = array->prox;
    while (atual != NULL)
    {
      proxNode = atual->prox;
      free(atual);
      atual = proxNode;
    }
  }
}

void push(node *array)
{
  node *novo = createElement();
  novo->prox = NULL;

  if (vazia(array))
    array->prox = novo;
  else
  {
    node *tmp = array->prox;

    while (tmp->prox != NULL)
      tmp = tmp->prox;

    tmp->prox = novo;
  }
  tam++;
}

node *pop(node *array)
{
  if (array->prox == NULL)
  {
    printf("array ja vazia\n\n");
    return NULL;
  }
  else
  {
    node *ultimo = array->prox,
         *penultimo = array;

    while (ultimo->prox != NULL)
    {
      penultimo = ultimo;
      ultimo = ultimo->prox;
    }

    penultimo->prox = NULL;
    tam--;
    return ultimo;
  }
}