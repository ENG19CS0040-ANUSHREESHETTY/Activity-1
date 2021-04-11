#include<stdio.h>
struct student
{
  char name[100];
  int scores[100];
  char grade;
  float result;
};
typedef struct student student;
struct Gradebook
{
  char course[100];
  int num_weights;
  float weights[100];
  int num_student;
  student students[100];
};
typedef struct Gradebook gradebook;
void
input_1 (gradebook * one)
{
  int i;
printf ("enter course name:");
  scanf ("%s", one->course);
printf ("enter no.of weights:");
  scanf ("%d", &one->num_weights);
printf ("enter no.of students:");
  scanf ("%d", &one->num_student);
printf ("enter the weights:");
  for (i = 0; i < one->num_weights; i++)
    scanf ("%f", &one->weights[i]);
  for (i = 0; i < one->num_student; i++)
    {
    printf ("enter student name:");
      scanf ("%s",one->students[i].name);
    printf ("enter scores:");
      for (int j = 0; j < one->num_weights; j++)
	{
	  scanf ("%d", &one->students[i].scores[j]);
	}
    }
}

void input_n (int n, gradebook gb[])
{
  for (int i = 0; i < n; i++)
    input_1 (&gb[i]);
}

char
scores_to_grade (float res)
{
  if (res >= 0 && res < 60)
    return 'F';
  else if (res >= 60 && res < 70)
    return 'D';
  else if (res >= 70 && res < 80)
    return 'C';
  else if (res >= 80 && res < 90)
    return 'B';
  else
    return 'A';
}

void compute_score_1 (gradebook * one)
{
  float w = 0;
  for (int i = 0; i < one->num_weights; i++)
    w += one->weights[i];
  int i;
  for (i = 0; i < one->num_student; i++)
    {
      one->students[i].result = 0.0;
      for (int j = 0; j < one->num_weights; j++)
	{
	  one->students[i].result +=
	    (one->students[i].scores[j] * one->weights[j]);
	}
      one->students[i].result = one->students[i].result / w;
      one->students[i].grade = scores_to_grade (one->students[i].result);
    }
}

void compute_score_n (int n, gradebook gb[])
{
  for (int i = 0; i < n; i++)
    compute_score_1 (&gb[i]);
}

void output_1 (gradebook * one)
{
  printf ("%s\n",one->course);
  for (int i = 0; i< one->num_student; i++)
    printf ("%s\t%f\t%c\n",one->students[i].name,one->students[i].result, one->students[i].grade);
}

void output_n (int n, gradebook gb[])
{
  for (int i = 0; i < n; i++)
    output_1 (&gb[i]);
}

void main ()
{
  int n;
printf ("enter no.of Gradebooks:");
  scanf ("%d", &n);
  gradebook gb[n];
  input_n (n, gb);
  compute_score_n (n, gb);
  output_n (n, gb);
}

