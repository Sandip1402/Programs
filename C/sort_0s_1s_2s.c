#include <stdio.h>
void swap(int *a, int *b);
void sort(int arr[], int size)
{
    int lo, mid, hi;
    lo = 0;
    mid = 0;
    hi = size - 1;
    // sorting
    while(mid <= hi)
    {
        switch(arr[mid])
        {
            // for 0
            case 0: swap(&arr[lo], &arr[mid]);
                    lo++; mid++;
                    break;
            // for 1
            case 1: mid++;
                    break;
            // for 2
            case 2: swap(&arr[mid], &arr[hi]);
                    hi = hi - 1; mid++;
                    break;
        }
    }
}
int main()
{
    int n;
    printf("enter size of array :");
    scanf("%d", &n);
    int arr[n];
    // input array
    printf("enter elements of array to sort(only 0,1,2):");
    for(int i = 0; i < n; i++)
    scanf("%d", arr + i);
    sort(arr, n);
    for(int i = 0; i < n; i++)
    printf("%d ", *(arr + i));
    return 0;
}
void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}