#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no_st no_st;

typedef char Item[27];

struct no_st
{
    Item e;
    no_st *ant, *prox;
};

typedef struct
{
    no_st *inicio;
    int no_count;
    no_st *ultimo;
} cabeca_st;

int inicializalista(cabeca_st *h)
{
    h->inicio = NULL;
    h->no_count = 0;
    h->ultimo = NULL;
    return 1;
}

void inserePrimeiro(cabeca_st *h, Item e)
{
    no_st *novo = malloc(sizeof(no_st));
    strcpy(novo->e, e);
    novo->prox = h->inicio;
    novo->ant = NULL;
    h->inicio = novo;
    h->no_count++;
    h->ultimo = novo;
}

void insereinicioL2(cabeca_st *h, Item e)
{
    if (h->inicio == NULL)
    {
        inserePrimeiro(h, e);
        return;
    }
    no_st *novo = malloc(sizeof(no_st));
    if (novo == NULL)
        return;
    strcpy(novo->e, e);
    novo->prox = h->inicio;
    h->inicio->ant = novo;
    novo->ant = NULL;
    h->inicio = novo;
    h->no_count++;
}

void insereFinal(cabeca_st *h, Item e)
{
    if (h->inicio == NULL)
    {
        inserePrimeiro(h, e);
        return;
    }
    no_st *novo = malloc(sizeof(no_st));
    strcpy(novo->e, e);
    novo->prox = NULL;
    h->ultimo->prox = novo;
    novo->ant = h->ultimo;
    h->ultimo = novo;
    h->no_count++;
}

void removeInicio(cabeca_st *h)
{
    if (h->inicio == NULL)
    {
        return;
    }
    h->no_count--;
    no_st *aux = h->inicio;
    if (h->ultimo == h->inicio)
    {
        h->inicio = NULL;
        h->ultimo = NULL;
        free(aux);
        return;
    }
    h->inicio = h->inicio->prox;
    h->inicio->ant = NULL;
    free(aux);
}

int main()
{
    cabeca_st h;
    inicializalista(&h);

    char cidade[27];

    while (scanf("%s", &cidade) != EOF)
    {
        insereFinal(&h, cidade);
    }

    if(h.no_count == 0) return 0;
    printf("%s\n", h.inicio->e);
    while (h.no_count > 1)
    {
        no_st *aux = h.inicio;
        if (h.inicio->prox->e[0] == (h.inicio->e[strlen(h.inicio->e) - 1] - 32))
        {
            insereFinal(&h, h.inicio->prox);
            removeInicio(&h);
            removeInicio(&h);
            insereinicioL2(&h, aux->e);
        }
        else
        {
            printf("%s\n", h.inicio->prox->e);
            removeInicio(&h);
        }
    }

    return 0;
}