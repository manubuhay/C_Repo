#include <stdio.h>

int main ()
{

  int n;
  clrscr();
  printf("\nHow many numbers of the sequence would you like?\n");
  scanf("%d",&n);

  fibonacci(n);
  getch();
}

fibonacci(int n)
{
  int a = 0;
  int b = 1;
  int sum;
  int i;

  for (i=0;i<n;i++)
  {
    printf("%d\t",a);
    sum = a + b;
    a = b;
    b = sum;
  }
  return 0;
}

