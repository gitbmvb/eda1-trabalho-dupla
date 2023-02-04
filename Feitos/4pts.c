#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define equals(A, B) strcmp(A, B) == 0
typedef struct node { char * phrase; struct node * next;} Node;
typedef struct linked_stack { Node * head;} LinkedStack;

void initialize(LinkedStack * l){ l->head = NULL;}

void put_it_on(LinkedStack * l, char * phrase){
    Node * new = malloc(sizeof(Node));
    new->phrase = malloc(sizeof(char) * 101);
    new->phrase = phrase;
    new->next = l->head;
    l->head = new;
}

char * take_it_out(LinkedStack * l){
    if(l->head == NULL) return "NULL";
    Node * temp = l->head;
    l->head = l->head->next;
    return temp->phrase;
}

int main(void){
    LinkedStack lines;
    initialize(&lines);
    char command[9];
    while(scanf("%s", command) == 1){
        if(equals(command, "desfazer")) printf("%s\n", take_it_out(&lines));
        else{
            char * phrase = malloc(sizeof(char) * 101);
            scanf("\n%[^\n]s", phrase);
            put_it_on(&lines, phrase);
        }
    }
}