#include <stdio.h>
#include <stdlib.h>

typedef struct tower { int x, y;} Tower;

int main(void){
    int l, c, towers_len = 0, h, counter = 0;
    scanf("%d %d", &l, &c);
    char field[l][c], aux;
    Tower towers [l * c];
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            scanf("%c", &aux);
            if(aux == '\n') scanf("%c", &aux);
            field[i][j] = aux;
            if(aux == 't') towers[towers_len++] = (Tower){i, j};
        }
    }
    for(int i = 0; i < towers_len; i++){
        scanf("%d", &h);
        for(int j = towers[i].x - h; j <= towers[i].x + h; j++){
            for(int k = towers[i].y - h; k <= towers[i].y + h; k++){
                if(j >= 0 && j < l && k >= 0 && k < c && field[j][k] == '#'){
                    field[j][k] = '.';
                    counter++;
                }
            }
        }    
    }
    printf("%d\n", counter);
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            printf("%c", field[i][j]);        
        }
        printf("\n");
    }
}