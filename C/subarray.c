#include <stdio.h>
// subarray
void subarray(int arr[], int start, int end, int size)
{
    if (end == size)
        return;
    else if (start > end)
    {
        subarray(arr, 0, end + 1, size);
    }
    else
    {
        printf("{");
        for (int i = start; i < end; i++)
        printf("%d, ", arr[i]);
        printf("%d}\n", arr[end]);
    }
    subarray(arr, start + 1, end, size);
}
int main()
{
    int n, arr[20], start, end, i;
    printf("Enter the size of array :\n");
    scanf("%d", &n);
    printf("enter the elements of the array :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("the subarrays are :\n");
    subarray(arr, 0, 0, n);
    return 0;
}