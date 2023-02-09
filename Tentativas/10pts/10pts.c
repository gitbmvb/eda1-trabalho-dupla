#include <stdio.h>
#include <stdlib.h>

typedef struct placa{
    int ope;
    long int valor;
} Item;

typedef struct no_st no_st;

struct no_st{
	Item e;
	no_st *prox;
};

typedef struct{
	no_st *inicio;
	int no_count;
    no_st *checkpoint;
} cabeca_st;

int inicializalista(cabeca_st *h){
	h->inicio = NULL;
	h->no_count = 0;
    h->ultimo = NULL;
	return 1;
}

int insereinicio(cabeca_st *h, Item e){
	no_st *novo_no = malloc(sizeof(no_st));
	if(novo_no == NULL) return 0;
	novo_no->e = e;
	novo_no->prox = h->inicio;
    h->inicio = novo_no;
	h->no_count++;
	return 1;
}

int inseredepois(cabeca_st *h, Item e, int p){
	int i = 0;
	no_st *aux = h->inicio;
    while(i < p && aux->prox != NULL){
        aux = aux->prox;
        i++;
    }
    no_st *novono = malloc(sizeof(no_st));
    if(novono == NULL) return 0;
    novono-> e = e;
    novono->prox = aux->prox;
    aux->prox = novono;
    h->no_count++;
return 1;
}

int main(){
    cabeca_st h;
    inicializalista(&h);
    Item aux;
    while (scanf("%d %ld", &aux.ope, &aux.valor) != EOF)
    {
        no_st *novo = h.inicio;
        no_st *antes;
        if (aux.ope == 1)
        {
            if (novo == NULL || aux.valor < novo->e.valor)
            {
                insereinicio(&h, aux);
                continue;
            }
            while (novo != NULL && aux.valor > novo->e.valor)
            {
                antes = novo;
                novo = novo->prox;
            }
            no_st *auxiliar = malloc(sizeof(no_st));
            auxiliar->e = aux;
            auxiliar->prox = novo;
            antes->prox = auxiliar;

            
        }else{
            printf("%ld", novo->e.valor);
            novo = novo->prox;
            for (int i = 1; i < aux.valor; i++)
            {
                if(novo == NULL) break;
                printf(" %ld", novo->e.valor);
                novo = novo->prox;
            }
            printf("\n");
        }
        
    }
    

    return 0;
}