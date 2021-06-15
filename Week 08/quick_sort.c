#include<stdio.h>
#include<stdlib.h>
#include<time.h>
clock_t start1,end1;
int a[10],n;

void q_sort(int [ ],int,int);
int partition(int [ ], int, int);

int main()
{
    int i;
    srand(time(0));	
	printf("Enter the size of array\n");
    scanf("%d",&n);
    start1=clock();
    for(i=0; i<n; i++){
		a[i]=rand()%100;
		printf("%d\t",a[i]);
	}
	printf("\n");
    q_sort(a, 0, n-1);
    for (int c = 1; c <= 8000; c++) for (int d = 1; d <= 8000; d++) { }
    end1=clock();
    printf("Sorted array\n");
    for(i=0;i<n;i++){
         printf("%d\t",a[i]);
	 }
	 printf("\n");
    double cpu_time1 = (double) (end1-start1)/CLOCKS_PER_SEC;
    printf("Time taken: %f",cpu_time1);
  return 0;
}

void q_sort(int a[ ], int low, int high)
{
    int mid;
    if(low<high)
     {
       mid=partition(a,low,high);
       q_sort(a,low,mid-1);
       q_sort(a,mid+1,high);
     }
}

int partition(int a[ ], int low, int high)
{
  int i, j, temp, pivot;
  pivot=a[low];
  i=low+1;
  j=high;
 while(i<=j)
 {
     while(a[i]<=pivot)
         i++;
     while(a[j]>pivot)
        j--;
      if(i<j)
     {
       temp=a[i];
       a[i]=a[j];
       a[j]=temp;
     }
 }
  temp=a[low];
  a[low]=a[j];
  a[j]=temp;
  return j;
}
