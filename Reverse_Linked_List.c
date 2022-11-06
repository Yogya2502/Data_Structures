#include <stdio.h>
#include <stdlib.h>
 // nuser defined data type
struct Node {
    int data;
    struct Node* next;
};
 
static void reverse(struct Node** ref)
{
   // intialize three pointers prev as NULL , head as ref and next as NULL.
   struct Node* prev = NULL;
    struct Node* Head = *ref;
    struct Node* next = NULL;
    while (Head!= NULL) {
    // before changing the next of head, we store the next node 
         next = Head->next;
 
        // Reverse Head node's pointer
        Head->next = prev;
 
        // Move pointers one position ahead.
        prev = Head;
        Head = next;
    }
    *ref = prev;
}
 
void push(struct Node** ref, int new_data)// we have created this function to push the node.
{
    struct Node* n_n
        = (struct Node*)malloc(sizeof(struct Node));
    n_n->data = new_data;
    n_n->next = (*ref);
    (*ref) = new_node;
}
 

void printList(struct Node* head)// the following function will print out the prepared linked list
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
 // here the push function has been called in order to prepare the linked list.
    printf("Given linked list\n");
    printList(head);
    reverse(&head);
    printf("\nReversed linked list \n");
    printList(head);
    getchar();
}
