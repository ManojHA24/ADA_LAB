#include<stdio.h>
#include<stdlib.h>
#include<time.h>
clock_t start1,end1;
void merge_sort(int [ ],int,int);
void merge(int [ ], int, int, int);

int main()
     {
	int i,n,a[100];
	srand(time(0));	
	printf("Enter the size of array\n");
    scanf("%d",&n);
    start1=clock();
    for(i=0; i<n; i++){
		a[i]=rand()%100;
		printf("%d\t",a[i]);
	}
	printf("\n");
	merge_sort(a,0,n-1);
	for (int c = 1; c <= 8000; c++) for (int d = 1; d <= 8000; d++) { }
    end1=clock();
	printf("Sorted array\n");
	for(i=0;i<n;i++)
	{
	printf("%d\t",a[i]);
    }
    printf("\n");
    double cpu_time1 = (double) (end1-start1)/CLOCKS_PER_SEC;
    printf("Time taken: %f",cpu_time1);
	return 0;
}
void merge_sort(int a[],int low,int high)
{
int mid;
if(low<high)
	{
	   mid=(low+high)/2;
	   merge_sort(a,low,mid);
	   merge_sort(a,mid+1,high);
	   merge(a,low,mid,high);
	}
}

void merge(int a[], int low, int mid ,int high)
{
int i,j,k,c[100];
i=low;
k=low;
j=mid+1;
while(i<=mid && j<=high)
  {
    if (a[i]<a[j]){
        c[k++]=a[i++];
   }
   else{
       c[k++]=a[j++];
  }
}
    while(i<=mid){
         c[k++]=a[i++];
	 }
    while(j<=high){
        c[k++]=a[j++];
	}
for(i=low;i<=high;i++){
   a[i]=c[i];
   }
}
