#include<stdio.h>
#include<stdlib.h>  
#include<time.h>

clock_t start1,end1;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
void selectionSort(int arr[], int n)
{
  int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
  
        swap(&arr[min_idx], &arr[i]);
    }
}


void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d \t", arr[i]);
    printf("\n");
}

void kth_largest_element(int arr[], int n, int k)
{
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
  for(int i=0;i<n;i++){
	  if(i==k+1)
	  {
         printf("k-th largest element :%d",arr[i]);
         break;	 
      } 
  }
}

int main()
{
    int arr[100], n, i,k;
    srand(time(0));	
    printf("Enter the size of array\n");
    scanf("%d",&n);
 
    for(i=0; i<n; i++){
		arr[i]=rand()%100;
		printf("%d\t",arr[i]);
	}
	printf("\n");
   
  
    printf("Enter the k value\n");
    scanf("%d",&k);
    kth_largest_element(arr,n,k);
    return 0;
}
