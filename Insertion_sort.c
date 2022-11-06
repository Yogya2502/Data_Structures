
#include <math.h>
#include <stdio.h>
void Sort(int* arr, int n)
{
	int i, k, j;
	for (i = 1; i < n; i++) {
		k = arr[i];
		j = i - 1;

		
		while (j >= 0 && arr[j] > k) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = k;
	}
}
void printarr(int* arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
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
	Sort(arr, n);
	printarr(arr, n);

	return 0;
}
