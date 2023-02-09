#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define equals(A, B) (strcmp(A, B) == 0)
typedef int Item;
typedef struct node { Item value; struct node * next, * previous;} Node;
typedef struct ada_queue { Node * begin, * end; int used;} AdaQueue;

void initialize(AdaQueue * aq){
    aq->begin = NULL;
    aq->end = NULL;
    aq->used = 0;
}

void back(AdaQueue * aq){
    if(aq->used == 0) printf("No job for Ada?\n");
    else{
        printf("%d\n", aq->end->value);
        Node * rem = aq->end;
        aq->used--;
        if(aq->used == 0) initialize(aq);
        else{
            aq->end = aq->end->previous;
            aq->end->next = NULL;
        }
        free(rem);
    } 
}

void front(AdaQueue * aq){
    if(aq->used == 0) printf("No job for Ada?\n");
    else{
        printf("%d\n", aq->begin->value);
        Node * rem = aq->begin;
        aq->used--;
        if(aq->used == 0) initialize(aq);
        else{
            aq->begin = aq->begin->next;
            aq->begin->previous = NULL;
        }
        free(rem);
    }
}

void push_back(AdaQueue * aq, Item e){
    Node * new = malloc(sizeof(Node));
    new->value = e;
    new->next = NULL;
    aq->used++;
    if(aq->begin == NULL && aq->end == NULL){
        aq->begin = new;
        aq->end = new;
        return;
    }
    new->previous = aq->end;
    aq->end->next = new;
    aq->end = new;
}

void toFront(AdaQueue * aq, Item e){
    Node * new = malloc(sizeof(Node));
    new->value = e; new->previous = NULL; new->next = NULL;
    aq->used++;
    if(aq->begin == NULL && aq->end == NULL){
        aq->begin = new;
        aq->end = new;
        return;
    }
    new->next = aq->begin;
    aq->begin->previous = new;
    aq->begin = new;
}

void reverse(AdaQueue * aq){
    Node * flag = aq->begin;
    while(flag != NULL){
        Node * aux = flag->next;
        flag->next = flag->previous;
        flag->previous = aux;
        flag = flag->previous;
    }
    Node * corner = aq->begin;
    aq->begin = aq->end;
    aq->end = corner;
}

int main(void){
    AdaQueue queue;
    initialize(&queue);
    int qtd, number;
    char command[10];
    scanf("%d", &qtd);
    for(int i = 0; i < qtd; i++){
        scanf("%s", command);
        // printf("(%d)Command = %s\n", i, command);
        if(equals(command, "back")) back(&queue);
        else if(equals(command, "front")) front(&queue);
        else if(equals(command, "reverse")) reverse(&queue);
        else if(equals(command, "push_back")){
            scanf("%d", &number);
            push_back(&queue, number);
        }
        else if(equals(command, "toFront")){
            scanf("%d", &number);
            toFront(&queue, number);
        }
        // printf("\n");
    }
}