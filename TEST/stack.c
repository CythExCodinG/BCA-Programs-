#include <stdio.h>
#define MAX 20
struct stack
{
  int data[MAX];
  int top;
};
void init(struct stack *s)
{
  s->top = -1;
}
int isEmpty(struct stack *s)
{
  if (s->top == -1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
int isFull(struct stack *s)
{
  if (s->top == MAX - 1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
void push(struct stack *s, int x)
{
  s->data[++s->top] = x;
}
int pop(struct stack *s)
{
  return (s->data[s->top--]);
}
void display(struct stack *s)
{
  int i;
  if (s->top == -1)
  {
    printf("stack is empty\n");
  }
  for (i = s->top; i >= 0; i--)
  {
    printf("\n%d", s->data[i]);
  }
}
void main()
{
  struct stack s1;
  int ch, x;
  init(&s1);
  while (1)
  {
    printf("\nstack operations:\n");
    printf("\n1.push\n2.pop\n3.chec if stack is empty\n4.to check if stack is full\n");
    printf("enter your choice:");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      if (isFull(&s1))
      {
        printf("stack overflow");
      }
      else
      {
        printf("enter value to insert:");
        scanf("%d", &x);
        push(&s1, x);
        printf("stack elements:");
        display(&s1);
      }
      break;
    case 2:
      if (isEmpty(&s1))
      {
        printf("stack is empty\n");
      }
      else
      {
        printf("popped element is %d\n", pop(&s1));
        printf("\nstack elements:\n");
        display(&s1);
      }
      break;
    default:
      printf("invalid choice\n");
      break;
    case 3:
      if (isEmpty(&s1))
      {
        printf("stack is empty\n");
      }
      else
      {
        printf("elements are present,stack is not empty\n");
      }
      break;
    case 4:
      if (isFull(&s1))
      {
        printf("stack is full\n");
      }
      else
      {
        printf("stack is not full\n");
      }
      break;
    }
  }
}