#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void traverse(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL)
    {
        newNode->next = newNode; // Point to itself
        return newNode;
    }
    struct Node *ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = head;
    return newNode; // New node becomes the new head
}
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL)
    {
        newNode->next = newNode; // Point to itself
        return newNode;
    }
    struct Node *ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = head;
    return head; // Head remains the same
}
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (index == 0)
    {
        return insertAtFirst(head, data);
    }
    struct Node *ptr = head;
    for (int i = 0; i < index - 1; i++) 
    {
        ptr = ptr->next;
        if (ptr == head) // If index is out of bounds
        {
            printf("Index out of bounds\n");
            free(newNode);
            return head;
        }
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
    return head;
}
struct Node *deleteAtFirst(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    struct Node *ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    struct Node *temp = head;
    if (head->next == head) // Only one node
    {
        free(head);
        return NULL;
    }
    ptr->next = head->next;
    head = head->next;
    free(temp);
    return head;
}
struct Node *deleteAtEnd(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    struct Node *ptr = head;
    struct Node *prev = NULL;
    while (ptr->next != head)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    if (prev == NULL) // Only one node
    {
        free(head);
        return NULL;
    }
    prev->next = head;
    free(ptr);
    return head;
}
struct Node *deleteAtIndex(struct Node *head, int index)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    if (index == 0)
    {
        return deleteAtFirst(head);
    }
    struct Node *ptr = head;
    struct Node *prev = NULL;
    for (int i = 0; i < index; i++)
    {   
        prev = ptr;
        ptr = ptr->next;
        if (ptr == head) // If index is out of bounds
        {
            printf("Index out of bounds\n");
            return head;
        }
    }
    prev->next = ptr->next;
    free(ptr);
    return head;
}   
void Traverse(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *ptr = head;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}
int main()
{
    int choice, data, index;
    struct Node *head = NULL;
    printf("Enter the number of nodes: ");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int data;
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert at first\n");
        printf("2. Insert at end\n");
        printf("3. Insert at index\n");
        printf("4. Delete at first\n");
        printf("5. Delete at end\n");
        printf("6. Delete at index\n");
        printf("7. Traverse\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter data to insert at first: ");
                scanf("%d", &data);
                head = insertAtFirst(head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter index and data to insert: ");
                scanf("%d %d", &index, &data);
                head = insertAtIndex(head, data, index);
                break;
            case 4:
                head = deleteAtFirst(head);
                break;
            case 5:
                head = deleteAtEnd(head);
                break;
            case 6:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                head = deleteAtIndex(head, index);
                break;
            case 7:
                Traverse(head);
                break;
            case 8:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}