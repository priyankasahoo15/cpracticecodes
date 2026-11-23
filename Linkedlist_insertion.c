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
struct Node* insertatindex(struct Node *head, int data,int index)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while(i != index - 1)
    {
        p = p -> next;
        i++;
    }
    ptr -> data = data;
    ptr -> next = p -> next;
    p -> next = ptr;
    return head;
}
struct Node* insertatend(struct Node *head, int data)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    while(p -> next != NULL)
    {
        p = p -> next;
    }
    ptr -> data = data;
    ptr -> next = NULL;
    p -> next = ptr;
    return head;
}
struct Node* insertafternode(struct Node *head,struct Node *prevnode, int data)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr -> next = prevnode -> next;
    prevnode -> next = ptr;
    return head; 
}
int main()
{
    struct Node *head = (struct Node*)malloc (sizeof(struct Node));
    struct Node *newNode = (struct Node*)malloc (sizeof(struct Node));
    while(newNode != NULL)
    {
        printf("Enter data for the node (enter -1 to stop): ");
        scanf("%d", &newNode -> data);
        if(newNode -> data == -1)
        {
            free(newNode);
            break;
        }
        newNode -> data = newNode -> data;
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            struct Node *temp = head;
            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp -> next = newNode;
        }   
        newNode -> next = NULL;
        newNode = (struct Node*)malloc (sizeof(struct Node));
    }
    while(1)
    {
        int choice;
        printf("Choose an insertion method:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at a specific index\n");
        printf("3. Insert at the end\n");
        printf("4. Insert after a specific node\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice == 5)
        {
            printf("Exiting program.\n");
            break;
        }
        int data, index;
        struct Node *prevnode;
        switch(choice)
        {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertatbeginning(head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter index to insert at: ");
                scanf("%d", &index);
                head = insertatindex(head, data, index);
                break;
            case 3:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertatend(head, data);
                break;
            case 4:
                printf("Enter data to insert after a specific node: ");
                scanf("%d", &data);
                printf("Enter the value of the previous node: ");
                int prevData;
                scanf("%d", &prevData);
                prevnode = head;
                while(prevnode != NULL && prevnode -> data != prevData)
                {
                    prevnode = prevnode -> next;
                }
                if(prevnode != NULL)
                {
                    head = insertafternode(head, prevnode, data);
                }
                else
                {
                    printf("Previous node not found.\n");
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("Current linked list:\n");
        linkedlist_traversal(head);
    }
    return 0; 
}