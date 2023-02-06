#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *tail = NULL;

struct node *create();
void insert_begin();
void insert_end();
void insert_AtPos();
void delete_begin();
void delete_end();
void delete_pos();
void display();
int length();
void search();

int length()
{
  if (tail == NULL)
  {
    return 0;
  }

  struct node *temp = tail->next;
  int count = 1;

  while (temp->next != tail->next)
  {
    count += 1;
    temp = temp->next;
  }
  return count;
}

struct node *create()
{
  struct node *temp = malloc(sizeof(struct node));
  printf("Enter value to be inserted :");
  scanf("%d", &temp->data);
  if (tail == NULL)
  {
    temp->next = temp;
    tail = temp;
  }
  else
  {
    temp->next = tail->next;
    tail->next = temp;
    tail = temp;
  }
}

void insert_begin()
{
  struct node *temp = malloc(sizeof(struct node));
  printf("Enter value to be inserted :");
  scanf("%d", &temp->data);
  if (tail == NULL)
  {
    temp->next = temp;
    tail = temp;
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
  printf("Enter value to be inserted at end :");
  scanf("%d", &temp->data);
  if (tail == NULL)
  {
    tail = temp;
    tail->next = tail;
  }
  temp->next = tail->next;
  tail->next = temp;
  tail = temp;
}

void insert_AtPos()
{
  struct node *temp = malloc(sizeof(struct node));
  // printf("Enter value to be inserted at end :");
  // scanf("%d", &temp->data);
  int index = 0;
  printf("Enter the Position :");
  scanf("%d", &index);
  if (tail == NULL)
  {
    tail = temp;
    tail->next = tail;
  }
  else if (index == 1)
  {
    insert_begin();
  }

  else if (index == 0)
  {
    printf("INVALID POSITION");
  }
  else if (index > length())
  {
    printf("\nINVALID POSITION");
  }
  else
  {
    printf("Enter value to be inserted at Position :");
    scanf("%d", &temp->data);
    // int index = 0;
    // printf("Enter the Position :");
    // scanf("%d", &index);

    int i = 1;
    struct node *p = tail->next;
    while (i < index - 1)
    {
      p = p->next;
      i++;
    }
    temp->next = p->next;
    p->next = temp;
  }
}
void delete_begin()
{
  if (tail->next == tail)
  {
    struct node *ptr = tail;
    free(ptr);

    printf("LIST IS EMPTY\n");
    return;
  }

  else
  {
    struct node *ptr = tail->next;
    // struct node *p = ptr;
    tail->next = ptr->next;
    // tail->next = ptr;
    printf("Deleted Value is :%d", ptr->data);
    free(ptr);
  }
}
void delete_end()
{
  if (tail == NULL)
  {
    printf("List is empty\n");
  }
  else if (tail->next == tail)
  {
    printf("Deleted Node is :%d", tail->data);
    free(tail);
    printf("\n***********\n");
    printf("List is Empty now");
    printf("\n***********");
  }
  else
  {
    struct node *ptr = tail->next;
    while (ptr->next != tail)
    {
      ptr = ptr->next;
    }
    struct node *p = tail;
    ptr->next = tail->next;
    printf("Deleted Node is :%d", tail->data);
    tail = ptr;
    free(p);
  }
}
void delete_pos()
{
  int index = 0;
  printf("Enter the Position :");
  scanf("%d", &index);

  if (tail == NULL)
  {
    printf("List is Empty:");
  }
  else if (index == 1)
  {
    delete_begin();
  }

  else if (index == 0)
  {
    printf("INVALID POSITION");
  }
  else if (index > length())
  {
    printf("\nINVALID POSITION");
  }
  else
  {
    struct node *ptr = tail->next;
    int i = 1;
    while (i < index - 1)
    {
      ptr = ptr->next;
      i++;
    }
    struct node *q = ptr->next;
    ptr->next = q->next;
    printf("Deleted Element is :%d", q->data);
    free(q);
  }
}
void search()
{
  struct node *ptr = tail->next;
  int value = 0;
  printf("Enter the value for searching :");
  scanf("%d", &value);
  int flag = 1;
  do
  {
    if (ptr->data == value)
    {
      printf("Value found At Pos:%d", flag);
      return;
    }
    ptr = ptr->next;
    flag++;

  } while (ptr != tail->next);
  printf("!!!Value Not Found!!!");
}

void display()
{
  if (tail == NULL)
  {
    printf("List empty:");
  }
  else
  {
    struct node *ptr = tail->next;
    do
    {
      printf("%d ", ptr->data);
      ptr = ptr->next;
    } while (ptr != tail->next);
  }
}
int main()
{
  int choice;
  while (1)
  {
    printf("\n\n\n*************\n");
    printf("1. Create\n");
    printf("2. Display\n");
    printf("3. Insert Node at beginning\n");
    printf("4. Insert Node in specific position\n");
    printf("5. Insert Node at end of LinkedList\n");
    printf("6. List size\n");
    printf("7. Delete Node at beginning\n");
    printf("8. Delete Node at end\n");
    printf("9. Delete Node at position\n");
    printf("10. Search in LL\n");
    printf("11. ** To exit **");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice)
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
      insert_AtPos();
      break;
    case 5:
      insert_end();
      break;
    case 6:
      length();
      break;
    case 7:
      delete_begin();
      break;
    case 8:
      delete_end();
      break;
    case 9:
      delete_pos();
      break;
    case 10:
      search();
      break;
    case 11:
      exit(0);
      break;
    }
  }
}