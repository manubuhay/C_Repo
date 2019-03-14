#include <stdio.h>
int MAX = 50; //globally define array of 50 integers

int main(void) 
{
  int i,j,a[MAX],total,del;
  
  printf("How many numbers?\n"); //how many values you want to input
  scanf("%d",&total);

  if(total > 0 && total < 51 ) //total needs to be greater than 0 and less than 50
  {
    printf("Input %d numbers:\n",total);
    for(i = 0; i < total; i++) //input the numbers
      scanf("%d",&a[i]);

    printf("Input value to delete:\n"); //input which value you want to delete
    scanf("%d", &del);
    for(i = 0; i < total;) //loop to traverse array
    {
      if(a[i] == del) //compare values
      {
        for(j = i; j < total; j++)
          a[j] = a[j+1]; //shift cells up
        total--; //decrement total everytime the cells are shifted up
      }
      else
      i++;
    }

      printf("Values are:\n");
    for(i = 0; i < total; i++) //print the values in the array
      printf("%d\n",a[i]);
  }
  else
    printf("Number entered is not between 0 and 50."); //if total is less than 0 and greater than 49
  return 0; //return 0 and terminate program
}