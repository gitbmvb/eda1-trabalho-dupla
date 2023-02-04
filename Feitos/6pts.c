#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int valor;
    int prox;
}Item;

int main(){
    int n, aux, index = 0;
    scanf("%d", &n);
    Item vetor[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &vetor[i].id, &vetor[i].valor, &vetor[i].prox);
    }

    aux = vetor[index].valor;
    while (aux != -1)
    {
        printf("%d\n", aux);
        aux = vetor[index].prox;

        for (int i = 1; i < n; i++)
        {
            if (vetor[i].id == aux){
                aux = vetor[i].valor;
                index = i; 
                break;
            }
        }
    }

    return 0;
}