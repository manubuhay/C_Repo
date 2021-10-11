void deleteElement(elementtype x, List *L)
{


position y;

clrscr();
for(y = 0; y < (*L).last && x! = (*L)->element[y]; y++);
if(x == L->element[y])
{
   while (y = (*L).last)
   {
       L->element[y] = L->element[y+1];
       y++;
   }
   L->last--;
}
else
       printf("Element not found.\n");

printf("End of function deleteElement.\n");
getch();
}