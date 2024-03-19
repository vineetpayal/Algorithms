#include <stdio.h>

void merge(int arr[], int low, int mid, int hight)
{
    int n1 = mid - low + 1;
    int n2 = hight - mid;

    // copying two subarrays into left and right
    int left[n1], right[n2];
    int i, j;
    for (i = 0; i < n1; i++)
    {
        left[i] = arr[low + i];
    }
    for (j = 0; j < n2; j++)
    {
        right[j] = arr[mid + j + 1];
    }

    // Now merge the two arrays in sorted order
    i = 0, j = 0;
    int k = low;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = right[j];
            j++;
            k++;
        }
    }

    // Now merging the remaining numbers in either left or right
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);      // sort left part
        mergeSort(arr, mid + 1, high); // sort right part
        merge(arr, low, mid, high);    // merge left and right part
    }
}

int main()
{
    int n;
    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    // input array
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // sorting
    mergeSort(arr, 0, n);

    printf("After sorting: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}