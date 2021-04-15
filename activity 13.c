#include<stdio.h>
#include<stdlib.h>
struct points
{
  float x;
  float y;
};
typedef struct points point;
struct rectangles
{
  point a[3];
float area;
};
typedef struct rectangles rectangle;

void input(rectangle*one)
{
for(int i=0;i<3;i++)
{
printf("enter the value of point1\n");
scanf("%f",&one->a[i].x);
printf("enter the value of point2\n");
scanf("%f",&one->a[i].y);
}
}
void input_n(rectangle a[],int n)
{
for(int i=0; i<n; i++)
input(&a[i]);
}
void compute(rectangle *one)
{
    float length=sqrt(pow((one->a[1].y-one->a[0].y),2)+pow((one->a[1].x-one->a[0].x),2));
    float breadth=sqrt(pow((one->a[0].y-one->a[2].y),2)+pow((one->a[0].x-one->a[2].x),2));
    one->area=length*breadth;
}
void compute_n(rectangle a[],int n)
{
    for(int i=0; i<n; i++)
        compute(&a[i]);
}
void output(rectangle *one)
{
    printf("Area of rectangle with vertices ");
    for(int i=0; i<3; i++)
        printf("(%.1f,%.1f) ",one->a[i].x,one->a[i].y);
    printf("is %.1f\n",one->area);
}

void output_n(rectangle a[],int n)
{
    for(int i=0; i<n; i++)
        output(&a[i]);
}

int main()
{
    int n;
    rectangle a[100];
    printf("Enter the number of rectangles to be analyzed:");
    scanf("%d",&n);
    input_n(a,n);
    compute_n(a,n);
    output_n(a,n);
    return 0;
}
