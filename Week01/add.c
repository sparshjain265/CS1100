#include <stdio.h>
int main()
{
int x, y, z;
printf("Enter first number: ");
scanf("%d", &x);
printf("\nEnter second number: ");
scanf("%d", &y);
z = x + y;
printf("\nSum of %d and %d is %d.\n", x, y, z);
return 0;
}
