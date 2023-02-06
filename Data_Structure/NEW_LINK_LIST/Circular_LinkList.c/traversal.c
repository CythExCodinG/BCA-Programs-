#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

void display(struct node *head)
{
  struct node *ptr = head;
  do
  {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  } while (ptr != head);
}
int main()
{
  struct node *head = malloc(sizeof(struct node));
  struct node *second = malloc(sizeof(struct node));
  struct node *third = malloc(sizeof(struct node));
  struct node *fourth = malloc(sizeof(struct node));

  head->data = 20;
  head->next = second;

  second->data = 30;
  second->next = third;

  third->data = 40;
  third->next = fourth;

  fourth->data = 50;
  fourth->next = NULL;

  display(head);
}