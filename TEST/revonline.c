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
  return (ptr->arr[ptr->top--]);
}
int main()
{
  struct stack *s = malloc(sizeof(struct stack));
  printf("enter total no. of digit:");
  int n = 0;
  s->top = -1;
  scanf("%d", &n);
  s->size = n;
  int a = pow(10, n);
  int no[n];
  int data = 0;
  for (int i = 0; i < n; i++)
  {
    printf("enter %d digit\n", i + 1);
    scanf("%d\n", &no[i]);
  }
  printf("number before reversing:");
  for (int i = 0; i < n; i++)
  {
    printf("%d\t", no[i]);
  }
  for (int i = 0; i < n; i++)
  {
    push(s, no[i]);
  }
  printf("\n");
  int rev = 0;
  int z = n - 1;
  for (int i = 0; i < n; i++)
  {
    rev = rev + ((1 * (pow(10, z))) * pop(s));
    z--;
  }
  printf("\nnumber after reversing:");
  printf("%d\t", rev);
}