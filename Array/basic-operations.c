/*
This file contains the basic operations which can be performed on an array. The following functions are implemented in this program:
1) Insert at End: It inserts an element at the end of an array.
2) Insert without Order: It inserts an element at any given position of the array and shifts the element at that position to the end of the array. So, it doesn't maintain the order of the array.
3) Insert with Order: It inserts an element at any given position of the array and shifts all the elements to the next position till the end of the array. So, it maintains the order of the array after insertion.
4) Delete at End: It deletes the element at the end of an array.
5) Delete without Order: It deletes an element at any given position of the array and shifts the element at the end of the array to that position. So, it doesn't maintain the order of the array.
6) Delete with Order: It deletes an element at any given position of the array and shifts all the elements to the previous position till the end of the array. So, it maintains the order of the array after deletion.
7) Display All: It displays all the elements of the array.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size, elements, *arr;
} array;

array *createArray()
{
    array *arr = (array *)malloc(sizeof(array));
    printf("Enter size: ");
    scanf("%d", &arr->size);
    arr->elements = 0;
    arr->arr = (int *)malloc(sizeof(int) * arr->size);
}

void isEmpty(array *arr, void (*func)(array *))
{
    if (arr->elements)
        func(arr);
    else
        printf("Array is empty.");
}

void isFull(array *arr, void (*func)(array *))
{
    if (arr->elements < arr->size)
        func(arr);
    else
        printf("Array is full.");
}

void insertAtEnd(array *arr)
{
    printf("Enter element: ");
    scanf("%d", &arr->arr[arr->elements++]);
    printf("Element added successfully.");
}

void insertwithoutOrder(array *arr)
{
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (0 < pos && pos < arr->elements)
    {
        arr->arr[arr->elements++] = arr->arr[--pos];
        printf("Enter element: ");
        scanf("%d", &arr->arr[pos]);
        printf("Element inserted successfully.");
    }
    else
        printf("Position must be in the range.");
}

void insertwithOrder(array *arr)
{
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (0 < pos && pos < arr->elements)
    {
        int i;
        for (i = arr->elements++; i >= pos; i--)
            arr->arr[arr->elements - i] = arr->arr[arr->elements - i - 1];

        printf("Enter element: ");
        scanf("%d", &arr->arr[--pos]);
        printf("Element inserted successfully.");
    }
    else
        printf("Position must be in the range.");
}

void deleteAtEnd(array *arr)
{
    arr->arr[--arr->elements];
    printf("Element deleted successfully.");
}

void deletewithoutOrder(array *arr)
{
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (0 < pos && pos < arr->elements)
    {
        arr->arr[--pos] = arr->arr[--arr->elements];
        printf("Element deleted successfully.");
    }
    else
        printf("Position must be in the range.");
}

void deletewithOrder(array *arr)
{
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (0 < pos && pos < arr->elements--)
    {
        int i;
        for (i = --pos; i < arr->elements; i++)
            arr->arr[i] = arr->arr[i + 1];
        printf("Element deleted successfully.");
    }
    else
        printf("Position must be in the range.");
}

void displayAll(array *arr)
{
    int i;
    printf("The elements of the array are:\n");
    for (i = 0; i < arr->elements; i++)
        printf("%-6d", arr->arr[i]);
}

int main()
{
    array *arr = createArray();
    int ch, flag = 1;
    void (*fullFunctions[])(array *) = {insertAtEnd, insertwithoutOrder, insertwithOrder}, (*emptyFunctions[])(array *) = {deleteAtEnd, deletewithoutOrder, deletewithOrder, displayAll};

    while (flag)
    {
        printf("Menu-driven Program:\n\n1) Insert at End\n2) Insert w/o Order\n3) Insert with Order\n4) Delete at End\n5) Delete w/o order\n6) Delete with Order\n7) Display all Elements\n8) Exit\n\nEnter choice: ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1 ... 3:
            isFull(arr, fullFunctions[ch - 1]);
            break;
        case 4 ... 7:
            isEmpty(arr, emptyFunctions[ch - 4]);
            break;
        case 8:
            printf("Exiting...");
            break;
        default:
            printf("Enter a valid choice.");
        }
        printf("\n\n");
    }
    return 0;
}
