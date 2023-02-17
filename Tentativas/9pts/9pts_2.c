#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define equivalents(A, B) (abs(A[strlen(A) - 1] - B[0]) == 32)
typedef char * Item;
typedef struct node {Item value; struct node * next;} Item;
typedef struct linked_list { Item * begin, * end; int used;} LinkedQueue;

void initialize(LinkedQueue * l){ l->begin = NULL; l->end = NULL; l->used = 0; }
Item first_in(LinkedQueue * l){ return l->begin->value; }
int is_empty(LinkedQueue * l) { return l->used == 0;}

Item dequeue(LinkedQueue * l){
    Item temp = malloc(sizeof(char) * 27);
    Item * rem = l->begin;
    strcpy(temp, l->begin->value);
    l->used--;
    l->begin = l->begin->next;
    free(rem);
    return temp;
}

void enqueue(LinkedQueue * l, Item value){
    Item * new = malloc(sizeof(Item));
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
    int flag = 0;
    LinkedQueue standby;
    initialize(&standby);
    while(scanf("%s", word) == 1){
        if(!equivalents(ref, word) || (equivalents(ref, word) && flag == 1)){
            printf("%s\n", word);
            strcpy(ref, word);
            flag = 0;
        } else{
            enqueue(&standby, word);
            flag = 1;
        }
    }
    while(!is_empty(&standby)){
        if(!equivalents(ref, first_in(&standby)) || (equivalents(ref, word) && flag == 1)){
            printf("%s\n", first_in(&standby));
            strcpy(ref, dequeue(&standby));
            flag = 0;
        } else {
            enqueue(&standby, dequeue(&standby));
            flag = 1;
        }
    }
}