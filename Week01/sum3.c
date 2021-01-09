#include <stdio.h>
int sum(int a);
int main()
{
unsigned int a, s;

printf("Enter a number: ");
scanf("%d", &a);

s = sum(a);

printf("\nSum of the numbers from 1 to %d is %d\n", a, s);
return 0;
}

int sum(int a)
{
if(a == 1)
return a;
else return (a + sum(a-1));
}
