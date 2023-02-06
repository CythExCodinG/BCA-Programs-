#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *insertAtIndex(struct Node *head, int data, int index)
{
  struct Node *ptr = malloc(sizeof(struct Node *));
  struct Node *p = head;
  int i = 0;
  while (i != index - 1)
  {
    p = p->next;
    i++;
  }
  ptr->data = data;
  ptr->next = p->next;
  p->next = ptr;
  return head;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
  struct Node *ptr = malloc(sizeof(struct Node));
  ptr->data = data;
  struct Node *p = head;
  while (p->next != NULL)
  {
    p = p->next;
  }

  p->next = ptr;
  ptr->next = NULL;
  return head;
}

struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
  struct Node *ptr = malloc(sizeof(struct Node));
  ptr->data = data;

  ptr->next = prevNode->next;
  prevNode->next = ptr;

  return head;
}

struct Node *insertAtFrist(struct Node *head, int data)
{
  struct Node *ptr = malloc(sizeof(struct Node));
  ptr->data = data;
  ptr->next = head;
  return ptr;
}

void linkedListTraversal(struct Node *ptr)
{
  while (ptr != NULL)
  {
    printf("Element: %d\n", ptr->data);
    ptr = ptr->next;
  }
}

int main()
{
  struct Node *head;
  struct Node *second;
  struct Node *third;
  struct Node *fourth;

  // Allocate memory for nodes in the linked list in Heap
  head = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));
  fourth = (struct Node *)malloc(sizeof(struct Node));

  // Link first and second nodes
  head->data = 7;
  head->next = second;

  // Link second and third nodes
  second->data = 11;
  second->next = third;

  // Link third and fourth nodes
  third->data = 41;
  third->next = fourth;

  // Terminate the list at the third node
  fourth->data = 66;
  fourth->next = NULL;

  linkedListTraversal(head);
  printf("-----\n");

  head = insertAtFrist(head, 50);
  linkedListTraversal(head);

  printf("-----\n");

  head = insertAtIndex(head, 20, 3);
  linkedListTraversal(head);

  insertAtEnd(head, 12);
  printf("-----\n");
  printf("Link List After insertion\n");
  linkedListTraversal(head);
  printf("-----\n");
  head = insertAfterNode(head, second, 25);
  linkedListTraversal(head);
  return 0;
}