#include <stdio.h>
#include <stdlib.h>
struct Node
{   
    int data;
    struct Node *prev;
    struct Node *next;
}; 
struct Node *head = NULL;
void pushfront(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
}
void pushback(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    struct Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->prev = ptr;
}
void pushatindex(int data, int index)
{
    if (index == 0)
    {
        pushfront(data);
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node *ptr = head;
    for (int i = 0; i < index - 1; i++)
    {
        if (ptr == NULL)
        {
            printf("Index out of bounds\n");
            free(newNode);
            return;
        }
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Index out of bounds\n");
        free(newNode);
        return;
    }
    newNode->next = ptr->next;
    newNode->prev = ptr;
    if (ptr->next != NULL)
    {
        ptr->next->prev = newNode;
    }
    ptr->next = newNode;
}
void popfront()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(temp);
}
void popback()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    if (ptr->prev != NULL)
    {
        ptr->prev->next = NULL;
    }
    else
    {
        head = NULL; // List had only one node
    }
    free(ptr);
}
void traverse()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int main()
{
    printf("Enter the number of nodes: ");
    int n,i;
    scanf("%d", &n);
    int choice, data, index;
    for (i = 0; i < n; i++)
    {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        pushback(data);
    }
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert at first\n");
        printf("2. Insert at end\n");
        printf("3. Insert at index\n");
        printf("4. Delete at first\n");
        printf("5. Delete at end\n");
        printf("6. Traverse\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                pushfront(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                pushback(data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter index: ");
                scanf("%d", &index);
                pushatindex(data, index);
                break;
            case 4:
                popfront();
                break;
            case 5:
                popback();
                break;
            case 6:
                traverse();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}