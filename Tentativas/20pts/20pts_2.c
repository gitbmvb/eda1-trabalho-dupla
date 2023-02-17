#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define equals(A, B) (strcmp(A, B) == 0)
#define exch(A, B) strcpy(A.itself, B.itself); strcpy(A.previous, B.previous);strcpy(A.next, B.next);
typedef struct node { char * itself, * previous, * next;} Node;
typedef struct queue {} Queue;

void initialize_node(Node * n){
    n->itself = malloc(sizeof(char) * 9);
    n->previous = malloc(sizeof(char) * 9);
    n->next = malloc(sizeof(char) * 9);
}

void quit(){
    printf("insana\n");
    exit(1);
}

int main(void){
    Node left, right, temp;
    initialize_node(&left); initialize_node(&right); initialize_node(&temp);
    scanf("%s %s %s", left.itself, left.previous, left.next);
    scanf("%s %s %s", right.itself, right.previous, right.next);
    while(scanf("%s %s %s", temp.itself, temp.previous, temp.next) == 1){
        if(equals(left.next, temp.itself) && equals(temp.previous, left.itself)) {exch(left, temp);}
        else if(equals(right.previous, temp.itself) && equals(temp.next, right.itself)) {exch(left, temp);}
        else if(equals(left.next, temp.itself) && !equals(temp.previous, left.itself)) quit();
        else if(equals(right.previous, temp.itself) && !equals(temp.next, right.itself)) quit();
        else{
            enqueue(&standby, temp);
        }
    }
    printf("sana\n");
}