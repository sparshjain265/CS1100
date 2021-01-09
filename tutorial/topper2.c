#include<stdio.h>
#define SIZE 5

typedef struct 
{  int roll;
   unsigned int marks[2];
   unsigned int total;
   char name[15];
  
}student;

typedef student studList[SIZE];
typedef student * studPtr;

student inputStudentDetails();
void printStudentDetails(student);
void updateTotal(studPtr);
student getTopper(studList, int);

int main()
{

   studList l;
   student s; 
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


student inputStudentDetails()
{
      student s;

      scanf("%d", &s.roll);
      scanf("%14s", s.name);
      scanf("%d", &s.marks[0]);
      scanf("%d", &s.marks[1]);
      return s;
}  
  
void printStudentDetails(student s)
{
      
      printf("%7d\t", s.roll);
      printf("\t%s\t", s.name);      
      printf("%2d\t", s.marks[0]);
      printf("%2d\t", s.marks[1]);
      printf("%2d\n", s.total);
      
} 
void updateTotal(studPtr ps)
{ 
     ps->total=ps->marks[0]+ps->marks[1];
}

student getTopper(studList sl, int n)
{
   int maxpos=0, i;
   for(i=1; i<n; i++)
      if(sl[i].total > sl[maxpos].total)
          maxpos=i;
   return sl[maxpos];
}   
 

