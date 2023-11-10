#include <stdio.h>

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

void display(stack *s)
{
	printf("Binary:");
	for (int i=s->tos; i>=0; i--) printf("%d", s->st[i]);
	printf("\n");
}
int main()
{
	stack s;
	s.tos = -1;
	int n;
	printf("Decimal: ");
	scanf("%d", &n);
	while (n!=0)
	{
		push(&s,n%2);
		n/=2;
	}
	display(&s);
	return 0;
}
