#include<stdio.h>
#include<math.h>

typedef struct coord
{
  float x;
  float y;

} coordinate;

typedef struct rect
{
  coordinate P1, P2, P3;
  float area, length, breadth;
} rectangle;


int input ()
{
  int n;
  printf ("Enter the number of test cases");
  scanf ("%d", &n);
  return n;
}

void input_one (rectangle * p)
{

  printf ("enter the coordinates");
  scanf ("%f %f %f %f %f %f  ", &p->P1.x, &p->P1.y, &p->P2.x, &p->P2.y,
	 &p->P3.x, &p->P3.y);
}

void input_n (int n, rectangle arr[])
{
  for (int i = 0; i < n; i++)
    {
      input_one (&arr[i]);
    }
}

void compute_one (rectangle * p)
{
  p->length =
    sqrt (pow ((p->P1.x - p->P2.x), 2) + pow ((p->P1.y - p->P2.y), 2));
  p->breadth =
    sqrt (pow ((p->P1.x - p->P3.x), 2) + pow ((p->P1.y - p->P3.y), 2));
  p->area = p->length * p->breadth;
}


void compute_n (int n, rectangle arr[])
{
  for (int i = 0; i < n; i++)
    {
      compute_one (&arr[i]);
    }
}

void output_one (rectangle * p)
{

  printf (" Area of rectangle with vertices (%f,%f),(%f,%f),(%f,%f) is %f \n",
	  p->P1.x, p->P1.y, p->P2.x, p->P2.y, p->P3.x, p->P3.y, p->area);
}

void output_n (int n, rectangle arr[])
{
  for (int i = 0; i < n; i++)
    {
      output_one (&arr[i]);
    }
}

int main ()
{
  int n = input ();
  rectangle arr[n];
  input_n (n, arr);
  compute_n (n, arr);
  output_n (n, arr);
  return 0;
}
