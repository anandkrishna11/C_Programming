#include <stdio.h>
#include <string.h>
int main()
{
int i;
char word1[50],word2[50],j,flag=0;
printf("Enter the first word:");
scanf("%s",word1);
printf("Enter the second word:");
scanf("%s",word2);
int result= strcmp(word1,word2);
{
if (result!=0)
{
printf("Not same");
}
else
{
printf("Same");
}
}
return 0;
}
