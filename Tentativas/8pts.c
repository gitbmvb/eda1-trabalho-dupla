#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int carros[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &carros[i]);
    }
    
    int sideStreet[n];
    int finalOrder[n];
    int countS = 0;
    int countF = 0;

    for (int i = 0; i < n-1; i++)
    {
        if(carros[i] > carros[i+1]){sideStreet[countS++] = carros[i];}
        else if(carros[i] > sideStreet[countS]){
            finalOrder[countF++] = sideStreet[countS--];
            sideStreet[countS++] = carros[i];    
        }
        else{finalOrder[countF++] = carros[i];}
    }
    
    if(carros[n-1] > sideStreet[countS-1]){
        finalOrder[countF++] = sideStreet[countS--];
        sideStreet[countS++] = carros[n-1];    
    }
    else{finalOrder[countF++] = carros[n-1];}

    for (int i = countS - 1; i > -1; i--)
    {
        finalOrder[countF++] = sideStreet[i]; 
    }

    for (int i = 0; i < countF - 1; i++)
    {
        if (finalOrder[i] > finalOrder[i+1])
        {
            printf("no\n");
            return 0;
        }
        
    }
    printf("yes\n");
    

    return 0;
}