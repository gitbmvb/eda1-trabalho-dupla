#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Item[4000000];

typedef struct no_st no_st;

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
    strcpy(novo->e, e);
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
    strcpy(novo->e, e);
	novo->prox = h->inicio;
	h->inicio->ant = novo;
	novo->ant = NULL;
	h->inicio = novo;
    h->no_count++;
}

void checkString(Item checando, Item nome, int total){
    printf("%s %s", checando, nome);
    int j = strlen(nome);
    printf("2\n");
    /* for (int i = 0; i < strlen(checando) - j; i++)
    {
        printf("3\n");
        if (strncmp(&checando[i], nome, j) == 0)
        {
            printf("4\n");
            total++;
        }  
    } */

    printf("%d\n", total);
    
}

void contador(Item str, Item sub){
    int i, j, l, l1, l2;
    int count = 0, count1 = 0;
 
    l1 = strlen(str);
 
    l2 = strlen(sub);
    for (i = 0; i < l1;)
    {
        j = 0;
        count = 0;
        while ((str[i] == sub[j]))
        {
            count++;
            i++;
            j++;
        }
        if (count == l2)
        {
            count1++;                                   
            count = 0;
        }
        else
            i++;
    }    
    printf("%d\n", count1);
}

int main(){
    cabeca_st h;
    Item entrada;
    inicializalista(&h);
    while (scanf("%s", entrada) != EOF)
    {
        insereinicioL2(&h, entrada);
    }

    no_st *aux = h.ultimo;
    while(aux != h.inicio)
    {
        contador(aux->e, h.inicio->e);
        aux = aux->ant;
    }
    
    

    return 0;
}