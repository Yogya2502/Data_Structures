#include<stdio.h>

int main(){
  int i, flag, num[60];
   printf("Enter the count of numbers to be sorted:\n ");
   scanf("%d",&flag);
   printf("Enter the elements:\n ");
   for(i=0;i<flag;i++)
   scanf("%d",&num[i]);
   sort(num,0,flag-1);
   printf("Order of Sorted elements: ");
   for(i=0;i<flag;i++)
   printf(" %d",num[i]);
   return 0;
}
// F stand for the first element, L stands for the last element and P is the pivotal element
void sort(int num[60],int F,int L){
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
      sort(num,F,j-1);
      sort(num,j+1,L);
   }
}

