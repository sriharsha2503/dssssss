#include<stdio.h>
int toh(int n,char rodA,char rodC,char rodB)
{
	static int count=1;
	if(n==1)
	{
		printf("\nMove disk 1 from rod %c to rod %c.\n",rodA,rodC);
		return count;
	}
	toh(n-1,rodA,rodB,rodC);
	printf("\nMove disk %d from rod %c to rod %c.\n",n,rodA,rodC);
	toh(n-1,rodB,rodC,rodA);
	count+=2;
}
void main()
{
	int n;
	printf("Enter number of disks:");
	scanf("%d",&n);
	printf("No of steps taken:%d\n",toh(n,'A','C','B'));
}