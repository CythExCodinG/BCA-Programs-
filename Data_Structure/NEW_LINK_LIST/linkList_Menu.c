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
void insert_specific();
void delete_first();
void delete_end();
void delete_pos();
struct node *head = NULL;
int main()
{
  int ch;
  while (1)
  {
    printf("********************");
    printf("\n1.create\n");
    printf("2.display\n");
    printf("3.insert at begin\n");
    printf("4.insert at end\n");
    printf("5.insert at specific\n");
    printf("6.delete from begin\n");
    printf("7.delete from end\n");
    printf("8.delete from specific pos\n");
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
    case 3:
      insert_begin();
      break;
    case 4:
      insert_end();
      break;
    case 5:
      insert_specific();
      break;
    case 6:
      delete_first();
      break;
    case 7:
      delete_end();
      break;
    case 8:
      delete_pos();
      break;
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

void insert_begin()
{
  struct node *temp = malloc(sizeof(struct node));
  if (temp == NULL)
  {
    printf("out of memory space");
    return;
  }
  printf("enter value for node:");
  scanf("%d", &temp->data);
  temp->next = NULL;
  if (head == NULL)
  {
    head = temp;
  }
  else
  {
    temp->next = head;
    head = temp;
  }
}

void insert_end()
{
  struct node *temp, *ptr;
  temp = malloc(sizeof(struct node));
  if (temp == NULL)
  {
    printf("out of memory space");
    return;
  }
  printf("enter value for node:");
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
}

void insert_specific()
{
  struct node *temp = malloc(sizeof(struct node));
  struct node *ptr = head;
  int i = 0, pos;
  if (temp == NULL)
  {
    printf("out of memory space");
    return;
  }
  printf("enter value for node:");
  scanf("%d", &temp->data);
  temp->next = NULL;
  printf("enter pos:");
  scanf("%d", &pos);
  if (pos == 0)
  {
    temp->next = head;
    head = temp;
  }

  while (i != pos - 1)
  {
    ptr = ptr->next;
    i++;
    if (ptr == NULL)
    {
      printf("pos not found");
      return;
    }
  }
  temp->next = ptr->next;
  ptr->next = temp;
}

void delete_first()
{
  struct node *ptr = head;
  if (ptr == NULL)
  {
    printf("list is empty");
    return;
  }
  else
  {
    head = head->next;
    printf("deleted element is %d\n", ptr->data);
    free(ptr);
  }
}

void delete_end()
{
  struct node *ptr = head;
  struct node *ptr2 = head->next;
  if (head == NULL)
  {
    printf("list is empty\n");
    return;
  }
  while (ptr2->next != NULL)
  {
    ptr = ptr->next;
    ptr2 = ptr2->next;
  }
  ptr->next = NULL;
  printf("deleted element is %d\n", ptr2->data);
  free(ptr2);
}

void delete_pos()
{
  struct node *p;
  struct node *q;
  int i = 0, pos;
  if (head == NULL)
  {
    printf("list is empty\n");
    return;
  }
  else
  {
    printf("enter pos of node to be deleted:");
    scanf("%d", &pos);
    if (pos == 0)
    {
      p = head;
      head = head->next;
      printf("deleted element is %d", p->data);
      free(p);
    }
    else
    {
      p = head;
      for (i = 0; i < pos; i++)
      {
        q = p;
        p = p->next;
        if (p == NULL)
        {
          printf("pos not found");
          return;
        }
        q->next = p->next;
        printf("deleted element is %d\t", p->data);
        free(p);
      }
    }
  }
}