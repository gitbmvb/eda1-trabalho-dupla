/* 
 * C Program To Count the Occurrence of a Substring in String 
 */
#include <stdio.h>
#include <string.h>
 
char str[100], sub[100];
 
void main()
{
    int i, j, l, l1, l2;
    int count = 0, count1 = 0;
 
    printf("\nEnter a string : ");
    scanf("%s", str);
 
    l1 = strlen(str);
 
    printf("\nEnter a substring : ");
    scanf(" %s", sub);
 
    l2 = strlen(sub);
 
    for (i = 0; i < l1;)
    {
        j = 0;
        count = 0;
        while ((str[i] == sub[j]))
        {
            count++;
            i++;
            j++;
        }
        if (count == l2)
        {
            count1++;                                   
            count = 0;
        }
        else
            i++;
    }    
    printf("%d\n", count1);
}