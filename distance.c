//WAP to find the distance between two point using 4 functions.
#include<stdio.h>
#include<math.h>
Struct Coordinate
{
  float x;
  float y;
}
typedef struct Coordinate point;
point read_coordinate()
{
point c;
printf(“Enter Coordinate x:”);
scanf(“%f”,&c.x);
printf(“Enter Coordinate y:”);
scanf(“%f”,&c.y);
return c;
}
float find_distance(point c1,point c2)
{
  float d;
  d=sqrt(c2.x-c1.x)*(c2.x-c1.x)+(c2.y-c1.y)*(c2.y-c1.y);
  return d;
}
void output(float dist)
{
printf(“Distance=%f”,dist);
}
int main()
{
  point c1,c2;
  float dist;
  c1=read_coordinate();
  c2=read_coordinate();
  dist=find_distance(c1,c2);
  output(dist);
  return 0;
}

