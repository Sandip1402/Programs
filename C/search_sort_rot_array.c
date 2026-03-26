#include <stdio.h>
// search in sorted and rotated array
int sort(int arr[], int key, int size)
{
    int low, mid, high;
    low = 0; high = size - 1;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(key == arr[mid])
        {
            return mid;
        }
        if(arr[low] < arr[mid])
        {
            if(key < arr[mid] && key >= arr[low])
            high = mid - 1;
            else
            low = mid + 1;
        }
        else
        {
            if(key > arr[mid] && key <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
}
int main()
{
    int n , key;
    printf("enter size of array :\n");
    scanf("%d", &n);
    int arr[n];
    printf("enter sorted and rotated array :\n");
    for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
    printf("enter key :\n");
    scanf("%d", &key);
    printf("element is at %d position.", sort(arr, key, n));
    return 0;
}
