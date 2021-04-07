#include<stdio.h>
#include<stdlib.h>
void linear_search(int search_key, int array[100], int n);
void sort(int array[100], int n);
void binary_search(int search_key, int array[100], int n);

void main()
{
 int array[100],search_key,i,j,n,low,high,temp,choice,flag=0;
    void linear_search(int search_key,int array[100],int n);
    void binary_search(int search_key,int array[100],int n);

printf("ENTER THE SIZE OF THE ARRAY:");
scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        array[i]=rand()%100+1;
        printf("%d\n",array[i]);    
     }   
for(;;){     
printf("ENTER THE SEARCH KEY:");
scanf("%d",&search_key);

printf("1.LINEAR SEARCH\n2.BINARY SEARCH\n3.Exit\n");

printf("ENTER YOUR CHOICE:");
scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        linear_search(search_key,array,n);
        break;
    case 2:
        sort(array,n);
        printf("sorted array is: \n");
       for(i=0;i<n;i++){
		   printf("%d \t", array[i]);
	   }
       binary_search(search_key,array,n);
        break;
    default:
        exit(0);
    }

       }
}

void linear_search(int search_key,int array[100],int n)
    {
       int i,temp,flag=0;
        for(i=0;i<n;i++)
        {
            if(search_key == array[i])
                flag=1;
                temp = i;
      
        }   
	
	if(flag==0){
		printf("Elements not found");
		
	}else{
		printf("The location of Search Key = %d is at index:%d\n",search_key,temp);
		   	  
}
}
void sort(int array[100],int n)
{    int temp=0,i,j;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if(array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}			
     
            
void binary_search(int search_key,int array[100],int n)
{  
   int low,mid,high;
    low = 0;
    high = n-1;
    mid = (low + high)/2;
    

    while(1)
    {   
     		
        if(search_key < array[mid])
        {
            high = mid;
            mid = (low+high)/2;
        }
        else if(search_key > array[mid])
        {
            low = mid;
            mid = mid + (low+high)/2;
        }
		else
			break;
		if(high == low)
			return;
    }
    printf("location=%d\t",mid);
    printf("Search_Key=%d Found!\n",search_key);

 }
