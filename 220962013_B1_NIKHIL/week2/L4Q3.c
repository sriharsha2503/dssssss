#include<stdio.h>
#include<string.h>
void checkPalin(char st1[])
{
	static int i=0;
	int len=strlen(st1)-(i+1);
	if (st1[i]==st1[len])
	{
		if (i==len)
		{
			printf("It is a palindrome.");
			return;
		}
		i++;
		checkPalin(st1);
	}
	else
		printf("Not palindrome.");
}
void main()
{
	char s1[100];
	printf("Enter string 1:");
	scanf("%s",s1);
	checkPalin(s1);
}