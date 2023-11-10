#include<stdio.h>
#include<string.h>
void copyst(char st1[],char st2[],int index)
{
	st2[index]=st1[index];
	if (st1[index]=='\0')
		return;
	return copyst(st1,st2,index+1);
}
void main()
{
	char s1[100],s2[100];
	int i=0;
	printf("Enter string 1:");
	scanf("%s",s1);
	copyst(s1,s2,i);
	printf("String 1:");
	puts(s1);
	printf("Copied string:");
	puts(s2);
}