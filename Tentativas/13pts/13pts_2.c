#include <stdio.h>
#include <stdlib.h>
typedef char Item;
typedef struct node { Item v; struct node * next; } Node;
typedef struct linked_list { Node * begin, * end; } LinkedList;

void initialize(LinkedList * l){ l->begin = NULL; l->end = NULL;}

void append(LinkedList * l, Item e){
    Node * new = malloc(sizeof(Node));
    new->next = NULL; new->v = e;
    if(l->begin == NULL && l->end == NULL){ l->begin = new; l->end = new; return;}
    l->end->next = new; l->end = new;
}

int main(void){
    char aux; int amount = 0, words_index = 0;
    LinkedList words[100000];
    initialize(&words[words_index]);
    while(scanf("%c", &aux) == 1) aux == '\n' ? initialize(&words[++words_index]) : append(&words[words_index], aux);
    Node * ref = words[words_index].begin;
    for(int i = 0; i < words_index; i++){
        for(Node * j = words[i].begin; j != NULL; j = j->next){
            if(ref->v == j->v) ref = ref->next;
            if(ref == NULL) {amount++; ref = words[words_index].begin; }
        }
        printf("%d\n", amount);
        amount = 0;
    }
}