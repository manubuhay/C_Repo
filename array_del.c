#include <stdio.h>

void main(void)
{

int a[20], i,del;
printf("Input number:\n");
for(i=0; i<10; i++)
	{
		scanf("%d", &a[i]);
	}
del = delete();
printf("The current list is:\n");
for(i = 0; i<10; i++)
	{
		printf("%d\n", a[i]);
	}
printf("You wanted to remove the value in index number %d\n", del);
// printf("%d", a[0+1]);
for(i = del - 1; i < 10; i++)
 	{
 	a[i] = a[i+1];
 	}
printf("The new list is:\n");
 for(i = 0; i<10; i++)
	{
		printf("%d\n", a[i]);
	}
}

int delete()
{
int i;
printf("Which index do you want to delete?\n");
scanf("%d", &i);
return i;
} 