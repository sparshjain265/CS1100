#include <stdio.h>


int main()
{
  int a[5];
  int i;

  i = 0;
  while (i < 5)
  {
    printf("%p: %d \t %p: %d\n", (a+i), *(a+i), &a[i], a[i]);
    i = i + 1;
  }

  printf("Enter 4 numbers\n");

  i = 0;
  while (i < 4)
  {
    scanf(" %d", &a[i]);
    i = i + 1;
  }
  /* The 5th element in the array will be garbage */

  i = 0;
  while (i < 5)
  {
    printf("%p: %d \t %p: %d\n", (a+i), *(a+i), &a[i], a[i]);
    i = i + 1;
  }


    return 0;
}

// int = 4 bytes, char = 1 byte, float = 4 bytes, double = 8 bytes
