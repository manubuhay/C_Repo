#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10
#define size 100

typedef char elementtype[size];

typedef struct{
 elementtype data[max];
 int num, front, rear;
}cQueue,*cQueue_ptr;

void create(cQueue_ptr *);
void Enqueue(cQueue_ptr , elementtype);
void printlist(cQueue_ptr);
void Dequeue(cQueue_ptr);

void main(void)
{
 cQueue_ptr A;
 elementtype x = "University",y = "of",z="San Carlos";

 create(&A);
 Enqueue(A,x);
 Enqueue(A,y);
 Enqueue(A,z);
 printlist(A);
 Dequeue(A);
 printf("\n");
 printlist(A);
}
void create(cQueue_ptr *A)
{
 *A = (cQueue_ptr)malloc(sizeof(cQueue));
 (*A)->front=1;
 (*A)->num = 0;
 (*A)->rear = 0;
}
void Enqueue(cQueue_ptr A, elementtype x)
{
 if(A->num != max)
 {
  A->rear=(A->rear+1)%max;
  fflush(stdin);
  strcpy(A->data[A->rear],x);
  A->num++;
 }
}
void printlist(cQueue_ptr A)
{
 int x,i=A->front;
 for(x = 0;x<A->num;x++)
 {
  puts(A->data[i]);
  i = (i+1)%max;
 }
}
void Dequeue(cQueue_ptr A)
{
 A->front = (A->front+1)%max;
 A->num--;

}
