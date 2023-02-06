#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
  int top;
  char *arr;
  int size;
};

int isEmpty(struct stack *ptr)
{
  if (ptr->top == -1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int isFull(struct stack *ptr)
{
  if (ptr->top == ptr->size - 1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int precedence(char sign)
{
  if (sign == '*' || sign == '/')
  {
    return 3;
  }
  else if (sign == '+' || sign == '-')
  {
    return 2;
  }
  else
  {
    return 0;
  }
}

int issign(char expr)
{
  if (expr == '+' || expr == '-' || expr == '*' || expr == '/')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
char push(struct stack *ptr, int data)
{
  ptr->top++;
  ptr->arr[ptr->top] = data;
}

char pop(struct stack *ptr)
{
  return ptr->arr[ptr->top--];
}

char *infixtopostfix(char *infix)
{
  struct stack *s = malloc(sizeof(struct stack));
  s->size = 15;
  s->top = -1;
  s->arr = (char *)malloc(s->size * sizeof(char));
  char *postfix = (char *)malloc(strlen(infix) + 1 * sizeof(char));
  int i = 0;
  int j = 0;
  while (infix[i] != '\0')
  {
    if (!issign(infix[i]))
    {
      postfix[j] = infix[i];
      i++;
      j++;
    }
    else
    {
      if (precedence(infix[i]) > precedence(s->arr[s->top]))
      {
        push(s, infix[i]);
        i++;
      }
      else
      {
        postfix[j] = pop(s);
        j++;
      }
    }
  }
  while (!isEmpty(s))
  {
    postfix[j] = pop(s);
    j++;
  }
  postfix[j] = '\0';
  return postfix;
}

int main()
{
  char infix[20];
  fflush(stdin);
  printf("Enter Your Expression :");
  fgets(infix, 20, stdin);
  printf("postfix is %s", infixtopostfix(infix));
  return 0;
}