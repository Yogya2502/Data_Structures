#include <stdio.h>
#include <stdlib.h>
 // nuser defined data type
struct Node {
    int data;
    struct Node* next;
};
 
static void reverse(struct Node** ref)
{
    struct Node* prev = NULL;
    struct Node* Head = *ref;
    struct Node* next = NULL;
    while (Head!= NULL) {
         next = Head->next;
 
        // Reverse Head node's pointer
        Head->next = prev;
 
        // Move pointers one position ahead.
        prev = Head;
        Head = next;
    }
    *ref = prev;
}
 
/* Function to push a node */
void push(struct Node** ref, int new_data)
{
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*ref);
    (*ref) = new_node;
}
 
/* Function to print linked list */
void printList(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
 

int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    push(&head, 30);
    push(&head, 50);
    push(&head, 70);
    push(&head, 100);
 
    printf("Given linked list\n");
    printList(head);
    reverse(&head);
    printf("\nReversed linked list \n");
    printList(head);
    getchar();
}