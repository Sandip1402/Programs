#include<iostream>
using namespace std;
void printstar(int lines)
{
    int i, j, flag;
    for(i = 1; i <= lines; i++)
    {
        flag = 1;
        for(j = 1; j <= 2 * lines - 1; j++)
        {
            if(j<=lines - 1 + i && j >= lines + 1 - i)
            {
                if(flag)
                cout << "*";
                else
                cout << " ";
                flag = 1 - flag;
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    int i, j, n, a[20], b[20];
    printf("Enter no. of lines :\n");
    scanf("%d", &n);
    printf("pascal's triangle is :");
    printf("\n");
    for(j = 0; j < n; j++)
    {
        b[0] = 1;
        b[j] = 1;
        for(i = 0; i < n - j; i++)
        printf(" ");
        for(i = 0; i <= j; i++)
        printf("%d ", b[i]);
        printf("\n");
        // copying in other array
        for(i = 0; i <= j; i++)
        a[i] = b[i];
        a[i] = 1;
        // next line middle values
        for(i = 0; i <= j - 1; i++)
        {
            b[i + 1] = a[i] + a[i + 1];
        }
    }
return 0;
}