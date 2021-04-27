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

int main()
{
    int arr[100], n, i;
    srand(time(0));	
    start1=clock();
    printf("Enter the size of array\n");
    scanf("%d",&n);
 
    for(i=0; i<n; i++){
		arr[i]=rand()%100;
		printf("%d\t",arr[i]);
	}
	printf("\n");
    selectionSort(arr, n);
    end1=clock();
    printf("Sorted array: \n");
    printArray(arr, n);
    double cpu_time1 = (double) (end1-start1)/CLOCKS_PER_SEC;
    printf("Time taken: %f",cpu_time1);
    return 0;
}
