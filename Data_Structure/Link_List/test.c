#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};

struct node *create();
void display();
void insert_begin();
void insert_end();
void delete_begin();
void delete_end();
struct node *head = NULL;
int main()
{
  int ch;
  while (1)
  {
    printf("1.create\n");
    printf("2.display\n");
    printf("3.insert at begin\n");
    printf("4.insert at end\n");
    printf("5.delete from begin\n");
    printf("6.delete from end\n");
    printf("enter choice:");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      create();
      break;
    case 2:
      display();
      break;
    // case 3:
    //   insert_begin();
    //   break;
    // case 4:
    //   insert_end();
    //   break;
    // case 5:
    //   delete_begin();
    //   break;
    // case 6:
    //   delete_end();
    //   break;
    default:
      printf("invalid choice\n");
      break;
    }
  }
  return 0;
}
struct node *create()
{
  struct node *ptr;
  struct node *temp = malloc(sizeof(struct node));
  printf("enter value:");
  scanf("%d", &temp->data);
  temp->next = NULL;
  if (head == NULL)
  {
    head = temp;
  }
  else
  {
    ptr = head;
    while (ptr->next != NULL)
    {
      ptr = ptr->next;
    }
    ptr->next = temp;
  }
  return temp;
}
void display()
{
  struct node *ptr;
  if (head == NULL)
  {
    printf("list is empty");
    return;
  }
  ptr = head;
  printf("elements are:\n");
  while (ptr != NULL)
  {
    printf("%d\t", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}