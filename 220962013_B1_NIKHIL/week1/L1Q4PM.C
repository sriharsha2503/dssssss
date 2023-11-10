#include<stdio.h>
void readm(int a[10][10],int rows, int cols)
{
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			scanf("%d",&a[i][j]);
		}
	}
}
void displaym(int a[10][10],int rows, int cols)
{
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			printf("%d \n",a[i][j]);
		}
	}
}

void prodm(int a[10][10],int b[10][10],int rows1, int cols1,int rows2, int cols2)
{
	int c[10][10];
	if (cols1!=rows2)
		printf("Multiplication not possible");
	for(int i=0;i<rows1;i++){
		for(int j=0;j<cols2;j++){
			c[i][j]=0;
			for (int k=0;k<cols2;k++){
				c[i][j]+=a[i][k]*b[k][j];
				printf("%d",c[i][j]);
			}
		}
	}
}
int main()
{
	int rows1,cols1,rows2,cols2,a[10][10],b[10][10];
	printf("Enter rows1:");
	scanf("%d",&rows1);
	printf("Enter cols1:");
	scanf("%d",&cols1);
	printf("Enter rows2:");
	scanf("%d",&rows2);
	printf("Enter cols2:");
	scanf("%d",&cols2);
	readm(a,rows1,cols1);
	displaym(a,rows1,cols1);
	readm(b,rows2,cols2);
	displaym(b,rows2,cols2);
	prodm(a,b,rows1,cols1,rows2,cols2);
}