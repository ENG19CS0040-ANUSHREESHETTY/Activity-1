#include<stdio.h>
struct unit_fraction
{
  int num;
  int den;
};
typedef struct unit_fraction unit;
struct Egyptian_fraction
{
  int m;
  int den[100];
  unit sum;
};
typedef struct Egyptian_fraction Egyptian;
int GCD (int a, int b);
int
input ()
{
  int n;
  printf ("Enter the number of fractions\n");
  scanf ("%d", &n);
  return n;
}

void input_1 (Egyptian * one)
{

  printf ("Enter the number of fractions required to be summed\n");
  scanf ("%d", &one->m);
  for (int i = 0; i < one->m; i++)
    scanf ("%d", &one->den[i]);
}

void input_n (Egyptian a[], int n)
{
  for (int i = 0; i < n; i++)
    input_1 (&a[i]);
}

int GCD (int a, int b)
{
  a = a < b ? a : b;
  if (b % a == 0)
    return a;
  for (int i = a / 2; i >= 2; i--)
    {
      if (a % i == 0 && b % i == 0)
	return i;
    }
  return 1;
}

void compute_1 (Egyptian * one)
{
  unit res;
  res.num = 0;
  res.den = 1;
  int g;
  for (int i = 0; i < one->m; i++)
    {
      one->sum.num = (res.num * one->den[i]) + res.den;
      one->sum.den = res.den * one->den[i];
      g = GCD (one->sum.num, one->sum.den);
      one->sum.num = one->sum.num / g;
      one->sum.den = one->sum.den / g;
      res = one->sum;
    }
}

void compute_n (Egyptian a[], int n)
{
  for (int i = 0; i < n; i++)
    compute_1 (&a[i]);
}

void output_1 (Egyptian * one)
{
  for (int i = 0; i < (one->m) - 1; i++)
    printf ("1/%d + ", one->den[i]);
  printf ("1/%d =%d/%d\n", one->den[(one->m) - 1], one->sum.num,
	  one->sum.den);
}

void output_n (Egyptian a[], int n)
{
  for (int i = 0; i < n; i++)
    output_1 (&a[i]);
}

int main ()
{
  int n;
  Egyptian a[100];
  n = input ();
  input_n (a, n);
  compute_n (a, n);
  output_n (a, n);
  return 0;
}

