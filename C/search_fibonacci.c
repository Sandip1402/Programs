// find an element in fibonacci series
#include <stdio.h>
int main()
{
    int n, a = 0, b = 1, c = 0, f = 0;
    printf("enter search element :");
    scanf("%d", &n);
    while(c <= n)
    {
        if(c == n)
        {
            f = 1;
            break;
        }
        c = a + b;
        a = b;
        b = c;
    }
    if(f == 1)
        printf("%d found",n);
    else
        printf("%d not found.", n);
    return 0;
}