#include<stdio.h>
#include<stdlib.h>
int smallest(int *arr,int n)
{
	int min=*arr;
	for(int i=1;i<n;i++)
	{
		if (*(arr+i)<min)
			min=*(arr+i);
	}
	return min;
}
void main()
{
	int *a,n,i;
	printf("Size of array:");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	printf("Enter element:");
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	int s=smallest(a,n);
	printf("Smallest element:%d\n",s);
}