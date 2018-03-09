#include <stdio.h>

int MAX=10;

void inputArray(int *x);
void outputArray(int *x);
void sortArray(int *x);

void main(void)
{
int x[MAX];
inputArray(x); //Input values
printf("Current list:\n");
outputArray(x); //Print current values
sortArray(x); //Sort the values
printf("Sorted list:\n");
outputArray(x); //Print sorted values
}

	void inputArray(int *x)
	{
		int a;
		printf("Enter values:\n");
		for(a=0; a<MAX; a++)
			scanf("%d", &x[a]);
	}

	void outputArray(int *x)
	{
		int i;
		for(i=0; i<MAX; i++)
			printf("%d\n", x[i]);
	}

	void sortArray(int *x)
	{
		int i, j, temp;
		for(i=MAX-1;i>=0;i--) //Loop within a loop for value comparison per run		
			for(j=i-1;j>=0;j--)			
				if(x[i] < x[j])
				{
					temp = x[i]; //Swap operation
					x[i] = x[j];
					x[j] = temp;
				}	
	}