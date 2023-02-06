#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *link;
};
struct node *add_at_end(struct node *ptr, int data)
{
  struct node *temp = malloc(sizeof(struct node));
  temp->data = data;
  temp->link = NULL;

  ptr->link = temp;
  return temp;
}
int main()
{
  struct node *head = malloc(sizeof(struct node));
  head->data = 50;
  head->link = NULL;

  struct node *ptr = head;

  char flag = 'y';
at_end:
  int d;
  printf("Enter Element to insert at end=>\n");
  scanf("%d", &d);
  ptr = add_at_end(ptr, d);
  printf("Want to continue press Y If Not then N:");
  scanf(" %c", &flag);

  if (flag == 'y' || flag == 'Y')
  {
    goto at_end;
  }
  else if (flag == 'n' || flag == 'N')
  {
    printf("Discontinued: YOUR LINK LIST IS==>\n");
  }

  // ptr = add_at_end(ptr, 98);

  ptr = head;

  while (ptr != NULL)
  {
    printf("%d ", ptr->data);
    ptr = ptr->link;
  }
}
