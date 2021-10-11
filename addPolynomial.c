#include<stdio.h>
#include<conio.h>

typedef struct singly_linked
{
int coefficient;
int exponent;
struct singly_linked *next;
}polynomial;
typedef polynomial *list_ptr;
list_ptr *A, *B;

void init(list_ptr L1, list_ptr L2);
list_ptr addPolynomial(list_ptr L1, list_ptr L2);

void main (void)
{
init(&L1,&L2);
addPolynomial(&L1,&L2);
}
void init(list_ptr *L1, list_ptr *L2)
{
int x,y;
list_ptr temp1st, temp2nd;
printf("enter the number of groups for the 1st polynomial");
scanf("%d",&x);
for(;x>0;x--)
  {
     temp1st = (list_ptr)malloc(sizeof(polynomial));
     scanf("%d",temp1st->coefficient);
     scanf("%d",temp1st->exponent);
     *L1 = temp1st;
      temp1st->next = *L1;
  }
printf("enter the number of groups for the 2nd polynomial");
scanf("%d",&y);
for(;y>0;y--)
  {
     temp2nd = (list_ptr)malloc(sizeof(polynomial));
     scanf("%d",temp2nd->coefficient);
     scanf("%d",temp2nd->exponent);
     *L2 = temp2nd;
      temp2nd->next = *L2;
  }
}

list_ptr addPolynomial(list_ptr L1, list_ptr L2)
{
list_ptr temp1,temp2,sum;
for(temp1 = *L1; temp1!=NULL; temp = temp->next)
 
{
  for(temp2 = *L2; temp!=NULL; temp = temp->next)
  {
   if (temp1->exponent == temp2->exponent)
    {
     sum = (list_ptr)malloc(sizeof(polynomial);
     sum->coefficient = temp1->coefficient + temp2->coefficient;
    }
   else
    







