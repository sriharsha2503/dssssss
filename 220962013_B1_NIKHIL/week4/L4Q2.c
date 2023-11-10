#include<stdio.h>
#include<stdlib.h>
typedef struct{
	char name[20];
	int rno;
	double cgpa;
}std;
void read(std *stds,int n)
{
	for (int i=0;i<n;i++)
	{
		printf("Name:\n");
		scanf("%s",(stds+i)->name);
		printf("Roll number:\n");
		scanf("%d",&(stds+i)->rno);
		printf("CGPA:\n");
		scanf("%lf",&(stds+i)->cgpa);
	}
}
void display(std *stds,int n)
{
	for (int i=0;i<n;i++)
	{
		printf("\nName: %s\n",(stds+i)->name);
		printf("Roll number:%d\n",(stds+i)->rno);
		printf("CGPA:%lf\n",(stds+i)->cgpa);
	}
}
void swap(std *a,std *b)
{
    std temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(std *a, int n)
{
    for (int j=0;j<n-1;j++)
        for (int i= 0;i<n-j-1;i++)
            if (a[i].rno>a[i+1].rno)
                swap(&a[i], &a[i+1]);
}

void main()
{
	int i,n;
	printf("Number of students:");
	scanf("%d",&n);
	std *student;
	student=(std*)malloc(n*sizeof(std *));
	read(student,n);
	sort(student,n);
	display(student,n);
}
