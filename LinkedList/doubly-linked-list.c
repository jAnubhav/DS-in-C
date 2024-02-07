#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev, *next;
} node;

typedef struct
{
    node *head, *end;
} ptrs;

node *createNode() { return (node *)malloc(sizeof(node)); }

node *addNode(node *ptr)
{
    node *new = createNode();
    if (new)
    {
        printf("Enter element: ");
        scanf("%d", &new->data);
        if (ptr)
        {
            ptr->next = new;
            new->prev = ptr;
        }
        else
        {
            ptr = new;
            ptr->prev = NULL;
        }
    }
    else
        printf("Memory Full.");
    return new;
}

ptrs createLinkedList()
{
    int size, i;
    node *head, *ptr;
    head = ptr = NULL;

    printf("Creating Initial Linked List...\nEnter size: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++)
    {
        ptr = addNode(ptr);
        if (!i)
            head = ptr;
    }
    ptr->next = NULL;
    ptrs p = {head, ptr};
    return p;
}

void insertAtStart(node **head)
{
    node *new = createNode();
    if (new)
    {
        printf("Enter element: ");
        scanf("%d", &new->data);
        new->next = *head;
        new->prev = NULL;
        (*head)->prev = new;
        *head = new;
        printf("Element inserted successfully.");
    }
    else
        printf("Memory Full.");
}

void insertBefore(node *head)
{
    node *new = createNode();
    if (new)
    {
        int elem;
        printf("Enter element: ");
        scanf("%d", &new->data);

        printf("Enter element before which node is to be inserted: ");
        scanf("%d", &elem);

        while (head && head->data != elem)
            head = head->next;
        if (head)
        {
            new->next = head;
            new->prev = head->prev;
            head->prev->next = new;
            head->prev = new;
            printf("Element inserted successfully.");
        }
        else
            printf("No such element present.");
    }
    else
        printf("Memory Full.");
}

void insertAfter(node *head)
{
    node *new = createNode();
    if (new)
    {
        int elem;
        printf("Enter element: ");
        scanf("%d", &new->data);

        printf("Enter element after which node is to be inserted: ");
        scanf("%d", &elem);

        while (head && head->data != elem)
            head = head->next;
        if (head)
        {
            new->prev = head;
            new->next = head->next;
            head->next->prev = new;
            head->next = new;
            printf("Element inserted successfully.");
        }
        else
            printf("No such element present.");
    }
    else
        printf("Memory Full.");
}

void deleteAtStart(node **head)
{
    if (head)
    {
        node *temp = *head;
        (*head) = temp->next;
        (*head)->prev = NULL;
        free(temp);
        printf("Element deleted successfully.");
    }
    else
        printf("Linked List is empty.");
}

void deleteNode(node *head)
{
    if (head)
    {
        int elem;
        printf("Enter element: ");
        scanf("%d", &elem);

        while (head && head->next->data != elem)
            head = head->next;
        if (head)
        {
            node *temp = head->next;
            head->next = temp->next;
            free(temp);
            printf("Element deleted succesfully.");
        }
        else
            printf("No such element present.");
    }
    else
        printf("Linked List is empty.");
}

void displayAll(node *head)
{
    if (head)
    {
        printf("The elements of the Linked List are:\n");
        while (head)
        {
            printf("%-6d", head->data);
            head = head->next;
        }
    }
    else
        printf("Linked List is empty.");
}

void reverseDisplayAll(node *end) {
    if (end)
    {
        printf("The elements of the Linked List are:\n");
        while (end)
        {
            printf("%-6d", end->data);
            end = end->prev;
        }
    }
    else
        printf("Linked List is empty.");
}

int main()
{
    ptrs ptr = createLinkedList();
    node *head, *end;
    head = ptr.head, end = ptr.end;
    int ch, flag = 1;
    while (flag)
    {
        printf("\nMenu-driven Program:\n\n1) Insert at Start\n2) Insert Before\n3) Insert After\n4) Delete at Start\n5) Delete Node\n6) Display all Elements\n7) Reverse Display all Elements\n8) Exit\n\nEnter choice: ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            insertAtStart(&head);
            break;
        case 2:
            insertBefore(head);
            break;
        case 3:
            insertAfter(head);
            break;
        case 4:
            deleteAtStart(&head);
            break;
        case 5:
            deleteNode(head);
            break;
        case 6:
            displayAll(head);
            break;
        case 7:
            reverseDisplayAll(end);
            break;
        case 8:
            printf("Exiting...");
            flag = 0;
            break;
        default:
            printf("Enter a valid choice.");
        }
        printf("\n\n");
    }
    return 0;
}
