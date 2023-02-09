#include <stdio.h>

int main(){
    int carro;
    int pilha[1001];
    int n;
    char resposta;

    while(scanf("%d",&n) && n != 0){
        int topo=-1;
        int esperado=1;
        resposta=121;

        for(int i = 0; i < n; i++){
            scanf("%d",&carro);
            if(carro != esperado){
                pilha[++topo]=carro;
            } else {
                esperado++;
                if(topo != -1){
                    while(pilha[topo] == esperado){
                        esperado++;
                        topo--;
                        if(topo==-1)break;
                    }
                }
            }
        }
        while(topo >= 0){
            if(pilha[topo] != esperado){
                resposta = 110;
                break;
            }
            topo--;
            esperado++;
        }
        if (resposta == 121){
            printf("yes\n");
        }
        else printf("no\n");
    }
    return 0;
}