#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void linkedlist_traversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("Element: %d\n", ptr -> data);
        ptr = ptr -> next;
    }
}
struct Node* insertatbeginning(struct Node *head, int data)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> next = head;
    ptr -> data = data;
    return ptr; 
}
int main()
{
    struct Node *head = (struct Node*)malloc (sizeof(struct Node));
    struct Node *second = (struct Node*)malloc (sizeof(struct Node));
    struct Node *third = (struct Node*)malloc (sizeof(struct Node));
    struct Node *fourth = (struct Node*)malloc (sizeof(struct Node));
    head -> data = 7;
    head -> next = second;
    second -> data = 10;
    second -> next = third;
    third -> data = 15;
    third -> next = fourth;
    fourth -> data = 20;
    fourth -> next = NULL;
    printf("Linked list before insertion:\n");
    linkedlist_traversal(head);
    head = insertatbeginning(head, 5);
    printf("Linked list after insertion at the beginning:\n");
    linkedlist_traversal(head);
    return 0;
}