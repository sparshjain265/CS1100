#include <stdio.h>


int main()
{
    int n, m, r;
    long bin = 0, i = 1;

    printf("Enter a positive number: ");
    scanf(" %d", &n);
    
    m = n;

    if(n < 0)
    {
        printf("\nWrong Input!");
        return 0;
    }

    while(n != 0)
    {
        r = n%2;
        n = n/2;
        bin = bin + r*i;
        i = i*10;
    }

    printf("\nBinary of %d is %ld", m, bin);
    
    printf("\n");

    return 0;
}
