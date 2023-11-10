#include <stdio.h>
void rev(int *ptr,int n)
{
	int i,temp;
	for(i=0;i<n/2;i++)
	{
		temp=*(ptr+i);
		*(ptr+i)=*(ptr+n-i-1);
		*(ptr+n-i-1)=temp;
	}
}
void main()
{
	int arr[100], n, i;
	printf("No of elements: ");
	scanf("%d", &n);
	printf("Enter elements:\n");
	for (i=0; i<n; i++)
		scanf("%d",&arr[i]);
	rev(arr, n);
	printf("Reversed array\n");
	for (i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
