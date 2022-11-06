#include<stdio.h>

int main(){
   int i, count, num[25];
   printf("Enter the count of numbers to be sorted:\n ");
   scanf("%d",&count);
   printf("Enter the elements:\n ");
   for(i=0;i<count;i++)
   scanf("%d",&num[i]);
   quicksort(num,0,count-1);
   printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
   printf(" %d",num[i]);
   return 0;
}
// F stand for the first element, L stands for the last element and P is the pivotal element
void quicksort(int num[25],int F,int L){
   int i, j, P, temp;
   if(F<L){
      i=F;
      P=F;
      j=L;
      while(i<j){
         while(num[j]>num[P])
         j--;
         while(num[i]<=num[P]&&i<L)
         i++;
         if(i<j){
            temp=num[i];
            num[i]=num[j];
            num[j]=temp;
         }
      }
      temp=num[P];
      num[P]=num[j];
      num[j]=temp;
      quicksort(num,F,j-1);
      quicksort(num,j+1,L);
   }
}

// to add the list that is to be sorted, do not add commas. Add number with spaces in between.
// reference taken from https://www.geeksforgeeks.org/quick-sort/

