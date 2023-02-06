#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
  int top;
  char *arr;
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
  printf("Enter size of stack :");
  scanf("%d", &s->size);
  s->top = -1;
  // s->arr = (char *)malloc(s->size * sizeof(char));
  char str[50];
  printf("Enter String :");
  fflush(stdin);
  gets(str);
  int len = strlen(str);
  if (len > s->size)
  {
    printf("String Size Greater Than Stack Size Aborting!!!!!");
    exit(0);
  }

  printf("Before Reversing The String :");
  printf("%s", str);

  for (int i = 0; i < len; i++)
  {
    push(s, str[i]);
  }

  for (int i = 0; i < len; i++)
  {
    str[i] = pop(s);
  }

  printf("\nAfter Reversing The String : ");
  printf("%s", str);
}