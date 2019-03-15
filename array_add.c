#include <stdio.h>

int MAX = 10;

void outputArray(int *a);
void arrayInput(int *a);
int addIndex();
void addArray(int *a,int index,int val);

void main(void)
{
int a[MAX],index,val;
arrayInput(a); //Input values into the array
printf("Current list is:\n");
outputArray(a); //Output current values
index=addIndex(); //Ask for index to where value will be put into
printf("Input value to be added:\n");
scanf("%d", &val); //Inputs new value to be added into the array
addArray(a,index,val); //Takes the array and index, shift the array cells down to add the new value to the specified index
printf("New list is:\n");
outputArray(a); //Outputs the new list
}

	void arrayInput(int *a)
	{
		int j;
		printf("Input numbers:\n");
		for(j=0; j<MAX; j++)
			scanf("%d", &a[j]);
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
		scanf("%d", &index);
		return index;
	}

	void addArray(int *a, int index, int val)
	{
		int x;
		for(x=MAX; x>=index; x--)
			a[x]=a[x-1];
		a[x] = val;
		MAX = MAX+1;
	}

	/*
NOTE: Do not add new line flags "\n" to scanf parameters e.g. %d, %c etc.
	*/
