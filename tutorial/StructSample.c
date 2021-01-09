#include<stdio.h>
#define SIZE 10

struct student 
{  int roll;
   unsigned int marks[2];
   unsigned int total;
   char name[15];
  
};



struct student inputStudentDetails();
void printStudentDetails(struct student);
void updateTotal(struct student *);
void swap(struct student *, struct student *);



int main()
{

   struct student l[SIZE];
   int i, n;
   
   printf("enter number of students (<%d) \n", SIZE);
   scanf("%d",&n);
   if(n > SIZE)
   { 
      printf("error \n");
      return 0;
   }
   
   for(i=0; i<n; i++)
   {    
      printf("\nGive roll number, name, mark1, mark2 of student %d\n", i+1);
      l[i]=inputStudentDetails();
      printf("\n");
      updateTotal(&l[i]);     
   }
   swap(&l[0], &l[n-1]);
   printf("\nupdated list is \n");
   for(i=0; i<n; i++)
   { 
     printStudentDetails(l[i]);
   }
}


struct student inputStudentDetails()
/*Input details of one student and return it */
{
      struct student s;

      scanf("%d", &s.roll);
      scanf("%14s", s.name);
      scanf("%d", &s.marks[0]);
      scanf("%d", &s.marks[1]);
      return s;
}  
  
void printStudentDetails(struct student s)
/*Print details of student s */
{
      
      printf("%7d\t", s.roll);
      printf("\t%s\t", s.name);      
      printf("%2d\t", s.marks[0]);
      printf("%2d\t", s.marks[1]);
      printf("%2d\n", s.total);
      
} 

void updateTotal(struct student *ps)
/*Update the total marks of one student whose address is the parameter */
{ 
     (*ps).total=(*ps).marks[0]+(*ps).marks[1];
}

void swap(struct student *s1, struct student *s2)
{
   struct student temp;
   temp=*s1;
   *s1=*s2;
   *s2=temp;
   
} 

 

