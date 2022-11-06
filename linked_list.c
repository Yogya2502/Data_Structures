#include <stdio.h>
#include <stdlib.h>
 // Node is a user defined data type therefore we use struct 
struct Node {
    int data;
    struct Node* next;
}
  
int main()
{
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;
  
    // allocate 4 nodes in the heap ( dynamic memory allocation)
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 5; 
    head->next = second;

    second->data = 10;
    second->next = third;
  
    third->data = 15; 
    third->next = fourth;
  
    fourth->data = 20;
    fourth->next = NULL;

    printlist(head);

    return 0;
}

int printlist(struct Node* n)
{
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
}