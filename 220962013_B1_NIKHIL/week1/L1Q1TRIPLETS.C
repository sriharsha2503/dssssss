#include<stdio.h>
void findTriplet(int n,int a[10])
{
	int i,j,k,flag;
	flag=0;
	for(i=0;i<n-3;i++)
		for(j=i;j<n-2;j++){
			for(k=j;k<n-1;k++){
				if (a[i]+a[j]+a[k]==0){
					printf("%d %d %d\n",a[i],a[j],a[k]);
					flag=1;
				}
			}
		}
	if (flag==0)
		printf("No triplets");
	
}
int main()
{
	int a[10],n;
	printf("No of elements:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	findTriplet(n,a);

}