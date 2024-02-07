#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} node;

node *createNode() { return (node *)malloc(sizeof(node)); }

node *addNode(node *ptr)
{
    node *new = createNode();
    if (new)
    {
        printf("Enter element: ");
        scanf("%d", &new->data);
        if (ptr)
            ptr->link = new;
        else
            ptr = new;
    }
    else
        printf("Memory Full.");
    return new;
}

node *createLinkedList()
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
    ptr->link = NULL;
    return head;
}

void insertAtStart(node **head)
{
    node *new = createNode();
    if (new)
    {
        printf("Enter element: ");
        scanf("%d", &new->data);
        new->link = *head;
        *head = new;
        printf("Element inserted successfully.");
    }
    else
        printf("Memory Full.");
}

void insertNode(node *head)
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
            head = head->link;
        if (head)
        {
            new->link = head->link;
            head->link = new;
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
        (*head) = temp->link;
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

        while (head && head->link->data != elem)
            head = head->link;
        if (head)
        {
            node *temp = head->link;
            head->link = temp->link;
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
            head = head->link;
        }
    }
    else
        printf("Linked List is empty.");
}

int main()
{
    node *head = createLinkedList();
    int ch, flag = 1;
    while (flag)
    {
        printf("\nMenu-driven Program:\n\n1) Insert at Start\n2) Insert Node\n3) Delete at Start\n4) Delete Node\n5) Display all Elements\n6) Exit\n\nEnter choice: ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            insertAtStart(&head);
            break;
        case 2:
            insertNode(head);
            break;
        case 3:
            deleteAtStart(&head);
            break;
        case 4:
            deleteNode(head);
            break;
        case 5:
            displayAll(head);
            break;
        case 6:
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
