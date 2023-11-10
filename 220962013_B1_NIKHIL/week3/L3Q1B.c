#include <stdio.h>
void maxprofit(int *p, int n)
{
	int i, s=0;
	for (i=0; i<n; i++)
		if (*(p+i+1) < *(p+i))
		{
			if (s!=i)
				printf("(%d %d) ", s, i);
			s=i+1;
		}
	printf("\n");
}

int main()
{
	int a[50], t, n, i, j;

	printf("No of test cases: ");
	scanf("%d", &t);

	for(j = 0; j<t; j++)
	{
		printf("No of days: ");
		scanf("%d", &n);

		printf("Prices for %d days\n",n);
		for (i=0; i<n; i++)
			scanf("%d", &a[i]);

		maxprofit(a, n);
	}
	return 0;
}