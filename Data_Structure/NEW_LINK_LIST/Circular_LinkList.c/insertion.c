#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *insert_AtPos(struct node *tail)
{
  struct node *ptr = malloc(sizeof(struct node));
  printf("\nEnter no to be inserted at Position :");
  scanf("%d", &ptr->data);
  int i = 1;
  int index = 0;
  printf("Enter Position");
  scanf("%d", &index);
  struct node *pos = tail->next;
  while (i != index - 1)
  {
    pos = pos->next;
    i++;
  }
  ptr->next = pos->next;
  pos->next = ptr;
  return tail;
}

struct node *insert_start(struct node *tail)
{
  struct node *ptr = malloc(sizeof(struct node));
  printf("\nEnter no to be inserted at first :");
  scanf("%d", &ptr->data);
  ptr->next = tail->next;
  tail->next = ptr;
  return tail;
}

struct node *insert_end(struct node *tail)
{
  struct node *temp = malloc(sizeof(struct node));
  printf("Enter value to be inserted at end :");
  scanf("%d", &temp->data);
  temp->next = tail->next;
  tail->next = temp;
  tail = temp;
}

void display(struct node *tail)
{
  struct node *temp = tail->next;
  do
  {
    printf("%d ", temp->data);
    temp = temp->next;
  } while (temp != tail->next);
}
int main()
{
  struct node *first = malloc(sizeof(struct node));
  struct node *second = malloc(sizeof(struct node));
  struct node *third = malloc(sizeof(struct node));
  struct node *tail = malloc(sizeof(struct node));

  first->data = 20;
  first->next = second;

  second->data = 30;
  second->next = third;

  third->data = 40;
  third->next = tail;

  tail->data = 50;
  tail->next = first;

  display(tail);

  tail = insert_start(tail);
  printf("\nAfter Inserting Element in Start:\t\n");
  display(tail);
  printf("\n************\n");
  tail = insert_end(tail);
  printf("\nAfter Inserting Element in End:\t\n");
  display(tail);
  printf("\n************\n");
  tail = insert_AtPos(tail);
  printf("\nAfter Inserting Element in Pos:\t\n");
  display(tail);
}