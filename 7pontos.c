#include <stdio.h>
#include <stdlib.h>
#define eq(A, B, C) (A == B && B == C)
typedef char Item;
typedef struct stack {Item* values; int size, top;} Stack;

void initialize(Stack * s, int size){
    s->values = malloc(sizeof(Item) * size);
    s->size = size; s->top = 0;
}

void insert(Stack * s, Item v){ s->values[s->top++] = v;}
void pop(Stack * s) { if(s->top > 0 ) s->top--;}
Item last_in(Stack * s) { return s->values[s->top - 1];}
int is_empty(Stack * s) { return s->top == 0;}
void finish(Stack * s){
    free(s->values);
    s->size = 0;
    s->top = 0;
}

int main(void){
    int lines;
    char aux;
    Stack symbols;
    scanf("%d\n", &lines);
    initialize(&symbols, 101 * lines);
    while(scanf("%c", &aux) == 1){
        if(eq(aux, '*', '*') || eq(aux, '_', '_') || eq(aux, '/', '/')){
            if(eq('*', last_in(&symbols), aux)) pop(&symbols);
            else if(eq('_', last_in(&symbols), aux)) pop(&symbols);
            else if(eq('/', last_in(&symbols), aux)) pop(&symbols);
            else insert(&symbols, aux);
        }
    }
    is_empty(&symbols) ? printf("C\n") : printf("E\n");
    finish(&symbols);
}