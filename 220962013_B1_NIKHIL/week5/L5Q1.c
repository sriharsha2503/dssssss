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
	printf("Stack: ");
	for (int i=0; i <= s->tos; i++) printf("\n%c\n", s->st[i]);
}

int main()
{
	stack s;
	int ch;
	char p;
	s.tos = -1;
	printf("1.Push\n2.Pop\n3.Display\n4.EXIT\n");
	while (ch!=4)
	{
		printf("Enter choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
		case 1:
			printf("Character to push: ");
			scanf(" %c", &p);
			push(&s, p);
			break;
		case 2:
			pop(&s);
			break;
		case 3:
			display(&s);
			break;
		case 4:
			printf("Exiting...\n");
		}
	}
	return 0;
}