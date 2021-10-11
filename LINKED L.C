#include<stdio.h>

typedef struct cell
{
char elem;
struct cell* next;
}celltype, *List;

void init(List *A);
void Insert(List *A, char x);
void PrintList(List A, int i);

void main ()
{
List L;
int i, x;
char z;
clrscr();
init(&L);
printf("How many Elements?");
scanf("%d\n",&i);
for(x = 1;x < i;x++)
    {
     scanf("%c\n",&z);
     Insert(&L,z);
    }
PrintList(L,i);
getch();
}

void init(List *A)
{
(*A)=NULL;
}

void Insert(List *A, char x)
{
List *trav,temp;
temp = (List)malloc(sizeof(celltype));
temp->elem = x;
temp->next = NULL;
for(trav = A;(*trav)!=NULL;trav = &(*trav)->next);
(*trav) = temp;
}

void PrintList(List A, int i)
{
List trav;
int x = 1;
printf("The elements are:\n");
for(trav = A;x < i&& trav!=NULL;trav = trav->next,x++)
  printf("%c\n",trav->elem);
}