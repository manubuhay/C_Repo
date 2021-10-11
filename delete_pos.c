#include<stdio.h>
#include<stdlib.h>

typedef struct cell
{
 int elem;
 struct cell * next;
}LIST , *LLIST;

void insertfirst(LLIST * L,int x)
{
LLIST temp;
temp = (LLIST)malloc(sizeof(LIST));
temp -> elem = x;

temp -> next = *L;
*L = temp;
}

void init(LLIST *L)
{
 *L = NULL;
}

void deletepos(LLIST *L, int pos)
{
LLIST *p,temp;
int ctr;
p=L;

	for(p = L, ctr = 1; *p != NULL && pos > ctr ; ctr++, p = &(*p)->next);

	if(*p!=NULL)
   {

	temp = *p;
	*p = temp -> next;
   free(temp);
	}
	else
	{
	printf("invalid pos \n\n");
	}
}

void display(LLIST L)
{
 LLIST  *p;
 
 p = &L;
 
  while(*p!=NULL)
	{
	  printf("%d\t",(*p)->elem);
	  p = &(*p)->next;
	}
 printf("\n");
}

void main(void)
{
 LLIST p;
 int x,y,o,i;
 init(&p);
 printf("How many would you like to be inserted? ");
 scanf("%d",&y);
 for(o=1;y>=o;o++)
 {
  printf("input [%d]: ",o);
  scanf("%d",&i);
  insertfirst(&p,i);
 }
 printf("\nthe numbers are: ");
 display(p);

 printf("\nInput position you want to delete: ");
 scanf("%d",&x);

 deletepos(&p,x);
 printf("\nthe new numbers are: ");
 display(p);
}