#include<stdio.h>
#include<stdlib.h>
int **create(int row,int col)
{
	int **mat=(int**)malloc(row*sizeof(int *));
	for(int i=0;i<row;i++)
	{
		mat[i]=(int*)malloc(row*sizeof(int));
	}
	return mat;
}
void read(int **a,int r, int c)
{
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			scanf("%d",&a[i][j]);
		}
	}
}
void display(int **a,int r, int c)
{
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			printf("%d \n",a[i][j]);
		}
	}
}

int **prod(int **a,int **b,int r1, int c1,int r2, int c2)
{
	if (c1!=r2)
		printf("Multiplication not possible");
	int **c=create(r1,c2);
	for(int i=0;i<r1;i++){
		for(int j=0;j<c2;j++){
			c[i][j]=0;
			for (int k=0;k<c2;k++){
				c[i][j]+=a[i][k]*b[k][j];
				printf("%d",c[i][j]);
			}
		}
	}
}
void freematrix(int **a,int r,int c)
{
	for (int i=0;i<r;i++)
		free(a[i]);
	free(a);
}
int main()
{
	int r1,c1,r2,c2;
	printf("Enter r1:");
	scanf("%d",&r1);
	printf("Enter c1:");
	scanf("%d",&c1);
	int **a = create(r1,c1);
	printf("Enter r2:");
	scanf("%d",&r2);
	printf("Enter c2:");
	scanf("%d",&c2);
	int **b = create(r2,c2);
	printf("Enter matrix 1 elements:\n");
	read(a,r1,c1);
	printf("Matrix 1:\n");
	display(a,r1,c1);
	printf("Enter matrix 2 elements:\n");
	read(b,r2,c2);
	printf("Matrix 2:\n");
	display(b,r2,c2);
	int **c=prod(a,b,r1,c1,r2,c2);
	if (c)
	{
		printf("Product Matrix:\n");
		display(c,r1,c2);
		free(c,r1,c2);
	}
	free(a,r1,c1);
	free(b,r2,c2);
	return 0;
}