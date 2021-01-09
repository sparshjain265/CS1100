#include <stdio.h>
int main()
{
unsigned int a, sum, i;
sum = 0;
printf("Enter a number: ");
scanf("%d", &a);

for(i = 1; i <= a; i++)
{
sum = sum + i;
}

printf("\nSum of the numbers from 1 to %d is %d\n", a, sum);
return 0;

}
