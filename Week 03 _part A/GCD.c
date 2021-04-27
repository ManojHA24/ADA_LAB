#include <stdio.h>
#include <stdlib.h>
int a ,b ,choice;
int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b%a, a);
}
int hcf(int a, int b)
{
    while (a != b) {
        if (a > b)       
            a = a - b;       
        else       
            b = b - a;       
    }
    return a;
}    
int main()
{
	
for(;;){
	printf("1:iterative\n2:recursive\n3:exit\n");
	printf("Enter choice:\n");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
		  printf("Enter 2 numbers\n");
	      scanf("%d %d",&a,&b);
	      printf("GCD is :%d\n", hcf(a, b));       
         break;
        case 2:
            printf("Enter 2 numbers\n");
	        scanf("%d %d",&a,&b);
           printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b)); 
          break;
        default:
              exit(0);
   }
  } 
		
}
