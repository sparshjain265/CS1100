#include <stdio.h>


int main()
{

  int a[5] ={1, 1, 2, 3, 5};
  int *p, *q;

  p = &a[0];
  q = &a[4];

  while (p <= q)
  {
     printf("%d\n", *q);
     q = q - 1;
  }


    return 0;
}
