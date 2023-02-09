#include <stdio.h>
#include <stdlib.h>

struct fila_st
{
    int *v;
    int size;
    int ocupados;
    int inicio, fim;
    
};

void inicializafila(struct fila_st *fila, int size){
    fila->size = size;
    fila->v = malloc(size*sizeof(int));
    if(fila->v == NULL) {return;}
    fila->ocupados = 0;
    fila->inicio = -1;
    fila->fim = 0;
};

int enfila(struct fila_st *f, int e ){
    if(f->fim == f->inicio) return 0;
    f->v[f->fim++] =e;
    f->fim = f->fim % f->size;
    f->ocupados++;
    return 1;
}

int espia(struct fila_st *f){
    return f->v[(f->inicio + 1) % f->size];
}

int espiaprox(struct fila_st *f){
    return f->v[((f->inicio + 1) % f->size)+1];
}

int estaVazia(struct fila_st *f){
    return f->ocupados == 0? 0 : 1;
}

void desenfila(struct fila_st *f){
    f->ocupados--;
    f->inicio = (f->inicio +1) % f->size;
}

typedef struct Stack {
	int *v;
	int size, top;
}Stack;

int inicializapilha(Stack *p, int s) {
	p->size = s;
	p->top = 0;
	return 1;
}

int empilha(Stack *p, int e) {
	if (p->top == p->size) return 0;
    p->v[p->top++] = e;
	return 1;
}

void desempilha(Stack *p) {
	p->top--;
}

int topo(Stack *p) {
	return p->v[p->top-1];
}

int pilhavazia(Stack *p) {
	return p->top == 0;
}

int final[1001];

int main(){
    int n;
    scanf("%d", &n);
    int index = 0; //Vetor com a ordem final

    //Fila com os carrinhos
    struct fila_st f;
    inicializafila(&f, n+1);
    int j;
    while(scanf("%d", &j))
    {
        if(j == 0){break;}
        enfila(&f, j);
    }
    enfila(&f, 1001);

    //Pilha de sideStreet
    Stack sideStreet;
    inicializapilha(&sideStreet, n);

    while (espia(&f) != 1001)
    {
        int primeiro = espia(&f); //Primeiro carro
        if(!pilhavazia(&sideStreet) && topo(&sideStreet) < primeiro){
            printf("errou ein ");
            final[index++] = topo(&sideStreet);
            desempilha(&sideStreet);
        } else if(primeiro > espiaprox(&f)){
            empilha(&sideStreet, primeiro);
            desenfila(&f);
        } else {
            final[index++] = primeiro;
            desenfila(&f);
        }
    }
    free(&f);
    
    while (!pilhavazia(&sideStreet))
    {
        final[index++] = topo(&sideStreet);
        desempilha(&sideStreet);
    }
    free(&sideStreet);
    int check = 0;
    for (int i = 0; i < n-1; i++)
    {
        printf("%d ", final[i]);
        if (final[i] > final[i+1])
        {
            check = 1;
        }
        
    }
    if(check == 1){printf("no\n");}
    else{printf("yes\n");}
    
    return 0;
}