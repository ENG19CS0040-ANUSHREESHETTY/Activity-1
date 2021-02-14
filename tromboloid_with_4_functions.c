//WAP to find the volume of a tromboloid using 4 functions.#include<stdio.h>
float input()
{
    float a;
    printf(“enter a number\n”);
    scanf(“%f”,&a);
    return a;
}
float find_vol(float a,float b,float c)
{
     float vol;
     vol=⅓*((a*b*c)+(b/c));
     return vol;
}
void output(float a)
{
printf(“the result is %f”,a);
}
int main()
{
    float x,y,z,vol;
    x=input();
    y=input();
    z=input();
    vol=find_vol(x,y,z);
    output(vol);
    return(0);
}


