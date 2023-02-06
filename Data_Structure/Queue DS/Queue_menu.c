#include <stdio.h>
#include <stdlib.h>

struct queue
{
  int f;
  int b;
  int *arr;
  int size;
};

int isfull(struct queue *ptr)
{
  if (ptr->b == ptr->size - 1)
  {
    printf("Queue is Full");
    return 1;
  }
  else
  {
    printf("Queue is not full");
    return 0;
  }
}

int isempty(struct queue *ptr)
{
  if (ptr->b == ptr->f)
  {
    printf("Queue is Empty");
    return 1;
  }
  else
  {
    printf("Queue is not Empty");
    return 0;
  }
}

void display(struct queue *ptr)
{
  if (isempty(ptr))
  {
    // printf("Queue is Empty\n");
    return;
  }
  else
  {
    printf("\nQueue :\n");
    printf("FRONT==> ");
    for (int i = ptr->f + 1; i <= ptr->b; i++)
    {
      printf("%d ", ptr->arr[i]);
    }
    printf("<==REAR");
  }
}

int dequeue(struct queue *ptr)
{
  if (isempty(ptr))
  {
    // printf("Queue is Empty\n");s
    return 1;
  }
  else
  {
    ptr->f++;
    printf("\nElement Dequeued is:%d", ptr->arr[ptr->f]);
    int v = ptr->arr[ptr->f];
    // printf("Element Dequeued is:%d",ptr->arr[ptr->f]);
    printf("\nNOW QUEUE IS=>\n");
    display(ptr);
    return v;
  }
}

void enqueue(struct queue *ptr)
{
  if (isfull(ptr))
  {
    printf("Queue is full\n");
  }
  else
  {
    int data;
    printf("\nEnter Value To add to Queue :");
    scanf("%d", &data);
    ptr->b++;
    ptr->arr[ptr->b] = data;
  }
}
int main()
{
  struct queue *q;
  q = malloc(sizeof(struct queue));
  q->size = 100;
  q->f = -1;
  q->b = -1;
  q->arr = (int *)malloc(q->size * sizeof(int));

  int ch = 0;
  while (1)
  {
    printf("\n\n1:ENQUEUE\n2:DEQUEUE\n3:TO CHECK IF FULL\n4:TO CHECK IF EMPTY\n5:DISPLAY QUEUE\n6:!!!TO EXIT!!!\n");
    printf("Enter Your Choice :");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      enqueue(q);
      break;
    case 2:
      dequeue(q);
      break;
    case 3:
      isfull(q);
      break;
    case 4:
      isempty(q);
      break;
    case 5:
      display(q);
      break;
    case 6:
      exit(0);

    default:
      break;
    }
  }
  return 0;
}