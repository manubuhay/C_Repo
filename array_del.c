#include <stdio.h>
int MAX = 10; //Defines the array length

int delete();
void inputArray(int *a);
void outputArray(int *a);
void deleteArray(int *a, int del);

void main(void)
{
int a[MAX], del;
inputArray(a); //Input values into the array
del = delete(); //Asks for the index to delete
printf("The current list is:\n");
outputArray(a); //Outputs the contents of the array
printf("You wanted to remove the value in index number %d\n", del);
printf("Deleting.....\n");
deleteArray(a,del); //Deletes the value and shift the cells up
MAX = MAX--; //Decrement MAX variable after deletion
printf("The new list is:\n");
outputArray(a); //Outputs the updated contents of the array
}

	int delete()
	{
	int i;
	printf("Which index do you want to delete?\n");
	scanf("%d", &i);
	return i;
	}

	void inputArray(int *a)
	{
		int i;
		printf("Input number:\n");
		for(i=0; i<MAX; i++)
			scanf("%d", &a[i]);
	}

	void outputArray(int *a)
	{
		int x;
		for(x=0; x<MAX; x++)
			printf("%d\n", a[x]);
	}

	void deleteArray(int *a, int del)
	{
		int y;
		for(y=del-1; y<MAX; y++)
		 	a[y] = a[y+1];
	}