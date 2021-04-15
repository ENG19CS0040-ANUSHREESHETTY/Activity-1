#include<stdio.h>
#include<string.h>

struct timeCard
{
	char empname[100];
	float minutes;
};
typedef struct timeCard tc;

struct employee
{
	char empname1[100];
	float hrWage;
	float workHr;
	float grossPay;
};
typedef struct employee emp;

int input()
{
	int n;
	printf("Enter the no.\n");
	scanf("%d",&n);
	return n;
}

void input_1(emp *a)
{
	printf("Enter the employee name and hourly wage:\n");
	scanf("%s %f",a->empname1,&a->hrWage);
}

void input_n(emp a[],int n)
{
	for(int i=0;i<n;i++)
	{
		input_1(&a[i]);
	}
}

void input_m(tc t[],int m)
{
	for(int i=0;i<m;i++)
	{
	printf("Enter the employee name and worktime(min)\n");
		scanf("%s %f",t[i].empname,&t[i].minutes);
	}
}

float compute_hr(emp *a,tc t[],int m)
{
	float tmin=0;
	float thr=0;
	for(int i=0;i<m;i++)
	{
		if(strcmp(a->empname1,t[i].empname)==0)
		{
			tmin+= t[i].minutes;
		}
	}
	thr=tmin/60.0;
	return thr;
}

void  compute_1(emp *a,int m,tc t[])
{
	a->workHr= compute_hr(a,t,m);
	if(a->workHr>40)
	{
		a->grossPay=(a->hrWage*40)+(a->workHr-40)*(1.5*a->hrWage);
	}
	else
{
		a->grossPay=(a->workHr)*(a->hrWage);
	}
}

void compute_n(int n,emp a[],int m,tc t[])
{
	for(int i=0;i<n;i++)
	{ 
		compute_1(&a[i],m,t);
	}
}

void output_1(emp *a)
{
	if(a->workHr!=0)
	{
		printf(" %s: %.2f hours, $%.2f \n",a->empname1,a-> workHr,a->grossPay);
	}
}

void output_n(int n,emp a[])
{
	for(int i =0;i<n;i++)
	{
		output_1(&a[i]);
	}
}

int main()
{
	int n=input();
	emp a[n];
input_n(a, n);
int m=input();
tc t[m];
input_m(t,m);
compute_n(n,a,m,t);
output_n(n,a);
return 0;
}
