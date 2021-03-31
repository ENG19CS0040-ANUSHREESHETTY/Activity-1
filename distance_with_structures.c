//WAP to find the distance between two points using structures and 4 functions.
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct point 
{
   float x,y;
};
double getdistance(struct point a,struct point b)
{
   double distance;
   distance=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
   return distance;
 }
int main()
{
  struct point a,b;
  printf(“Enter the coordinates of the point a:\n”);
  scanf(“%f%f”,&a.x,&a.y);
  printf(“Enter the coordinates of the point b:\n”);
  scanf(“%f%f”,&b.x,&b.y);
  printf(“Distance between a and b:%f”,getdistance(a,b));
  return 0;
}
