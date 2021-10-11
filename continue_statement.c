#include < stdio.h >                         //Include stdio.h file
void main()                                  //start of the program
{
int I=1, num, sum=0;                         // declare and initialize the variables
for (I = 0; I < 5; I++)                      // for loop
{
printf("Enter the integer");                 //Message to the user
scanf("%I", &num);                            //read and store the number
if(num < 0)                                   //check whether the number is less than zero
{
printf("You have entered a negative number"); // message to the user
continue;                                     // starts with the beginning of the loop
}                                             // end of for loop
sum+=num;                                     // add and store sum to num
}
printf("The sum of positive numbers entered = %d",sum); // print thte sum.
}                                             // end of the program.
