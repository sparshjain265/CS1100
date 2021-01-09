#include<stdio.h>
#include<stdlib.h>

struct node{
  int val;
  struct node *next;
};

typedef struct node *nodeptr;

struct queue{ 
    nodeptr front;
    nodeptr rear;
    };

nodeptr createNode(int );
struct queue createQ(void);
int insertQ(struct queue *, int );
int deleteQ(struct queue *, int * );
void printQ(struct queue );
void removeQ(struct queue *);


void main()
{
  int op=-1, key, flag=-1;
  struct queue q;
  
  q=createQ();   
  while(op!=4)
  {
     printf("\n1:insert 2:delete 3:print from front 4:exit\n");
     scanf("%d", &op);
     if (op==1)
     { printf("enter value to be inserted\n");
       scanf("%d",&key);
       flag=insertQ(&q, key);
       if(flag==-1)
       {   printf("insert failed\n");
           return;
       }
     } 
     else if (op==2)
     { 
         flag=deleteQ(&q, &key);
         if(flag==-2)
         { 
            printf("delete failed\n");
            return;
         }
        else if (flag==-1)
           printf("Queue is empty\n");
        else 
           printf("%d is deleted \n",key);  
      
     }
     if (op==3)
     {
        printQ(q);
     }
  }

  removeQ(&q);
}


nodeptr createNode(int item)
/*allocate memory for a new node and initialize it*/
{

   nodeptr tempptr;
   tempptr=(nodeptr)malloc(sizeof(struct node));
   if(tempptr!=NULL)
   {
      tempptr->val=item;
      tempptr->next=NULL;
   }
   else
   {
      printf("Alloc failed\n");
   }  
   return tempptr;
}

struct queue createQ(void)
//intialize the front and rear of a queue
{
  struct queue q;
  
     q.front=NULL;
     q.rear=NULL;
 
  return q;
}  
  
int insertQ(struct queue * qptr, int item)
/*insert a value item to the queue with address qptr
return 0 if success and -1 otherwise.
 */
{
   nodeptr newPtr;
   
   newPtr=createNode(item);
   if(newPtr!=NULL)
   {
      if (qptr->front == NULL)
      {  
         qptr->front=newPtr;
         qptr->rear=newPtr;
      }
      else
      {
         qptr->rear->next=newPtr;
         qptr->rear=newPtr;
      }
      return 0;
   }
   return -1;
} 

int deleteQ(struct queue * qptr, int * pitem)
/*delete the front element from a queue with address qptr, the resultant value will be stored at address pitem
return -2 if there is a crtical error, -1 if the queue is empty and 0 otherwise
*/
{
   nodeptr secondPtr;
   if (qptr==NULL)   
      return -2;
   if (qptr->front==NULL)
   {   
       return -1;
   }
   secondPtr=qptr->front->next;
   *pitem = qptr->front->val;
   free(qptr->front);
   qptr->front=secondPtr;
   if(qptr->front == NULL)
        qptr->rear=NULL;
   return 0;
}

void printQ(struct queue q)
/*print elements of the queue q from front to rear*/
{
   nodeptr curPtr;
   curPtr=q.front;
   if(curPtr==NULL)
   {
       printf("Queue is empty");
       return;
   }
   printf("items in the queue \n");
   while(curPtr!=NULL)
   {
     printf("%d ", curPtr->val);
     curPtr=curPtr->next;
   }
   return;
}

void removeQ(struct queue *qptr)
/*free the memory hold by queue elements and reset the front and rear pointers of the queue with address qptr*/
{  
   nodeptr tempptr;
   if(qptr!=NULL)
   {
     while(qptr->front!=NULL)
     {
      tempptr=qptr->front;
      qptr->front=qptr->front->next;
      if(tempptr!=NULL)
        free(tempptr);
     }
     qptr->front=NULL;
     qptr->rear=NULL;
   }
   
   return;      
}



