#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int stack[20];
int top= -1;
void push(int x)
{
	stack[++top]=x;
}
int pop()
{
	return stack[top--];
}
int main()
{
	int n1,n2,n3,num,len;
	char exp[20];
	printf("Enter expression:");
	scanf("%s",exp);
	len=strlen(exp)-1;
	while(len>=0)
	{
		if (isdigit(exp[len]))
		{
			num=(exp[len])-48;
			push(num);
		}
		else
		{
			n1=pop();
			n2=pop();
			switch(exp[len])
			{
			case'+':
				n3=n1+n2;
				break;
			case'-':
				n3=n1-n2;
				break;
			case'*':
				n3=n1*n2;
				break;
			case'/':
				n3=n1/n2;
				break;
			}
			push(n3);
		}
		len--;
	}
	printf("Result :%d",pop());
	printf("\n");
	return 0; 
}
