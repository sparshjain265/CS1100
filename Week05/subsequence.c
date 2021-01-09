#include <stdio.h>


int main()
{
    int a[100], n, i = 0, b[100], c[100], j = 0, k = 0, *max, l;

    printf("Enter n: ");
    scanf(" %d", &n);
    i = 0;
    while(i<n)
    {
        printf("\nEnter element no. %d: ", i+1);
        scanf(" %d", &a[i]);
        i++;
    }

    i = 1;
    j = 1;
    b[0] = a[0];
    while(i<n)
    {
        if(a[i]>a[i-1])
        {
            b[j] = a[i];
            j++;
        }
        else if(j>=k)
        {
            k = 0;
            while(k<j)
            {
                c[k] = b[k];
                k++;
            }
            b[0] = a[i];
            j = 1;
        }
        else
        {
            b[0] = a[i];
            j = 1;
        }
        i++;
    }

    if(j>=k)
    {
        max = b;
        l = j;
    }

    else
    {
        max = c;
        l = k;
    }
    
    printf("\nLargest Strictly Ascending subsequence is: \n");

    i = 0;
    while(i<l)
    {
        printf("%d\n", max[i]);
        i++;
    }

    return 0;
}
