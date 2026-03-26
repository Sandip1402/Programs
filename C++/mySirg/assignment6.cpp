// swap using call by reference
#include <iostream>
#include <string.h>
using namespace std;
void swap(int &m, int &n)
{
    m = m + n;
    n = m - n;
    m = m - n;
}
void arrange (int ar[], int size, bool a = true);
// mysirg
void arrange_str(char str[][20], int size, bool a = true);
// mysirg
void rotate(int a[], int size, int d = 1, int n = 1);
void arrange(int ar[], int size, bool a)
{
    int i, t, j;
    for(i = 0; i < size; i++)
    {
        for(j = i + 1; j < size; j++)
        {
            if(a == true && ar[i] > ar[j])
            {
                t = ar[i];
                ar[i] = ar[j];
                ar[j] = t;
            }
            else if(a == false && ar[i] < ar[j])
            {
                t = ar[i];
                ar[i] = ar[j];
                ar[j] = t;
            }
        }
    }
    cout << "after arrangement" << endl;
    for(i = 0; i < size; i++)
    cout << ar[i] << endl;
}
int checkprime(int n)
{
    int i;
    for(i = 2; i <= n / 2; i++)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
void primefactor(int n)
{
    int i;
    for(i = 2; i <= n / 2; i++)
    {
        if(n % i == 0 && checkprime(i))
        cout << i << endl;
    }
}
void lcm(int a, int b, int c)
{
    int i, l;
    l = a > b ? a : (b > c ? b : c);
    cout << "l is " << l << endl;
    for(i = l; i <= a * b * c; i++)
    {
        if(i % a == 0 && i % b == 0 && i % c == 0)
        {
            cout << "lcm is " << i;
            break;
        }
    }
}
// mysirg
void arrange_str(char str[][20], int size, bool a)
{
    int i, j;
    char t[100];
    for(i = 0; i < size; i++)
    {
        for(j = 0; j <= size - 1 - i; j++)
        {
            if(a == true && strcmp(str[i],str[i + 1]) > 0)
            {
                strcpy(t,str[i]);
                strcpy(str[i],str[i + 1]);
                strcpy(str[i + 1],t);
            }
            else if(a == false && strcmp(str[i],str[i + 1]) < 0)
            {
                strcpy(t,str[i]);
                strcpy(str[i],str[i + 1]);
                strcpy(str[i + 1],t);
            }
        }
    }
}
// mysirg
void rotate(int a[], int size, int d, int n)
{
    int i, t, r;
    if(d == 1)
    {
        for(i = 1; i <= n; i++)
        {
            t = a[size - 1];
            for(r = size - 1; r > 0; r--)
            a[r] = a[r - 1];
            a[0] = t;
        }
    }
    if(d == -1)
    {
        for(i = 1; i <= n; i++)
        {
            t = a[0];
            for(r = 1; r < size; r++)
            a[r - 1] = a[r];
            a[size - 1] = t;
        }
    }
    for(i = 0; i < size; i++)
    cout << a[i] << endl;
}
int main()
{
    char str[][20] = {"kanpur", "bihar", "patna"};
    arrange_str(str, 20, true);
    for(int i = 0; i < 3; i++)
    cout << str[i] << " ";
    return 0;                                              
}