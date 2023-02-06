#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct stack
{
  int top;
  int *arr;
  int size;
};

void push(struct stack *ptr, int data)
{
  ptr->top++;
  ptr->arr[ptr->top] = data;
}

int pop(struct stack *ptr)
{
  return ptr->arr[ptr->top--];
}

int main()
{
  struct stack *s = malloc(sizeof(struct stack));
  printf("Enter Total no of Digits :");
  int n = 0;
  s->top = -1;
  scanf("%d", &n);
  s->size = n;
  int no[n];
  int data = 0;

  for (int i = 0; i < n; i++)
  {
    printf("Enter %d digit\n", i + 1);
    scanf("%d", &no[i]);
  }
  printf("No Before Reversing is :");
  for (int i = 0; i < n; i++)
  {
    printf("%d", no[i]);
  }

  for (int i = 0; i < n; i++)
  {
    push(s, no[i]);
  }
  printf("\n");

  // int rev = 0;
  // int z = n - 1;
  // for (int i = 0; i < n; i++)
  // {
  //   rev = rev + ((1 * (pow(10, z))) * pop(s));
  //   z--;
  // }
  for (int i = 0; i < n; i++)
  {
    no[i] = pop(s);
  }

  printf("\n");
  printf("No After Reversing is :");
  // printf("%d", rev);
  for (int i = 0; i < n; i++)
  {
    printf("%d", no[i]);
  }
}