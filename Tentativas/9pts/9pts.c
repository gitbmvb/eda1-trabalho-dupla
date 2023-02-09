#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fila_st
{
    char v[1000][28];
    int size;
    int ocupados;
    int inicio, fim;
    
};

void inicializafila(struct fila_st *fila, int size){
    fila->size = size;
    if(fila->v == NULL) {return;}
    fila->ocupados = 0;
    fila->inicio = -1;
    fila->fim = 0;
};

int enfila(struct fila_st *f, char *e ){
    if(f->fim == f->inicio) return 0;
    strcpy(f->v[f->fim++], e);
    f->fim = f->fim % f->size;
    f->ocupados++;
    return 1;
}

char *espia(struct fila_st *f){
    return f->v[(f->inicio + 1) % f->size];
}

int espiaprox(struct fila_st *f){
    return f->v[((f->inicio + 1) % f->size)+1];
}

int estaVazia(struct fila_st *f){
    return f->ocupados == 0;
}

void desenfila(struct fila_st *f){
    f->ocupados--;
    f->inicio = (f->inicio +1) % f->size;
}

int main(){
    struct fila_st f;
    inicializafila(&f, 1000);
    char cidade[28], aux[28];

    while(scanf("%s", cidade) != EOF){
        enfila(&f, cidade);
    }
    
    while (!estaVazia(&f))
    {
        strcpy(aux, espia(&f));
        printf("%s\n", aux);
        desenfila(&f);
        if(estaVazia(&f)) break;

        char inicio = espia(&f)[0];

        if((inicio + 32) == aux[strlen(aux)-1]){
            enfila(&f, espia(&f));
            desenfila(&f);    
        }
    }

    return 0;
}