#include <stdio.h>

int MAX = 10;

void outputArray(int *a);
void arrayInput(int *a);
int addIndex();
void addArray(int *a,int index,int val);

void main(void)
{
int a[MAX],index,val;
arrayInput(a);
printf("Current list is:\n");
outputArray(a);
index=addIndex();
printf("Input value to be added:\n");
scanf("%d\n", &val);
addArray(a,index,val);
printf("New list is:\n");
outputArray(a);
}

	void arrayInput(int *a)
	{
		int j;
		printf("Input numbers:\n");
		for(j=0; j<MAX; j++)
			scanf("%d\n", &a[j]);
	}

	void outputArray(int *a)
	{
		int x;
		for(x=0; x<MAX; x++)
			printf("%d\n", a[x]);
	}

	int addIndex()
	{
		int index;
		printf("Where do you want to add the value?\n");
		scanf("%d\n", &index);
		return index;
	}

	void addArray(int *a, int index, int val)
	{
		int x;
		for(x=MAX-1; x>index-1; x--)
			a[x+1]=a[x];
		MAX = MAX++;
		a[x] = val;
	}