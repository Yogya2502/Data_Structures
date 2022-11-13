#include<stdio.h>
#include<stdlib.h>
 // user defined datatype
struct Node
{ int data;
    struct Node* next;
};
 
struct Node *reverse (struct Node *head, int k)
{
    if (!head)
        return NULL;
   
    struct Node* current = head;
    struct Node* next = NULL;
    struct Node* prev = NULL;
    int count = 0;
   
    while (current != NULL && count < k)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if (next !=  NULL)
       head->next = reverse(next, k);
 
    return prev;
}
 
void push(struct Node** ref, int new_data)
{

    struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));
 
    new_node->data  = new_data;
 
    new_node->next = (*ref);   
    (*ref)    = new_node;
}
 
void printlist(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}   
int main(void)
{
    struct Node* head = NULL;
  
     push(&head, 100);
     push(&head, 90);
     push(&head, 80);
     push(&head, 70);
     push(&head, 60);
     push(&head, 50);
     push(&head, 40);
     push(&head, 30);
     push(&head, 20);          
 
     printf("\n Inputted linked list  \n");
     printlist(head);
     head = reverse(head, 3);
 
     printf("\n Reversed Linked list \n");
     printlist(head);
 
     return(0);
}