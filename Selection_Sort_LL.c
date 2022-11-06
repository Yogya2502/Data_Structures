#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// user defined datatype.
struct Node{
    int new;
    struct Node * next;
};
typedef struct Node * NodeAddress; // a new datatype has been created 

void selection(NodeAddress head)// we have created the function for selection sort which keeps on swaping the elements till the highest value reaches the end of the linked list and the lowest value element at the head 
{
    NodeAddress temp, top, prev, curr;     // declaring the pointers
    temp = head;                                   
    while(temp->next != NULL){                    
        top = temp;                              
        prev = temp;                                
        curr = temp->next;                       
        // We Move the Value to End of the List    
        while(curr != NULL){
            if(curr->new < top->new){           
                top = curr;                        
            }
            curr = curr->next;                     
        }

        // We Swap the Value with the End of the List
        int swap_temp = temp->new;
        temp->new = top->new;
        top->new = swap_temp;
        
        // update temp to next node and the smallest value is at the head node
        temp = temp->next;                          
    }
}

// we have created this function to generate a new node in the linked list
NodeAddress generate(int n){
    int i;
    NodeAddress head = NULL;
    NodeAddress temp = NULL;
    
    if(n>0){
        head = malloc(sizeof(struct Node));
        head->new = rand()%1000;            
        head->next = NULL;                  
        temp = head;
    }
   
    for(i=1; i<n; i++){
        temp->next = malloc(sizeof(struct Node));
        temp = temp->next;
        temp->new = rand()%1000;           
        temp->next = NULL;                 
    }
    return head;                             
}
// this function prints the prepared linked list
void print(NodeAddress head, int k){
    NodeAddress temp = head;
    printf("Linked List = ");
    for(int i=0; i<k; i++){
        printf(i?", %d":"%d", temp->new);
        temp = temp->next;
    }
    printf(".\n");
}
// this function deletes required nodes from the linked list
void delete(NodeAddress head){
    NodeAddress prev;
	while(head){                // while head is not NULL. When the head is NULL it will be the last node
		prev = head;
		head = head->next;
		free(prev); 
	}
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the count of elements in the Linked List: ");
    scanf("%d", &n);
    NodeAddress list;         
    srand(time(NULL));               
    list = generate(n);    
    print(list, n);          
    selection(list);              
    print(list, n);           
    delete(list);                         
    return 0;
}
