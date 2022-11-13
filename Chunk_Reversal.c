#include<stdio.h>
#include<stdlib.h>
 // user defined datatype
struct Node
{ int data;
    struct Node* next;
};
 // we divide the given linked list into sub lists of size n and link the pointer to the new head node
struct Node *Rev(struct Node *head, int n) 
{
    if (!head)
        return NULL;
   
    struct Node* curr = head;
    struct Node* next = NULL;
    struct Node* prev = NULL;
    int flag = 0;
 // we start by reversing the first sub list of group n.
   
    while (curr != NULL && flag < n)
    {
        next  = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        flag++;
    }
 //now the last node of the first sub list after reversal is a pointer to the (n+1)th node.
 // the entire list is reversed recursively starting from curr ans sub lists.
    if (next !=  NULL)
       head->next = Rev(next, n);
 
    return prev; // the list provided by the user will have prev as the head of the list.
}
 
void push(struct Node** ref, int new_data) // we have created this function in order to push a node 
{

    struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));
 
    new_node->data  = new_data;
 
    new_node->next = (*ref);   
    (*ref)    = new_node;
 /* in this function we allocated a node in the heap memory along with inserting the data in the node. 
 the last node of the old list has been now linked to this node and the head pointer has been moved to 
 the new node */
}
 
void printlist(struct Node *node) // we have created this function to print the prepared linked list.
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
 // now calling the push function with the help of which we will create the linked list. 
 
     printf("\n Inputted linked list  \n");
     printlist(head);
     head = Rev(head, 3);
 
     printf("\n Reversed Linked list \n");
     printlist(head);
 
     return(0);
}
