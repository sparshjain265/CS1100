#include <stdio.h>
int main()
{
int a, d, n, t, s;
printf("Enter the first term of the Arithmetic Progresstion: ");
scanf("%d", &a);
printf("\nEnter the common difference of the Arithmetic Progression: ");
scanf("%d", &d);
printf("\nEnter the number of term you want to find the value of: ");
scanf("%d", &n);
t = a + (n-1)*d;
s = n*(a + t)/2;
printf("\n%dth number of the Arithmetic Progression is %d and the sum of the first %d terms is %d.\n", n, t, n, s);
return 0;
}
