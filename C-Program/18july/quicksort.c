#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high)
{
    int temp;
    int i = low + 1;
    int j = high;
    int pivot = arr[low];
    do
    {
        while (pivot >= arr[i])
        {
            i++;
        }
        while (pivot < arr[j])
        {
            j--;
        }
        if (i < j)
        {
            // swap(&arr[i], &arr[j]);
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }

    } while (i < j);
    // swap(&arr[low], &arr[j]);
    temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;
}
void quicksort(int *arr, int low, int high)
{
    int partitionindex; // pivot index
    if (low < high)
    {
        partitionindex=partition(arr, low, high);
        quicksort(arr, low, partitionindex - 1);  // sort left subarray
        quicksort(arr, partitionindex + 1, high); // sort right subarray
    }
}
void display(int *arr)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]);
    }
}
int main()
{
    int arr[] = {3, 5, 2, 12, 5};
    quicksort(arr, 0, 4);

    display(arr);
}