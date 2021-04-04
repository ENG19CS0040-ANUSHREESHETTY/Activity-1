//WAP to find the sum of n fractions.
#include<stdio.h>
struct fraction
{
  int num;
  int den;
};
typedef struct fraction Fract;

void input (Fract array[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    {
      printf ("enter numerator: ");
      scanf ("%d", &array[i].num);
      printf ("enter denominator: ");
      scanf ("%d", &array[i].den);
    }
}

int gcd (int a, int b)
{
  int i, gcd = 1;
  for (i = 2; i <= a && i <= b; ++i)
    {
      if (a % i == 0 && b % i == 0)
	gcd = i;
    }
  return gcd;
}

Fract addfraction (Fract arr[], int n)
{
  Fract sum, f;
  int GCD;
  f.num = arr[0].num;
  f.den = arr[0].den;
  for (int i = 1; i < n; i++)
    {
      sum.den = f.den * arr[i].den;
      sum.num = (f.num * arr[i].den) + (arr[i].num * f.den);
      GCD = gcd (sum.num, sum.den);
      sum.den = (sum.den) / GCD;
      sum.num = (sum.num) / GCD;
      f = sum;
    }
  return sum;
}

void output (int n, Fract array[], Fract sum)
{
  for (int i = 0; i < n - 1; i++)
    {
      printf ("%d/%d+ ", array[i].num, array[i].den);
    }
  printf ("%d/%d = %d/%d", array[n - 1].num, array[n - 1].den, sum.num,
	  sum.den);
}

void main ()
{
  int n, i;
  printf ("Enter the number of Fractions to be entered:\n");
  scanf ("%d", &n);
  Fract array[n], sum;
  input (array, n);
  sum = addfraction (array, n);
  output (n, array, sum);

}
