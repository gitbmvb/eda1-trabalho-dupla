#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no_st no_st;

typedef int Item;

struct no_st{
	Item e;
	no_st *ant, *prox;
};

typedef struct{
	no_st *inicio;
	int no_count;
    no_st *ultimo;
} cabeca_st;

int inicializalista(cabeca_st *h){
	h->inicio = NULL;
	h->no_count = 0;
    h->ultimo = NULL;
	return 1;
}

void inserePrimeiro(cabeca_st *h, Item e){
    no_st *novo = malloc(sizeof(no_st));
    novo->e = e;
    novo->prox = h->inicio;
    novo->ant = NULL;
    h->inicio = novo;
    h->no_count++;
    h->ultimo = novo;
}

void insereinicioL2(cabeca_st *h, Item e){
    if(h->inicio == NULL){
        inserePrimeiro(h, e);
        return;
    }
	no_st *novo = malloc(sizeof(no_st));
	if(novo == NULL) return;
    novo->e = e;
	novo->prox = h->inicio;
	h->inicio->ant = novo;
	novo->ant = NULL;
	h->inicio = novo;
    h->no_count++;
}

void insereFinal(cabeca_st *h, Item e){
    if(h->inicio == NULL){
        inserePrimeiro(h, e);
        return;
    }
    no_st *novo = malloc(sizeof(no_st));
    novo->e = e;
    novo->prox = NULL;
    h->ultimo->prox = novo;
    novo->ant = h->ultimo;
    h->ultimo = novo;
    h->no_count++;
}

void printInicio(cabeca_st *h){
    if (h->inicio == NULL)
    {
        printf("No job for Ada?\n");
        return;
    }
    printf("%d\n", h->inicio->e);
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

void printFinal(cabeca_st *h){
    if (h->ultimo == NULL)
    {
        printf("No job for Ada?\n");
        return;
    }

    printf("%d\n", h->ultimo->e);
    h->no_count--;
    no_st *aux = h->ultimo;

    if (h->ultimo == h->inicio)
    {
        h->inicio = NULL;
        h->ultimo = NULL;
        free(aux);
        return;
    }

    h->ultimo->ant->prox = NULL;
    h->ultimo = h->ultimo->ant;
    free(aux);
}

void reverse(cabeca_st *h){
    if(h->inicio == NULL || h->no_count == 1) return;
    no_st *aux = h->inicio;
    no_st *aux2 = h->ultimo;
    h->ultimo = h->inicio;
    while (aux != NULL)
    {
        no_st *temp = aux->ant;
        aux->ant = aux->prox;
        aux->prox = temp;
        aux = aux->ant;
    }
    h->inicio = aux2;
}

int main(){
    //Inicializa lista
    cabeca_st h;
    inicializalista(&h);

    //Qtdade de entradas
    long int Q;
    scanf("%ld", &Q);

    //Variaveis das entradas
    char entrada[10];
    int valor;

    int reverso = 1;

    for (long int i = 0; i < Q; i++)
    {
        scanf("%s", entrada);
        if(reverso){
            if(strcmp(entrada, "toFront") == 0) {
                scanf("%d", &valor);
                insereinicioL2(&h, valor);
            }
            else if(strcmp(entrada, "push_back") == 0) {
                scanf("%d", &valor);
                insereFinal(&h, valor);
            }
            else if(strcmp(entrada, "front") == 0) printInicio(&h);
            else if(strcmp(entrada, "back") == 0) printFinal(&h);
            else reverso = 0;
        } else {
            if(strcmp(entrada, "toFront") == 0) {
                scanf("%d", &valor);
                insereFinal(&h, valor);
            }
            else if(strcmp(entrada, "push_back") == 0) {
                scanf("%d", &valor);
                insereinicioL2(&h, valor);
            }
            else if(strcmp(entrada, "front") == 0) printFinal(&h);
            else if(strcmp(entrada, "back") == 0) printInicio(&h);
            else reverso = 1;
        }
    }
    

    return 0;
}