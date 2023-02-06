#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *tail = NULL;
int length()
{
  struct node *ptr = tail->next;
  int count = 1;
  while (ptr->next != tail->next)
  {
    ptr = ptr->next;
    count++;
  }
  printf("length of list is %d", count);
  return count;
}

struct node *create()
{
  struct node *temp = malloc(sizeof(struct node));
  printf("enter value to create a node:");
  scanf("%d", &temp->data);
  printf("node create successfully\n");
  temp->next = NULL;
  if (tail == NULL)
  {
    tail = temp;
    tail->next = tail;
  }
  else
  {
    temp->next = tail->next;
    tail->next = temp;
    tail = temp;
  }
}
void display()
{
  struct node *ptr = tail->next;
  do
  {
    printf("%d\t", ptr->data);
    ptr = ptr->next;
  } while (ptr != tail->next);
}
void insert_first()
{
  struct node *temp = malloc(sizeof(struct node));
  printf("enter value to insert:");
  scanf("%d", &temp->data);
  printf("value inserted successfully\n");
  if (tail == NULL)
  {
    tail = temp;
    tail->next = tail;
  }
  else
  {
    temp->next = tail->next;
    tail->next = temp;
  }
}
void insert_end()
{
  struct node *temp = malloc(sizeof(struct node));
  printf("enter value to insert:");
  scanf("%d", &temp->data);
  if (tail == NULL)
  {
    tail = temp;
    tail->next = tail;
  }
  else
  {
    temp->next = tail->next;
    tail->next = temp;
    tail = tail->next;
  }
}
void insert_pos()
{
  struct node *ptr = tail->next;
  struct node *temp = malloc(sizeof(struct node));
  int i = 1, pos = 0;
  printf("enter value to insert:");
  scanf("%d", &temp->data);
  printf("enter position:");
  scanf("%d", &pos);
  if (tail == NULL)
  {
    tail = temp;
    tail->next = tail;
  }
  else if (pos < 0)
  {
    printf("invalid position\n");
  }
  else if (pos > length())
  {
    printf("invalid position\n");
  }
  while (i != pos - 1)
  {
    ptr = ptr->next;
    i++;
  }
  temp->next = ptr->next;
  ptr->next = temp;
}
// int length()
// {
//   struct node *ptr = tail->next;
//   int count = 1;
//   while (ptr->next != tail->next)
//   {
//     ptr = ptr->next;
//     count++;
//   }
//   printf("length of list is %d", count);
//   return count;
// }
int main()
{
  int ch;
  while (1)
  {
    printf("\n***\n");
    printf("1. Create\n");
    printf("2. Display\n");
    printf("3. Insert Node at beginning\n");
    printf("4. Insert Node at end\n");
    printf("5. Insert Node at spceific position\n");
    printf("6. Delete Node at beginning\n");
    printf("7. Delete Node at end\n");
    printf("8. Delete Node at position\n");
    printf("9. * To exit *");

    printf("\nEnter your choice: ");
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
      insert_first();
      break;
    case 4:
      insert_end();
      break;
    case 5:
      insert_pos();
      break;
    case 6:
      length();
      break;
    }
  }
}