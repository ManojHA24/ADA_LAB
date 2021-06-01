#include<math.h>
#include<stdio.h>
#include<time.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;


        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d\t ", arr[i]);
    printf("\n");
}

int main()
{
    int n;
    clock_t start,end;
    double cpu_time_taken;
    srand(time(0));
    printf("enter no of elements\n");
    scanf("%d",&n);
    int arr[n] ;
    printf("chosen array is:");
     for (int i = 0; i < n; i++)
            {
               arr[i]=rand()%100;

               printf("%d\t",arr[i]);

            }
     printf("\n");
    start=clock();
    for (int c = 1; c <= 8000; c++) for (int d = 1; d <= 8000; d++) { }
    insertionSort(arr, n);
    end = clock();
    cpu_time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("sorted array is:");
    printArray(arr, n);
    printf("time spent: %f sec\n",cpu_time_taken);
    return 0;
}
