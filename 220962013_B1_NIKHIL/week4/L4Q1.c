#include<stdio.h>

typedef struct{
	double real;
	double imag;
}complex;

complex add(complex c1,complex c2)
{
	complex c3;
	c3.real=c1.real+c2.real;
	c3.imag=c1.imag+c2.imag;
	return c3;
}
complex diff(complex c1,complex c2)
{
	complex c3;
	if (c1.real>c2.real){
		c3.real=c1.real-c2.real;
		c3.imag=c1.imag-c2.imag;
	}
	else
	{
		c3.real=c2.real-c1.real;
		c3.imag=c2.imag-c1.imag;
	}
	return c3;
}
complex mult(complex c1,complex c2)
{
	complex c3;
	c3.real=(c1.real*c2.real)-(c1.imag*c2.imag);
	c3.imag=(c1.imag*c2.real)+(c1.real*c2.imag);
	return c3;
}
void display(complex c3)
{
    printf("%.2f+%.2fi\n", c3.real, c3.imag);
}
void main()
{
	complex c1;
	complex c2;
	complex c3;
	printf("Enter real part 1:");
	scanf("%lf",&c1.real);
	printf("Enter imaginary part 1:");
	scanf("%lf",&c1.imag);
	printf("Enter real part 2:");
	scanf("%lf",&c2.real);
	printf("Enter imaginary part 2:");
	scanf("%lf",&c2.imag);
	printf("Addition:\n");
	display(add(c1,c2));
	printf("Subtraction:\n");
	display(diff(c1,c2));
	printf("Multiplication:\n");
	display(mult(c1,c2));
}