#include <stdio.h>
#include <stdlib.h>
struct node *head = NULL;
struct node
{
  int data;
  struct node *next;
};

void create()
{
  struct node *temp;
  temp = malloc(sizeof(struct node));
  printf("Enter Node Value:");
  scanf("%d", &temp->data);
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
void display()
{
  if (head == NULL)
  {
    printf("List is empty");
  }
  else
  {
    struct node *ptr = head;
    printf("Link List is:");
    while (ptr != NULL)
    {
      printf("%d ", ptr->data);
      ptr = ptr->next;
    }
    printf("\n");
  }
}
void insert_begin()
{
  struct node *temp;
  temp = malloc(sizeof(struct node));
  printf("Enter value to be inserted:");
  scanf("%d", &temp->data);
  temp->next = NULL;

  if (head == NULL)
  {
    head = temp;
    return;
  }
  else
  {
    temp->next = head;
    head = temp;
  }
}

void insert_pos()
{
  int index;
  struct node *temp;
  temp = malloc(sizeof(struct node));

  printf("Enter value to be inserted:");
  scanf("%d", &temp->data);
  temp->next = NULL;
  printf("Enter Position:");
  scanf("%d", &index);
  if (head == NULL)
  {
    head = temp;
    return;
  }
  else
  {
    struct node *ptr = head;
    int i = 1;
    while (i < index - 1)
    {
      ptr = ptr->next;
      i++;
    }
    temp->next = ptr->next;
    ptr->next = temp;
  }
}
void insert_end()
{
  struct node *temp;
  temp = malloc(sizeof(struct node));

  printf("Enter value to be inserted");
  scanf("%d", &temp->data);
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
    temp->next = NULL;
  }
}
void delete_begin()
{
  if (head == NULL)
  {
    printf("List is Empty Nothing to Delete");
    return;
  }
  else
  {
    struct node *ptr = head;
    head = head->next;
    printf("deleted element is %d\n", ptr->data);
    free(ptr);
  }
}

void delete_end()
{
  if (head == NULL)
  {
    printf("List is Empty\n");
    return;
  }
  struct node *ptr = head;
  struct node *pre_ptr = NULL;
  while (ptr->next != NULL)
  {
    pre_ptr = ptr;
    ptr = ptr->next;
  }
  pre_ptr->next = NULL;
  free(ptr);
}

void delete_pos()
{
  if (head == NULL)
  {
    printf("List is Empty");
    return;
  }
  else
  {
    int index;
    printf("Enter Position:");
    scanf("%d", &index);
    struct node *ptr = head;
    int i = 1;
    while (i < index - 1)
    {
      ptr = ptr->next;
      i++;
    }
    struct node *q = ptr->next;
    ptr->next = q->next;
    free(q);
  }
}
int main()
{
  int choice;
  while (1)
  {
    printf("\n*************\n");
    printf("1. Create\n");
    printf("2. Display\n");
    printf("3. Insert Node at beginning\n");
    printf("4. Insert Node in specific position\n");
    printf("5. Insert Node at end of LinkedList\n");
    printf("6. Delete Node at beginning\n");
    printf("7. Delete Node at end\n");
    printf("8. Delete Node at position\n");
    printf("9. ** To exit **");

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
      insert_pos();
      break;
    case 5:
      insert_end();
      break;
    case 6:
      delete_begin();
      break;
    case 7:
      delete_end();
      break;
    case 8:
      delete_pos();
      break;
    case 9:
      exit(0);
    default:
      printf("\n Wrong Choice");
      break;
    }
  }
}