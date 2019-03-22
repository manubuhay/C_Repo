#include <stdio.h>
#include <string.h>

int main()
{
  int i, c, MAX = 50;//declare
  char S[MAX];

  printf("Enter string:\n");
  //scanf("%s",&S);//enter string
  gets(S);

  printf("How many times do you want to enter the said string?\n");
  scanf("%d",&i); //counter how many times you want to print string

  for (c = 0; c < i; c++)
    //printf("%s\n",S);//print string i number of times
    puts(S);
    printf("\n");
}
