#include "../Includes/push_swap.h"

void    print_array(int *arr, int n)
{
    int i;

    i = 0;
    printf("printing the stack to be sorted\n");
    while (i < n)
    {
        printf("[%d] %d\n",i, arr[i]);
        i++;
    }
}

 void swap(int *arr, int i, int largest) 
 {
    int temp;

    temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
}

void    heapify(int *arr, int n, int i)
{   
    int largest;
    int left;
    int right;
    
    largest = i;
    left = (2 * i) + 1;
    right = (2 * i) + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(arr, i, largest);
        heapify(arr, n, largest);
    }
}

void    sort_number(t_data *data, int n)
{
    int     i;

    i = (n / 2) - 1;
    while(i >= 0)
    {
        heapify(data->req_pos, n, i);
        i--;
    }
    i = n - 1;
    while (i >= 0)
    {
        swap(data->req_pos, 0, i);
        heapify(data->req_pos, i, 0);
        i--;
    }
}