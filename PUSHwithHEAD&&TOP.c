/*** GOOD! with head and top ***/


#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef int elementtype;
typedef struct node
{
	elementtype element;
	struct node *next;
}celltype;

typedef struct
{
	celltype *Head, *Top;
}STACK;

void PUSH(elementtype x, STACK *A);
void initialize(STACK *A);
void printlist(STACK A);

void main(void)
{
	STACK A;
	elementtype x, y, i;

	initialize(&A);
	printf("Number of inputs: ");
		scanf("%d",&y);
	for(i=0; i<y; i++)
	{
		printf("\n");
		printf("Integer to insert: ");
			scanf("%d", &x);
		PUSH(x,&A);
	}
	printf("\n");
	printf("LIST: ");
	printlist(A);
}
void initialize(STACK *A)
{
	A->Head = NULL;
	A->Top = NULL;
}
void PUSH(elementtype x, STACK *A)
{
	celltype *temp;

	temp = (celltype*)malloc(sizeof(celltype));
	temp->element = x;
	temp->next = NULL;
	if(A->Head == NULL)
		A->Head = temp;
	else
		A->Top->next = temp;
	A->Top = temp;
}
void printlist(STACK A)
{
	celltype *temp;

	for(temp = A.Head; temp != NULL; temp = temp->next)
		printf(" %d",temp->element);
}