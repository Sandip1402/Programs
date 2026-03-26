#include <iostream>
#include <string.h>
using namespace std;
int HCF(int, int);
void strinex(char [], int in, int ex = -1);
int HCF(int a, int b)
{
    int rem;
    rem = b % a;
    if (rem == 0)
        return a;
    else if (rem != 0)
    {
        HCF(rem, a);
    }
}
// mysirg
void strinex(char str[], int in, int ex)
{
    int i;
    if(ex == -1)
    {
        ex = strlen(str);
    }
    for(i = in; i < ex; i++)
    cout << str[i];
}
// mysirg
int* merge(int a[], int b[], int size)
{
    int i, j, k;
    int *arr = (int *) malloc(2 * size * sizeof(int));
    for(i = 0, j = 0, k = 0; i < size && j < size; k++)
    {
        if(a[i] < b[j])
        {
            arr[k] = a[i];
            i++;
        }
        else
        {
            arr[k] = b[j];
            j++;
        }
    }
        while(i < size)
        {
            arr[k] = a[i];
            i++;
            k++;
        }
        while(j < size)
        {
            arr[k] = a[j];
            j++;
            k++;
        }
    return arr;
}
int main()
{
    char str[] = "technointernational";
    strinex(str, 5, -1);
    return 0;
}