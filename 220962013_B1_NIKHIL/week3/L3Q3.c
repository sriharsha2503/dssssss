#include<stdio.h>
#include<stdlib.h>
void exchange(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
	return;
}
int *small(int *x,int*y)
{
	return(*x<*y?x:y);
}
void main()
{
	int a,b;
	printf("Enter 2 numbers:");
	scanf("%d%d",&a,&b);
	printf("Value of a:%d\n",a);
	printf("Value of b:%d\n",b);
	exchange(&a,&b);
	printf("After exchange,\nValue of a:%d\n",a);
	printf("Value of b:%d\n",b);
	int *f;
	f=small(&a,&b);
	printf("Smallest of a and b:%d\n",*f);
	int x,*p,**q;
	p=&x;
	q=&p;
	printf("Enter number:");
	scanf("%d",&x);
	printf("Value of x:%d\n",x);
	printf("Enter number:");
	scanf("%d",p);
	printf("Value of p:%d\n",*p);
	printf("Enter number:");
	scanf("%d",*q);
	printf("Value of q:%d\n",**q);
	printf("Value of x:%d\n",x);
}
