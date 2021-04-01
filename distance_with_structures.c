//WAP to find the distance between two points using structures and 4 functions.
#include<stdio.h>
#include<math.h>
struct point
{
    float x;
    float y;
};
typedef struct point Point;
Point input()
{
    Point p;
    printf("Enter coordinates of point 1: ");
    scanf("%f",&p.x);
    printf("Enter coordinates of point 2: ");
    scanf("%f",&p.y);
    return p;
}

float compute(Point p1, Point p2)
{
    float dist;
    dist = sqrt(pow((p2.x - p1.x),2) + pow((p2.y - p1.y),2));
    return dist;
}

void output(Point p1, Point p2, float d)
{
    printf("The distance between (%f,%f) and (%f,%f) is %f", p1.x,p1.y,p2.x,p2.y,d);
}

int main()
{
    float d;
    Point p1, p2;
    p1 = input();
    p2 = input();
    d = compute(p1,p2);
    output(p1,p2,d);
    return 0;
}
