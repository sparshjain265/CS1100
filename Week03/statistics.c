#include <stdio.h>
#include <math.h>

int main()
	{
		int i = 0, n, score, max, min, fail = 0, sum = 0, sqsum = 0;
		float avg, std;
		printf("Enter the number of students: ");
		scanf("%d", &n);
		
		printf("\nEnter score of Student No. %d : ", i+1);
		scanf("%d", &score);
		
		max = score;
		min = score;
		sum = score;
		sqsum = score*score;
		
		if(score<40)
			fail = fail + 1;
			
		i = i + 1;
		
		while(i<n)
			{
				printf("\nEnter score of Student No. %d : ", i+1);
				scanf("%d", &score);
				
				if(score>max)
					max = score;
					
				if(score<min)
					min = score;
				
				sum = sum + score;
				
				sqsum = sqsum + score*score;
				
				if(score<40)
					fail = fail+1;
					
				i = i + 1;
			}
			
		avg = (float)sum/n;
		
		std = (float)sqsum/n - avg*avg;
		
		std = sqrt(std);
		
		printf("\nThe Highest Score is %d.\nThe Lowest Score is %d.\nThe Average Score is %f.\nThe Standard Deviation is %f.\nThe Number of Failures is %d.\n", max, min, avg, std, fail);
			
		return 0;
	}
