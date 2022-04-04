#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int num;
    struct Node *prox;
};

typedef struct Node node;

int tam;

void queueMenu()
{
    int opt;
    printf("Escolha a opcao\n");
    printf("0. Menu principal\n");
    printf("1. Zerar fila\n");
    printf("2. Exibir fila\n");
    printf("3. Adicionar Elemento na Fila\n");
    printf("4. Retirar Elemento da Fila\n");
}

void stackMenu()
{
    int opt;
    printf("Escolha a opcao\n");
    printf("0. Menu principal\n");
    printf("1. Zerar pilha\n");
    printf("2. Exibir pilha\n");
    printf("6. Inserir no inicio\n");
    printf("7. Retirar do fim\n");
}

void listMenu()
{
    printf("Escolha a opcao\n");
    printf("0. Menu principal\n");
    printf("1. Zerar lista\n");
    printf("2. Exibir lista\n");
    printf("3. Adicionar node no inicio\n");
    printf("4. Adicionar node no final\n");
    printf("5. Escolher onde inserir\n");
    printf("6. Retirar do inicio\n");
    printf("7. Retirar do fim\n");
    printf("8. Escolher de onde tirar\n");
}

int handlerListOptions(int list_opt)
{
}

int handlerOptions(int opt)
{
    int listopt = 1;

    do
    {
        switch (opt)
        {
        case 0:
            return 0;
        case 1:
            queueMenu();
            break;
        case 2:
            stackMenu();
            break;
        case 3:
            listMenu();
            break;
        default:
            printf("Opcao invalida\n");
            exit(1);
            break;
        }

        scanf("%d", &listopt);
        handlerListOptions(listopt);

    } while (listopt);
}

int main()
{
    int opt;
    node *ARRAY = (node *)malloc(sizeof(node));

    if (!ARRAY)
    {
        printf("memoria cheia!\n");
        exit(1);
    }
    else
    {
        do
        {
            printf("Menu principal\n");
            printf("Selecione uma das opcoes\n");
            printf("0. Sair\n");
            printf("1. Fila\n");
            printf("2. Pilha\n");
            printf("3. Lista\n");

            printf("Digite a opcao: ");
            scanf("%i", &opt);
            printf("Opcao escolhida: %i\n", opt);
            handlerOptions(opt);
        } while (opt);
    }
}