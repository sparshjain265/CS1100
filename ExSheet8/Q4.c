#include <stdio.h>

int main()
{
	int i;
	float num = 0, k = 0.5;
	char n[21];
	
	printf("Enter the binary: ");
	scanf(" %20s", n);
	
	for(i = 0; n[i] != '\0'; i++)
	{
		if(n[i] != '.')
			num = num*2 + (n[i] - 48);
		else 
			break;	
	}
	for(i = i + 1; n[i] != '\0'; i++)
	{
		num = num + (n[i] - 48)*k;
		k = k/2;
	}
	
	printf("%f\n", num);
	
	return 0;
}
