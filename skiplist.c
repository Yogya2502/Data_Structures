#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Skip_List
{
    int data;
    struct Skip_List *next;
    struct Skip_List *down;
};

typedef struct Skip_List * nodeAddress;

nodeAddress Generate_Linked_List(int size){
    nodeAddress head = NULL;
    nodeAddress temp = NULL;
    nodeAddress current = NULL;
    
    int i;
    
    for (i = 0; i < size; i++)
    {
        temp = (nodeAddress)malloc(sizeof(struct Skip_List));
        temp->data = rand() % 100;
        temp->next = NULL;
        temp->down = NULL;
        if (head == NULL)
        {
            head = temp;
            current = temp;
        }
        else
        {
            current->next = temp;
            current = temp;
        }
    }
    return head;
}


void Print_Linked_list(nodeAddress head){
    nodeAddress current = head;
    printf("Linked List = ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

// We will set a skip list with random jumps
void Set_Skip_List(nodeAddress head){
    // We have a linked list, we will set a skip list with random jumps by setting the down pointer of the node
    nodeAddress current = head;
    nodeAddress temp = NULL;
    int i;
    while (current != NULL)
    {
        i = rand() % 10;
        temp = current;
        while (i > 0 && temp != NULL)
        {
            temp = temp->next;
            i--;
        }
        current->down = temp;
        current = current->next;
    }    
}

void Print_Linked_List(nodeAddress head){
    nodeAddress current = head;
    printf("\nSkip List = ");
    while (current != NULL && current->down != NULL)
    {
        printf("%d ", current->data);
        current = current->down;
    }
}

void Free_Linked_list(nodeAddress head){
    nodeAddress current = head;
    nodeAddress temp = NULL;
    // first we free the down pointer
    while (current != NULL && current->down != NULL)
    {
        temp = current->down;
        free(temp);
        current = current->next;
    }
    // then we free the next pointer
    while (current != NULL && current->next != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
}

int main(int argc, char const *argv[])
{
    int size;
    printf("Enter the size of the Linked List: ");
    scanf("%d", &size);
    srand(time(NULL));
    nodeAddress head = Generate_Linked_List(size);
    Print_Linked_list(head);
    Set_Skip_List(head);
    Print_Linked_List(head);
    Free_Linked_list(head);
    return 0;
}

//reference : https://www.geeksforgeeks.org/skip-list-set-2-insertion/

