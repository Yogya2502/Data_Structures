#include <stdio.h>
int main() {
    int n;
    printf("Enter the count of elements to be sorted:\n");
    scanf("%d",&n);

   int arr[n];
   printf("Enter the elements to be sorted:\n");
   for(int i=0; i<n; i++){
    scanf("%d",&arr[i]);
   }
   
   int i, j, pos, swap;
   for (i = 0; i < (n - 1); i++) {
      pos = i;
      for (j = i + 1; j < n; j++) {
         if (arr[pos] > arr[j])
            pos = j;
      }
      if (pos != i) {
         swap = arr[i];
         arr[i] = arr[pos];
         arr[pos] = swap;
      }
   }
   for (i = 0; i < n; i++)
      printf("%d\t", arr[i]);
   return 0;
}

// reference from https://www.geeksforgeeks.org/selection-sort/