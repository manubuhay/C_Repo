#include<string.h>

void main()
{
char str[50],rev[50];
int i,j;
clrscr();
printf("\nEnter a string:");
scanf("%s",&str);
for(i=strlen(str)-1,j=0;i>=0;i--,j++)
rev[j]=str[i];
rev[j]='\0';
if(strcmp(rev,str))
printf("\nThe string is not a palindrome");
else printf("\nThe string is a palindrome");
getch();
} 