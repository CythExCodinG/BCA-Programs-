#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};
int length(struct node *head)
{
  int count = 0;
  struct node *ptr = head;
  while (ptr != NULL)
  {
    ptr = ptr->next;
    count++;
  }
  return count;
}
int intersection(struct node *head1, struct node *head2)
{
  int l1 = length(head1);
  int l2 = length(head2);
  struct node *ptr1;
  struct node *ptr2;
  int d = 0;

  if (l1 > l2)
  {
    d = l1 - l2;
    ptr1 = head1;
    ptr2 = head2;
  }
  else
  {
    d = l2 - l1;
    ptr1 = head2;
    ptr2 = head1;
  }
  while (d != 0)
  {
    ptr1 = ptr1->next;
    if (ptr1 == NULL)
    {
      return -1;
    }

    d--;
  }

  int count = 0;
  while (ptr1 != NULL && ptr2 != NULL)
  {
    if (ptr1->data == ptr2->data)
    {
      printf("%d ", ptr1->data);
      count++;
    }

    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  return count;
}
void display(struct node *head)
{
  if (head == NULL)
  {
    printf("Linked List is Empty\n");
    return;
  }
  printf("LinkedList: ");
  struct node *ptr = head;
  while (ptr != NULL) // start from first node
  {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}
int main()
{
  struct node *ptr;
  struct node *head1 =
      (struct node *)malloc(sizeof(struct node));
  head1->data = 10;

  struct node *head2 =
      (struct node *)malloc(sizeof(struct node));
  head2->data = 3;

  ptr =
      (struct node *)malloc(sizeof(struct node));
  ptr->data = 6;
  head2->next = ptr;

  ptr =
      (struct node *)malloc(sizeof(struct node));
  ptr->data = 9;
  head2->next->next = ptr;

  ptr =
      (struct node *)malloc(sizeof(struct node));
  ptr->data = 15;
  head1->next = ptr;
  head2->next->next->next = ptr;

  ptr =
      (struct node *)malloc(sizeof(struct node));
  ptr->data = 30;
  head1->next->next = ptr;

  ptr =
      (struct node *)malloc(sizeof(struct node));
  ptr->data = 45;
  head1->next->next->next = ptr;
  head1->next->next->next->next = NULL;

  ptr =
      (struct node *)malloc(sizeof(struct node));
  ptr->data = 55;
  head2->next->next->next->next->next->next = ptr;
  head2->next->next->next->next->next->next->next = NULL;

  int l = length(head1);
  int l2 = length(head2);

  printf("Length of LL is 1:%d\n", l);
  printf("Length of LL is 2:%d\n", l2);

  display(head1);
  display(head2);
  printf("Points that insersect :");
  int intersect = intersection(head1, head2);
  printf("\nLink List intersect at %d points", intersect);
}