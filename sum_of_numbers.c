//Write a program to find the sum of n different numbers using 4 functions
#include<stdio.h>
int input()
{
  int a;
  printf("Enter a number: \n");
  scanf("%d", &a);
  return a;
}
void input_array(int n, int a[n])
{
  for(int i=0;i<n;i++)
{
  printf("Enter the element number %d of the array: \n", i);
  scanf("%d", &a[i]);
}
}
int nsum(int n, int a[n])
{
  int sum=0;
  for(int i=0;i<n;i++)
{
  sum += a[i];
}
return sum;
}
int result(int n, int a[n], int sum)
{
  int i;
  printf("The sum of %d different numbers is ", n);
  printf("%d", sum);
}
int main()
{
  int n,sum;
  n=input();
  int a[n];
  input_array(n,a);
  sum = nsum(n,a);
  result(n,a,sum);
}

