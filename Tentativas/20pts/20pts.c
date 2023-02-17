#include <stdio.h>
#include <stdlib.h>
typedef struct item {long unsigned int itself, previous, next;} Item;
typedef struct queue {Item * v; int begin, end, size, used;} Queue;

void initialize(Queue * q, int s){
    q->v = malloc(sizeof(Item) * s);
    q->begin = 0; q->end = 0; q->size = s; q->used = 0;
}

void enqueue(Queue * q, Item e){
    q->v[q->end] = e;
    q->end = (q->end + 1) % q->size;
    q->used++;
}

int is_empty(Queue * q){ return q->used == 0;}

void quit(){
    printf("insana\n");
    exit(0);
}

int main(void){
    Item left, right, temp;
    Queue standby;
    initialize(&standby, 100);
    scanf("%lx %lx %lx", &left.itself, &left.previous, &left.next);
    scanf("%lx %lx %lx", &right.itself, &right.previous, &right.next);
    while(scanf("%lx %lx %lx", &temp.itself, &temp.previous, &temp.next) == 1){
        printf("ok\n");
        printf("reading {%lx, %lx, %lx}\n", temp.itself, temp.previous, temp.next);
        if(left.next == temp.itself && temp.previous == left.itself) left = temp;
        else if(right.itself == temp.next && right.previous == temp.itself) right = temp;
        else if(left.next == temp.itself && temp.previous != left.itself) quit();
        else if(right.itself == temp.next && right.previous != temp.itself) quit();
        else if(left.next != temp.itself && temp.previous == left.itself) quit();
        else if(right.itself != temp.next && right.previous == temp.itself) quit();
        else enqueue(&standby, temp);
    }
    is_empty(&standby) ? printf("sana\n") : printf("insana\n");
}