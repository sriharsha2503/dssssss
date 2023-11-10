#include<stdio.h>
int sm(int a[10][10], int rows,int cols)
{
	int size=0;
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if (a[i][j]!=0)
				size++;
		}
	}
	if(size<(rows*cols)/2)
		printf("It is sparse matrix.");
	else
		printf("Not a sparse matrix");
	return 0;
}
int main()
{
	int a[10][10],rows,cols;
	printf("No of rows:");
	scanf("%d",&rows);
	printf("No of cols:");
	scanf("%d",&cols);
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			scanf("%d",&a[i][j]);
		}
	}
	sm(a,rows,cols);
}