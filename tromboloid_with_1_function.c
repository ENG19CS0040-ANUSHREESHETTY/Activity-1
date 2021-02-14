//Write a program to find the volume of a tromboloid using one function
#include<stdio.h>
int main()
{
float h,d,b,vol;
printf(“enter the values of h,b and d\n”);
scanf(“%f%f%f”,&h,&d,&b);
vol=((h*d*b)+(d/b))/3.0;
printf(“Volume of the tromboloid is=%f\n”,vol);
return(0);
}
