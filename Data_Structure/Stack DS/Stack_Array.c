#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct stack
{
  int size;
  int top;
  int *arr;
};

int isempty(struct stack *ptr)
{
  if (ptr->top == -1)
  {
    printf("STACK IS EMPTY");
    return 1;
  }
  else
  {
    printf("STACK IS NOT EMPTY\n");
    return 0;
  }
}

int isfull(struct stack *ptr)
{
  if (ptr->top == ptr->size - 1)
  {
    printf("STACK IS FULL\n");

    return 1;
  }
  else
  {
    printf("STACK IS NOT FULL\n");

    return 0;
  }
}

void push(struct stack *ptr)
{
  if (isfull(ptr))
  {
  }
  else
  {
    int data;
    printf("Enter Data To Push =>");
    scanf("%d", &data);
    ptr->top++;
    ptr->arr[ptr->top] = data;
  }
}
int pop(struct stack *ptr)
{
  if (isempty(ptr))
  {
  }
  else
  {
    int val = ptr->arr[ptr->top];
    printf("Removed :%d", val);
    ptr->top--;
  }
}
void display(struct stack *ptr)
{
  int i;
  if (isempty(ptr))
  {
    printf("Stack is Empty\n");
  }
  else
  {
    printf("%d", ptr->arr[ptr->top]);
    printf("\t<==PEEK VALUE\n");
    int count = 0;
    printf("\n*************\n");
    printf("ELEMENTS\n");
    for (i = ptr->top; i >= 0; i--)
    {
      printf("%d\n", ptr->arr[i]);
      count++;
    }
    printf("\n*************\n");
    printf("\nSIZE OF STACK IS :%d\n\n", count);
  }
}

int main()
{
  struct stack *s = malloc(sizeof(struct stack));
  printf("\n ENTER SIZE OF STACK :");
  scanf("%d", &s->size);
  s->top = -1;
  s->arr = (int *)malloc(s->size * sizeof(int));
  int ch = 0;
  while (1)
  {
    printf("\n1:PUSH\n2:POP\n3:TO CHECK IF FULL\n4:TO CHECK IF EMPTY\n5:DISPLAY STACK\n6:!!!TO EXIT!!!\n");
    printf("Enter Your Choice :");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      push(s);
      break;
    case 2:
      pop(s);
      break;
    case 3:
      isfull(s);
      break;
    case 4:
      isempty(s);
      break;
    case 5:
      display(s);
      break;
    case 6:
      exit(0);

    default:
      break;
    }
  }
  return 0;
}
