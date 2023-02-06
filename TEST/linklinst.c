#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *head = NULL;
struct node *create();
int length();
int disp_length();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void del_first();
void del_end();
void del_pos();
int main()
{
  int ch;
  while (1)
  {
    printf("1.create\n");
    printf("2.display\n");
    printf("3.insert element at beggining of list\n");
    printf("4.insert element at end of list\n");
    printf("5.insert at specific position\n");
    printf("6.delete first element\n");
    printf("7.length of linked list\n");
    printf("8.delete last element\n");
    printf("9.delete from specific position\n");
    printf("enter your choice:");
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
      insert_pos();
      break;
    case 6:
      del_first();
      break;
    case 7:
      disp_length();
      break;
    case 8:
      del_end();
      break;
    case 9:
      del_pos();
      break;
    }
  }
  return 0;
}
struct node *create()
{
  struct node *temp = malloc(sizeof(struct node));
  printf("enter value for node:");
  scanf("%d", &temp->data);
  printf("value created successfully\n");
  temp->next = NULL;
  if (head == NULL)
  {
    head = temp;
  }
  else
  {
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
      ptr = ptr->next;
    }
    ptr->next = temp;
  }
  return temp;
}
int length()
{
  struct node *ptr = head;
  int count = 0;
  while (ptr != NULL)
  {
    ptr = ptr->next;
    count++;
  }
  return count;
}
int disp_length()
{
  struct node *ptr = head;
  int count = 0;
  while (ptr != NULL)
  {
    ptr = ptr->next;
    count;
  }
  printf("lenght=%d\n", count);
}
void display()
{
  struct node *ptr = head;
  if (head == NULL)
  {
    printf("list is empty\n");
  }
  else
  {
    printf("elements are:\n");
    while (ptr != NULL)
    {
      printf("%d\t", ptr->data);
      ptr = ptr->next;
    }
    printf("\n");
  }
}
void insert_begin()
{
  struct node *temp = malloc(sizeof(struct node));
  printf("enter value to insert at begining:");
  scanf("%d", &temp->data);
  printf("value inserted successfully\n");
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
  struct node *temp = malloc(sizeof(struct node));
  printf("enter value to insert at end:");
  scanf("%d", &temp->data);
  printf("value inserted successfully\n");
  temp->next = NULL;
  if (head == NULL)
  {
    head = temp;
  }
  else
  {
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
      ptr = ptr->next;
    }
    ptr->next = temp;
  }
}
void insert_pos()
{
  int i = 0, pos;
  struct node *temp = malloc(sizeof(struct node));
  printf("enter position:");
  scanf("%d", &pos);
  if (pos == 0)
  {
    insert_begin();
  }
  else if (pos > length())
  {
    printf("invalid position\n");
  }
  else
  {
    struct node *ptr = head;
    printf("enter value to insert:");
    scanf("%d", &temp->data);

    temp->next = NULL;
    while (i != pos - 1)
    {
      ptr = ptr->next;
      i++;
      if (ptr == NULL)
      {
        printf("position not found\n");
        return;
      }
    }
    temp->next = ptr->next;
    ptr->next = temp;
    printf("element inserted successfully\n");
  }
}
void del_first()
{
  struct node *ptr = head;
  if (head == NULL)
  {
    printf("list is empty\n");
  }
  else
  {
    head = head->next;
    printf("deleted element is %d\n", ptr->data);
    free(ptr);
  }
}
void del_end()
{
  struct node *ptr = head;
  struct node *q = head->next;
  if (head == NULL)
  {
    printf("list is already empty\n");
    return;
  }

  while (q->next != NULL)
  {
    ptr = ptr->next;
    q = q->next;
  }
  ptr->next = NULL;
  printf("deleted element is %d\n", q->data);
  free(q);
}
void del_pos()
{
  if (head == NULL)
  {
    printf("list is empty");
    return;
  }
  else
  {
    int i = 0, pos;
    printf("enter position\n");
    scanf("%d", &pos);
    struct node *p = head;
    while (i < pos - 1)
    {
      p = p->next;
    }
    struct node *q = p->next;
    p->next = q->next;
    printf("deleted element is %d", q->data);
    free(q);
  }
}