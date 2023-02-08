#include <stdio.h>
#include <stdlib.h>

typedef struct placa{
    int ope;
    long int valor;
} Item;

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
    novo->e = e;
    novo->prox = h->inicio;
    novo->ant = NULL;
    h->inicio = novo;
    h->no_count++;
    h->ultimo = novo;
}

void insereinicioL2(cabeca_st *h, Item e){
	no_st *novo = malloc(sizeof(no_st));
	if(novo == NULL) return;
	novo->e = e;
	novo->prox = h->inicio;
	h->inicio->ant = novo;
	novo->ant = NULL;
	h->inicio = novo;
    h->no_count++;
}

void insertionsort(cabeca_st *h, int l, int r){
    no_st *v = h->ultimo;
    for (int i = r; i > l; i--)
    {
        if (v->ant->e.ope < v->e.valor)
        {
            no_st *aux = v->ant;
            v->ant->ant->prox = v;
            v->ant = v->ant->ant;
            aux->prox = v->prox;
            v->prox->ant = aux;
            aux->ant = v;
            v->prox = aux;
        }
    }

    v = h->inicio;
    for (int i = l+2; i <= r; i++)
    {
        no_st *ajuda = v->prox->prox;
        int j = i;
        while (ajuda->e.valor < )
        {
            /* code */
        }
        
    }
    
    
}


int main(){
    cabeca_st h;
    inicializalista(&h);
    Item aux;
    while (scanf("%d %ld", &aux.ope, &aux.valor) != EOF)
    {
        if (aux.ope == 1)
        {
            insereinicioL2(&h, aux);
        }else{
            selectionSort(&h, 0, h.no_count);
            no_st *novo = h.inicio;
            printf("%ld", novo->e.valor);
            novo = novo->prox;
            for (int i = 1; i < aux.valor; i++)
            {
                printf(" %ld", novo->e.valor);
                novo = novo->prox;
            }
            printf("\n");
        }
    }
    


    return 0;
}