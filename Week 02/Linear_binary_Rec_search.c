#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t start1, start2, end1, end2;
double cpu_time_used1, cpu_time_used2;

int recLinearSearch(int arr[], int l, int r, int x)
{
    if (r < l)
        return -1;
    if (arr[l] == x)
        return l;
    if (arr[r] == x)
        return r;
    return recLinearSearch(arr, l + 1, r - 1, x);
}

int recBinarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;


        if (arr[mid] == x)
            return mid;


        if (arr[mid] > x)
            return recBinarySearch(arr, l, mid - 1, x);


        return recBinarySearch(arr, mid + 1, r, x);
    }


    return -1;
}

int main()
{

    int result, k,choice, n, x,j,a,i,c,d;
    srand(time(0));
    while (1)
    {
        printf("1:linear search\n2:binary search\n3:exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter no of elements:\n");
            scanf("%d", &n);
            int arr[n];

            for (int k = 1; k <= n; k++)
            {
               arr[k]=rand()%100;
               printf("%d\t",arr[k]);
            }
            printf("\nenter element to be found\n");
            scanf("%d", &x);
            start1 = clock();
            result = recLinearSearch(arr, 0, n-1, x);
            for (c = 1; c <= 5000; c++) for (d = 1; d <= 5000; d++) { }
            end1 = clock();
            cpu_time_used1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
            (result == -1) ? printf("Element is not present in array\n") :
            printf("Element is present at index %d\n", result);
            printf("time taken: %f\n",cpu_time_used1);
        }

        else if (choice == 2)
        {
            printf("Enter no of elements:");
            scanf("%d", &n);
            int arr[n];
            for (int k =1; k<=n; k++)
            {
               arr[k]=rand()%100;
            }
           for (i=1; i <=n;i++)
        {
            for (j = i + 1; j <= n; ++j)
            {
                if (arr[i] >arr[j])
                {
                    a =arr[i];
                    arr[i] = arr[j];
                    arr[j] = a;
                }

            }

        }
         for (int k =1; k <=n; k++)
            {
               printf("%d\t",arr[k]);
            }
            printf("\nenter element to be found\n");
            scanf("%d", &x);
            start2 = clock();
            result = recBinarySearch(arr, 0, n - 1, x);
            for (c = 1; c <= 5000; c++) for (d = 1; d <=5000; d++) { }
            end2 = clock();
            cpu_time_used2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
            (result == -1) ? printf("Element is not present in array\n") : printf("Element is present at index %d\n", result);
            printf("time taken: %f\n", cpu_time_used2);
        }
        else
            break;
    }
    return 0;
}
