#include<stdio.h>
#include<stdlib.h>
#define emptyTos -1

typedef int elementtype;

typedef struct{
unsigned int stack_size;
elementtype *element;
int top;
}stack, *stack_ptr;

void create(unsigned int,stack_ptr *);
void printlist(stack_ptr);
void push(elementtype,stack_ptr *);
void pop(stack_ptr *);

void main(void)
{
 stack_ptr L;
 create(10,&L);
 printlist(L);
 push(1,&L);
 push(100,&L);
 push(82,&L);
 push(500,&L);
 printlist(L);
 pop(&L);
 printlist(L);

}
void create(unsigned int x,stack_ptr *L)
{
 *L =(stack_ptr)malloc(sizeof(stack));
 (*L)->stack_size = x;
 (*L)->element = (elementtype *)malloc(sizeof(elementtype)*x);
 (*L)->top = emptyTos;
}
void printlist(stack_ptr L)
{

 if(L->top > -1)
 {
 int x = 0;
 for(;x<=L->top;x++){
  printf("L[%d]: ",x);
  printf("%d\n",L->element[x]);
 }}
 else printf("No Value!\n");
 printf("\n");
}
void push(elementtype x,stack_ptr *L)
{
if((*L)->top != (*L)->stack_size-1)
{
 (*L)->element[++(*L)->top] = x;
 }
 else printf("L[%d] is not available\n\n",(*L)->top+1);
}
void pop(stack_ptr *L)
{

  printf("delete! index[%d]\n",(*L)->top--);
}