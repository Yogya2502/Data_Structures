#include <stdio.h>

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
void printArray(int* arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void bubbleSort(int* arr, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

int main()
{
    int n;
    printf("Enter the count of elements to be sorted:\n");
    scanf("%d",&n);
	int arr[n];
    printf("Enter the elements to be sorted:\n");
    for( int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
	bubbleSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}



// reference from https://www.geeksforgeeks.org/bubble-sort/
