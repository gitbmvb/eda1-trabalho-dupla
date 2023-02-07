#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define equivalents(A, B) abs(A[strlen(A) - 1] - B[0]) == 32
typedef char * Item;
typedef struct node {Item value; struct node * next;} Node;
typedef struct linked_list { Node * begin, * end; int used;} LinkedQueue;

void initialize(LinkedQueue * l){ l->begin = NULL; l->end = NULL; l->used = 0; }
Item first_in(LinkedQueue * l){ return l->begin->value; }
int is_empty(LinkedQueue * l) { return l->used == 0;}

Item dequeue(LinkedQueue * l){
    Item temp = malloc(sizeof(char) * 27);
    Node * rem = l->begin;
    strcpy(temp, l->begin->value);
    l->begin = l->begin->next;
    free(rem);
    return temp;
}

void enqueue(LinkedQueue * l, Item value){
    Node * new = malloc(sizeof(Node));
    new->value = malloc(sizeof(char) * 27);
    new->next = NULL;
    strcpy(new->value, value);
    l->used++;
    if(l->begin == NULL && l->end == NULL){
        l->begin = new; l->end = new;
        return;
    }
    l->end->next = new;
    l->end = new;
}

int main(void){
    char word[27], ref[27] = "";
    LinkedQueue standby;
    initialize(&standby);
    while(scanf("%s", word) != EOF){
        if(!equivalents(word, ref)){
            printf("%s\n", word);
            strcpy(ref, word);
        } else enqueue(&standby, word);
    }
    while(!is_empty(&standby)){
        if(!equivalents(first_in(&standby), ref)){
            printf("%s\n", first_in(&standby));
            strcpy(ref, dequeue(&standby));
        } else enqueue(&standby, dequeue(&standby));
    }
}