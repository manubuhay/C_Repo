#include <stdio.h>

int main(void)
{
    float numb1 = 0, numb2 = 0;       /* the two numbers to work on */
    int menu = 1;             /* add or substract or divide or multiply */
    float total = 0;           /* the result of the calculation */
    char calType;             /* what type of calculation */

    printf("Please enter in the first of the two numbers\n\t");
    scanf("%f", &numb1);                 /* READ first number */

    printf("\n\nPlease enter the second of the two numbers\n\t");
    scanf("%f", &numb2);                 /* READ second number */

    printf("\n\nWhat would you like to do?\n\n");    /* WRITE instructions */
    printf("\t1 = add\n");
    printf("\t2 = substract\n");
    printf("\t3 = multiply\n");
    printf("\t4 = divide\n");

    printf("\n\nPleas make your selection now:\n\t");
    scanf("%d",&menu);                   /* READ calculation type */

    switch (menu)                  /* select the type of calculation */
    {
    case 1: total = numb1 + numb2;
        calType = '+';             /* assign a char to symbolise calculation type */
        break;
    case 2: total = numb1 - numb2;
        calType = '-';
        break;
    case 3: total = numb1 * numb2;
        calType = '*';
        break;
    case 4: total = numb1 / numb2;
        calType = '/';
        break; 
    default: printf("Invalid option selected\n");
    }

    if (menu == 4 && numb2 == 0)            /* cannot divide by 0 */
        printf("\n\n\tYou cannot divide by 0\n\n");

              /* display result to 2 decimal places */
    printf("\n\n*************************");
    printf("\n\n\t%.3f %c %.3f = %.2f", numb1, calType, numb2, total);
    printf("\n\n*************************\n\n");

    return 0;
}