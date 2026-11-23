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
    linkedlist_traversal(head);
    return 0;
}