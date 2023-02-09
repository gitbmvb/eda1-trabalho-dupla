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

int create_stack(Stack *p, int s) {
	p->size = s;
	//p->v = malloc(s * sizeof(Item));
	p->top = 0;
	return 1;
}

int push(Stack *p, int e) {
	if (p->top == p->size) return 0;
    p->v[p->top++] = e;
	return 1;
}

void pull(Stack *p) {
	p->top--;
}

int top(Stack *p) {
	return p->v[p->top-1];
}

int is_empty(Stack *p) {
	return p->top == 0;
}


int main(){
    int n, entrada;
    scanf("%d", &n);
    struct fila_st f;
    
    Stack sideStreet;
    create_stack(&sideStreet, n);
    inicializafila(&f, n+1);

    struct fila_st saida;
    inicializafila(&saida, n+1);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &entrada);
        enfila(&f, entrada);
    }
    enfila(&f, 1001);

    for (int i = 0; i <= n; i++)
    {
        int j = espia(&f);
        if (!is_empty(&sideStreet) && top(&sideStreet) < j)
        {
            enfila(&saida, top(&sideStreet));
            pull(&sideStreet);
            i--;
            continue;
        } else if(j > espiaprox(&f)){
            push(&sideStreet, j);
        } else {
            enfila(&saida, j);
        }
        desenfila(&f);
    }
    
    while (!is_empty(&sideStreet) && saida.ocupados != 5)
    {
        enfila(&saida, top(&sideStreet));
        pull(&sideStreet);
    }


    for (int i = 0; i < n; i++)
    {
        printf("%d ", espia(&saida));
        desenfila(&saida);
    }
    
    
    
    return 0;
}