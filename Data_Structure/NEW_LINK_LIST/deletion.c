#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};

struct Node *deleteFirst(struct Node *head)
{
  struct Node *ptr = head;
  head = head->next;
  free(ptr);
  return head;
}

struct Node *deleteLast(struct Node *head)
{
  struct Node *ptr = head;
  struct Node *q = head->next;

  while (q->next != NULL)
  {
    ptr = ptr->next;
    q = q->next;
  }
  ptr->next = NULL;
  free(q);
  return head;
}
struct Node *deleteAtIndex(struct Node *head, int index)
{
  struct Node *ptr = head;
  int i = 1;
  while (i < index - 1)
  {
    ptr = ptr->next;
    i++;
  }
  struct Node *q = ptr->next;
  ptr->next = q->next;
  free(q);
  return head;
}
// void LLlengeth(struct Node *head)
// {
//   struct Node *ptr = head;
//   int count = 0;
//   while (ptr != NULL)
//   {
//     ptr = ptr->next;
//     count++;
//   }
//   printf("Lengeth of LL is:%d", count);
//   // return;
// }
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
  head->data = 4;
  head->next = second;

  // Link second and third nodes
  second->data = 3;
  second->next = third;

  // Link third and fourth nodes
  third->data = 8;
  third->next = fourth;

  // Terminate the list at the third node
  fourth->data = 1;
  fourth->next = NULL;

  printf("LinkL before deletion:\n");
  linkedListTraversal(head);
  // LLlengeth(head);
  // head = deleteFirst(head);
  // head = deleteAtIndex(head, 3);

  printf("LinkL After deletion:\n");
  // linkedListTraversal(head);

  deleteLast(head);
  linkedListTraversal(head);
}