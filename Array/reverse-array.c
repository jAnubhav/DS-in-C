/*
This program reverses an array.
*/

#include <stdio.h>

void displayAll(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%-6d", arr[i]);
    printf("\n");
}

void reverse(int *arr, int size)
{
    int temp, i;
    for (i = 0; i < size / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

int main()
{
    int size, i, arr[100];
    printf("Enter size: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++)
    {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    printf("\nThe array before reversal is:\n");
    displayAll(arr, size);

    reverse(arr, size);
    
    printf("\nThe array after reversal is:\n");
    displayAll(arr, size);

    return 0;
}
