#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int num;
    struct Node *prox;
};

typedef struct Node node;

int tam;

void start(node *ARRAY)
{
    ARRAY->prox = NULL;
    tam = 0;
}

int isEmpty(node *ARRAY)
{
    if (ARRAY->prox == NULL)
        return 1;
    else
        return 0;
}

void printList(node *ARRAY)
{
    system("clear");
    if (isEmpty(ARRAY))
    {
        printf("ARRAY vazia!\n\n");
        return;
    }

    node *tmp;
    tmp = ARRAY->prox;
    printf("Lista:");
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

node *allocate()
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

void freeMemory(node *ARRAY)
{
    if (!isEmpty(ARRAY))
    {
        node *proxNode,
            *atual;

        atual = ARRAY->prox;
        while (atual != NULL)
        {
            proxNode = atual->prox;
            free(atual);
            atual = proxNode;
        }
    }
}

void stackPush(node *array)
{
    node *novo = allocate();
    novo->prox = NULL;

    if (isEmpty(array))
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

node *stackPop(node *array)
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

void startInsert(node *ARRAY)
{
    node *novo = allocate();
    node *oldHead = ARRAY->prox;

    ARRAY->prox = novo;
    novo->prox = oldHead;

    tam++;
}

void positionInsert(node *ARRAY)
{
    int pos,
        count;
    printf("Em que posicao, [de 1 ate %d] voce deseja inserir: ", tam);
    scanf("%d", &pos);

    if (pos > 0 && pos <= tam)
    {
        if (pos == 1)
            startInsert(ARRAY);
        else
        {
            node *atual = ARRAY->prox,
                 *anterior = ARRAY;
            node *novo = allocate();

            for (count = 1; count < pos; count++)
            {
                anterior = atual;
                atual = atual->prox;
            }
            anterior->prox = novo;
            novo->prox = atual;
            tam++;
        }
    }
    else
        printf("Elemento invalido\n\n");
}

void endInsert(node *ARRAY)
{
    node *novo = allocate();
    novo->prox = NULL;

    if (isEmpty(ARRAY))
        ARRAY->prox = novo;
    else
    {
        node *tmp = ARRAY->prox;

        while (tmp->prox != NULL)
            tmp = tmp->prox;

        tmp->prox = novo;
    }
    tam++;
}

void queueInsert(node *ARRAY)
{
    node *novo = allocate();
    novo->prox = NULL;

    if (isEmpty(ARRAY))
        ARRAY->prox = novo;
    else
    {
        node *tmp = ARRAY->prox;

        while (tmp->prox != NULL)
            tmp = tmp->prox;

        tmp->prox = novo;
    }
    tam++;
}

node *startDelete(node *ARRAY)
{
    if (ARRAY->prox == NULL)
    {
        printf("lista ja esta vazia\n");
        return NULL;
    }
    else
    {
        node *tmp = ARRAY->prox;
        ARRAY->prox = tmp->prox;
        tam--;
        return tmp;
    }
}

node *endDelete(node *ARRAY)
{
    if (ARRAY->prox == NULL)
    {
        printf("ja esta vazia\n");
        return NULL;
    }
    else
    {
        node *tmp = ARRAY->prox;
        ARRAY->prox = tmp->prox;
        tam--;
        return tmp;
    }
}

node *deletePosition(node *ARRAY)
{
    int opt,
        count;
    printf("Que posicao, [de 1 ate %d] voce deseja retirar: ", tam);
    scanf("%d", &opt);

    if (opt > 0 && opt <= tam)
    {
        if (opt == 1)
            return startDelete(ARRAY);
        else
        {
            node *atual = ARRAY->prox,
                 *anterior = ARRAY;

            for (count = 1; count < opt; count++)
            {
                anterior = atual;
                atual = atual->prox;
            }

            anterior->prox = atual->prox;
            tam--;
            return atual;
        }
    }
    else
    {
        printf("Elemento invalido\n\n");
        return NULL;
    }
}

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

int handlerListOptions(int type, int list_opt, node list)
{
    node *tmp;

    if (type == 1) // fila
    {
        switch (list_opt)
        {
        case 0:
            freeMemory(list);
            break;
        case 1:
            freeMemory(list);
            start(list);
            break;
        case 2:
            printList(list);
            break;
        case 3:
            queueInsert(list);
            break;
        case 4:
            endInsert(list);
            if (tmp != NULL)
            {
                printf("Retirado: %3d\n\n", tmp->num);
                libera(tmp);
            }
            break;
        default:
            printf("Comando invalido\n\n");
            break;
        }
    }
    else if (type == 2) // pilha
    {
        switch (list_opt)
        {
        case 0:
            freeMemory(array);
            break;

        case 1:
            freeMemory(array);
            start(array);
            break;

        case 2:
            printList(array);
            break;

        case 3:
            stackPush(array);
            break;

        case 4:
            tmp = stackPop(array);
            if (tmp != NULL)
                printf("Retirado: %3d\n\n", tmp->num);
            break;

        default:
            printf("Comando invalido\n\n");
        }
    }
    else if (type == 3) // lista
    {
        switch (list_opt)
        {
        case 0:
            freeMemory(list);
            break;

        case 1:
            freeMemory(list);
            start(list);
            break;

        case 2:
            printList(list);
            break;

        case 3:
            startInsert(list);
            break;

        case 4:
            endInsert(list);
            break;

        case 5:
            positionInsert(list);
            break;

        case 6:
            tmp = startDelete(list);
            printf("Retirado: %3d\n\n", tmp->num);

        case 7:
            tmp = endDelete(list);
            printf("Retirado: %3d\n\n", tmp->num);

        case 8:
            tmp = deletePosition(list);
            printf("Retirado: %3d\n\n", tmp->num);

        default:
            printf("Comando invalido\n\n");
            break;
        }
    }
}

int handlerOptions(int opt)
{
    int listopt = 1;
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
            handlerListOptions(opt, listopt, *ARRAY);

        } while (listopt);
    }
}

int main()
{
    int opt;
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