#include<stdio.h>
#define SIZE 150

struct student 
{  int roll;
   unsigned int marks[2];
   unsigned int total;
   char name[15];
  
};



struct student inputStudentDetails();
void printStudentDetails(struct student);
void updateTotal(struct student *);
struct student getTopper(struct student [], int);
//struct student getTopper(struct student *, int);
int main()
{

   struct student l[SIZE];
   struct student s; 
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
   s=getTopper(l, n);
   printf("\nDetails of the topper \n");
   printf("\n Roll No.\tName\t\tMark1\tMark2\tTotal\n");
   printStudentDetails(s);
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


struct student getTopper(struct student sl[], int n)
/*Get the details of the student maximum total marks among students in list sl of size n*/
{
   int maxpos=0, i;
   for(i=1; i<n; i++)
      if(sl[i].total > sl[maxpos].total)
          maxpos=i;
   return sl[maxpos];
}   
 
/*
struct student getTopper(struct student sl[], int n)
{
   struct student s;
   int i;
   
   s=sl[0];
   for(i=1; i<n; i++)
   {   
      if(sl[i].total > s.total)
           s=sl[i];
   }
   return s;  
}
*/
