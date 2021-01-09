#include <stdio.h>
int main()
{
int a, d, n, t;
printf("Enter the first term of the Arithmetic Progresstion: ");
scanf("%d", &a);
printf("\nEnter the common difference of the Arithmetic Progression: ");
scanf("%d", &d);
printf("\nEnter the number of term you want to find the value of: ");
scanf("%d", &n);
t = a + (n-1)*d;
printf("\n%dth number of the Arithmetic Progression is %d.\n", n, t);
return 0;
}
