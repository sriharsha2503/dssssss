#include<stdio.h>
int Lsearch(int a[10],int n,int K)
{ 
	int i;
	for(i=0;i<n;i++){
		if(a[i]==K)
			printf("Element %d is at %d",K,i+1);
	}
	return i;
}
int main()
{
	int i,a[10],n,fin;
	printf("No of elements:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Element to search:");
	scanf("%d",&fin);
	Lsearch(a,n,fin);
	return 0;

}