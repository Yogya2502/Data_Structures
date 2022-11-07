#include <stdio.h>
#include <stdlib.h>

// user defined datatype.
struct Node {
	int data;
	struct Node* new;
};

void insert(struct Node** head, int val)// this function has been created to add a node in the linked list
{
	struct Node* node
		= (struct Node*)malloc(sizeof(struct Node));// using malloc we allocate dynamic memory to this node
	if (node == NULL) {
		printf("Memory overflow\n");
	}
	else {
		node->data = val;
		node->new = NULL;
		if (*head == NULL) {
			*head = node;
		}
		else {
			struct Node* temp = *head;
			while (temp->new != NULL) {
				temp = temp->new;
			}
			temp->new = node; // linking a new node at the end of the list
		}
	}
}

void display(struct Node* head) //we create this function to display the required elements of the linked list
{
	if (head == NULL) {
		printf("Empty linked list");
		return;
	}
	struct Node* temp = head;
	printf("\n Linked List :");
	while (temp != NULL) {
		printf(" %d", temp->data);
		temp = temp->new;
	}
}

struct Node* ln(struct Node* head)//reaching out to the last node of the linked list
{
	struct Node* temp = head;
	while (temp != NULL && temp->new != NULL) {
		temp = temp->new;
	}
	return temp;
}

struct Node* parition(struct Node* F, struct Node* L)// using the first and last element
{
	// Get first node of given linked list
	struct Node* pivot = F;
	struct Node* front = F;
	int temp = 0;
	while (front != NULL && front != L) {
		if (front->data < L->data) {
			pivot = F;

			// Swapping node values
			temp = F->data;
			F->data = front->data;
			front->data = temp;
			F = F->new;
		}
		front = front->new;
	}
	// Change last node value to current node
	temp = F->data;
	F->data = L->data;
	L->data = temp;
	return pivot;
}

void sort(struct Node* first, struct Node* last)// function for quick sort on a linked list
{
   int F,L;// first and last element

	if (F == L) {
		return;
	}
	struct Node* pivot = parition(F, L);

	if (pivot != NULL && pivot->new != NULL) {
		sort(pivot->new, L);
	}

	if (pivot != NULL && F != pivot) {
		sort(F, pivot);
	}
}
int main()
{
	struct Node* head = NULL;

	insert(&head, 100);
	insert(&head, 90);
	insert(&head, 80);
	insert(&head, 70);
	insert(&head, 60);
	insert(&head, 50);
	insert(&head, 40);
	insert(&head, 30);
	insert(&head, 20);
	insert(&head, 10);
	//calling the insert funtion and preparing the required linked list
	printf("\n After Sort ");
	display(head);

	
}
