#include <stdio.h>
int main()
{
int x, sum = 0;
printf("Enter First Number: ");
scanf("%d", &x);
sum+=x;
printf("\nEnter Second Number: ");
scanf("%d", &x);
sum+=x;
printf("\nEnter Third Number: ");
scanf("%d", &x);
sum+=x;
printf("\nSum of the numbers you entered is %d \n", sum);
return 0;
}
