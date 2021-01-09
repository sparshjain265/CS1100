#include <stdio.h>

int main()
{
  FILE *p;            /* p is a file pointer */
  char c;
  int success;
  
  p = fopen("print_me.c", "r");	
  /* Open the file test.c in read-only mode and assign its handle to p */
  if (p == 0)	/* Check if the file was opened correctly */
  {
   printf("Error in opening the file\n");
  return(1);
  }

  do
  {
    success = fscanf(p, "%c", &c);    /* Read next character from file */
    printf("%c", c);                  /* Print the character to screen */
  }
  while(success == 1);                /* Repeat till fscanf reads something successfully */

  fclose(p);                          /* Close the file */
  return(0);
}
