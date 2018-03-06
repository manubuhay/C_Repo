#include <stdio.h>

void main (void){
int a[10], i, j;
printf("Input 10 numbers:\n");

for(i=0; i<=9; i++)
	{
	scanf("%d", &a[i]);
 	}
printf("Display in reverse!\n");

for(j=9; j>=0; j--)
	{
	printf("%d\n", a[j]);
 	}
}