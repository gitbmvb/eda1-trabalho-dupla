#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define equals(A, B) (strcmp(A, B) == 0)
typedef int Item;
typedef struct node { Item value; struct node * previous, * next; } Node;
typedef struct ada_queue { Node * head, * tail; int used, reversed; } AdaQueue;

void initialize(AdaQueue * aq){ aq->head = NULL; aq->tail = NULL; aq->used = 0; aq->reversed = 0; }

void enqueue(AdaQueue * aq, char * command, Item e){
    Node * new = malloc(sizeof(Node));
    new->previous = NULL; new->next = NULL; new->value = e;
    aq->used++;
    if(aq->head == NULL && aq->tail == NULL){ aq->head = new; aq->tail = new; return; }
    else if(equals(command, "push_back") && aq->reversed == 0){ aq->tail->next = new; new->previous = aq->tail; aq->tail = new; }
    else if(equals(command, "push_back") && aq->reversed == 1){ aq->tail->previous = new; new->next = aq->tail; aq->tail = new; }
    else if(equals(command, "toFront") && aq->reversed == 0){ aq->head->previous = new; new->next = aq->head; aq->head = new; }
    else if(equals(command, "toFront") && aq->reversed == 1){ aq->head->next = new; new->previous = aq->head; aq->head = new; }
}

void dequeue(AdaQueue * aq, char * command){
    if(aq->used == 0) {printf("No job for Ada?\n"); return; }
    else if(equals(command, "back")){
        if(aq->used == 1){
            printf("%d\n", aq->head->value);
            free(aq->head);
            aq->head = NULL;
            aq->tail = NULL;
        }
        else if(aq->reversed == 0){
            Node * temp = aq->tail;
            aq->tail = aq->tail->previous;
            aq->tail->next = NULL;
            printf("%d\n", temp->value);
            free(temp);
        }
        else if(aq->reversed == 1){
            Node * temp = aq->tail;
            aq->tail = aq->tail->next;
            aq->tail->previous = NULL;
            printf("%d\n", temp->value);
            free(temp);
        }
    } else if(equals(command, "front")){
        if(aq->used == 1){
            printf("%d\n", aq->head->value);
            free(aq->head);
            aq->head = NULL;
            aq->tail = NULL;
        }
        else if(aq->reversed == 0){
            Node * temp = aq->head;
            aq->head = aq->head->next;
            aq->head->previous = NULL;
            printf("%d\n", temp->value);
            free(temp);
        }
        else if(aq->reversed == 1){
            Node * temp = aq->head;
            aq->head = aq->head->previous;
            aq->head->next = NULL;
            printf("%d\n", temp->value);
            free(temp);
        }
    }
    aq->used--;
}

void reverse(AdaQueue * aq){
    Node * temp = aq->tail;
    aq->tail = aq->head;
    aq->head = temp;
    // printf("Now head is %d and tail is %d\n", aq->head->value, aq->tail->value);
    aq->reversed = aq->reversed ? 0 : 1;
}

int main(void){
    int lines;
    char command[10];
    AdaQueue ada;
    scanf("%d", &lines);
    for(int i = 0; i < lines; i++){
        scanf("%s", command);
        if(equals(command, "front") || equals(command, "back")) dequeue(&ada, command);
        else if(equals(command, "push_back") || equals(command, "toFront")){
            int number;
            scanf("%d", &number);
            enqueue(&ada, command, number);
        }
        else if(equals(command, "reverse")) reverse(&ada);
    }
}