#include<stdio.h>
#include<conio.h>
void warshalls();
int a[10][10], p[10][10], i,j,k,n,count=0;

void main()
{
    printf("Enter number of vertices\n");
    scanf("%d",&n);
    printf("Enter adjacency matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    warshalls();
    printf("\nPath Matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d ",p[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=n;i++)
    {
        if(p[i][i]==1)
        {
            count++;
        }
    }
    if(count==0)
    {
        printf("\nGraph does not contain any cycle");
    }
    else
    {
        printf("\nGraph contains cycle with vertices:\n");
        for(i=1;i<=n;i++)
        {
            if(p[i][i]==1)
            {
               printf("%d ",i);
            }
        }
    }
    
    getch();
}
void warshalls()
{
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            p[i][j]=a[i][j];
        }
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if((p[i][j]!=1) && (p[i][k]==1 && p[k][j]==1))
                {
                    p[i][j]=1;
                }
            }
        }
    }
}
