#include <stdio.h>
#include<string.h>
#include<stdbool.h>
typedef struct
{
	char st[50];
	int tos;
}stack;

int isEmpty(stack *s)
{
	if(s->tos == -1)
		return 1;
	return 0;
}

int isFull(stack *s)
{
	int max= 50;
	if(s->tos==max)
		return 1;
	return 0;
}

void push(stack *s, char e)
{
	if (isFull(s)) {printf("Stack overflow\n"); return;}
	s->tos++;
	s->st[s->tos]=e;
}

char pop(stack *s)
{
	if (isEmpty(s)) {printf("Stack underflow\n"); return '\0';}
	return(s->st[s->tos--]);
}
int palin(stack *s)
{
	int flag=0;
	for (int i=s->tos; i>=0; i--){
		if ((s->st[i])==(s->st[i]-1))
			flag=1;
	}
	if (flag==1)
		return true;
}

int main()
{
	stack stk;
	stk.tos = -1;
	char e;

	int n;
	printf("strlen: ");
	scanf("%d", &n);

	printf("String: ");
	for (int i=0; i<=n; i++)
	{
		scanf("%c", &e);
		push(&stk, e);
	}

	if(palin(&stk))
		printf("Palindrome.");
	else
		printf("not Palindrome.");

	return 0;
}