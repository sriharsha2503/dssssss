#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int day;
	int month;
	int year;
}date;
typedef struct{
	int hno;
	int zipcode;
	char state[30];
}address;
typedef struct{
	char name[30];
	date d;
	address addr;
}employee;
void read(employee *e,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Name:");
		scanf("%s",(e+i)->name);
		printf("Day born:");
		scanf("%d",&(e+i)->d.day);
		printf("Month born:");
		scanf("%d",&(e+i)->d.month);
		printf("Year born:");
		scanf("%d",&(e+i)->d.year);
		printf("House no:");
		scanf("%d",&(e+i)->addr.hno);
		printf("Zip code:");
		scanf("%d",&(e+i)->addr.zipcode);
		printf("State of address:");
		scanf("%s",(e+i)->addr.state);
	}
}
void display(employee *e,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("------------------------\n");
		printf("Employee %d:\n",i+1);
		printf("Name: %s\n",(e+i)->name);
		printf("Date of Birth: %d/%d/%d\n",(e+i)->d.day,(e+i)->d.month,(e+i)->d.year);
		printf("House no: %d\n",(e+i)->addr.hno);
		printf("Zip code: %d\n",(e+i)->addr.zipcode);
		printf("State of address: %s\n",(e+i)->addr.state);
	}
}
int main()
{
	int n;
	printf("Enter number of employees:");
	scanf("%d",&n);
	employee *emp;
	emp=(employee*)malloc(n*sizeof(employee *));
	read(emp,n);
	display(emp,n);
}