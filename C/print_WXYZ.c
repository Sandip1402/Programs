#include <stdio.h>
int main()
{
    char str[] = "pqrstu";
    int n, i, j, k;
    printf("enter no of lines :");
    scanf("%d", &n);
    for(i = 0; i <= n/2; i++)
    {
        for(j = 0; j < (n/2 - i); j++)
        printf(" ");
        for(k = 0; k <= i; k++)
        printf("%c ", str[k]);
        printf("\n");
    }
    for(i = n/2; i > 0; i--)
    {
        for(j = 0; j <= (n/2 - i); j++)
        printf(" ");
        for(k = 0; k < i; k++)
        printf("%c ", str[k]);
        printf("\n");
    }
return 0;
}












