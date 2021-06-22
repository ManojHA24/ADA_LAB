#include<stdio.h>

void floyds();
int min(int,int);
int c[10][10], d[10][10], i,j,k,n;
void main()
{
printf("Enter number of vertices\n");
scanf("%d",&n);
printf("enter cost adjacency matrix\n");
for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
   {
    scanf("%d",&c[i][j]);
  }
}
floyds();
printf("Distance Matrix\n");
for(i=1;i<=n;i++)
   {
    for(j=1;j<=n;j++)
    {
      printf("%d\t",d[i][j]);
     }
     printf("\n");
     }
getch();
}
     
void floyds()
{
for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {
    d[i][j]=c[i][j];
   }
}
    for(k=1;k<=n;k++)
    {
      for(i=1;i<=n;i++)
       {
         for(j=1;j<=n;j++)
           {
               if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
         }
      }
   }
}

 
