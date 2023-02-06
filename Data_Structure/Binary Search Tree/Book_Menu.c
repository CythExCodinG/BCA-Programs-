#include <stdio.h>

#include <stdlib.h>

struct node

{
  struct node *left;
  int data;
  struct node *right;
};

struct node *insert(struct node *p, int d)

{
  if (p == NULL)
  {
    p = (struct node *)malloc(sizeof(struct node));
    p->left = p->right = NULL;
    p->data = d;
  }
  else if (d < p->data)
    p->left = insert(p->left, d);
  else if (d > p->data)
    p->right = insert(p->right, d);
  return (p);
}

struct node *search(struct node *p, int x)

{
  if (p != NULL)
  {
    if (p->data == x)
      return p;
    if (x < p->data)
      return (search(p->left, x));
    else
      return (search(p->right, x));
  }
}

void preorder(struct node *p)
{
  if (p != NULL)
  {
    printf("%d \t", p->data);
    preorder(p->left);
    preorder(p->right);
  }
}

void inorder(struct node *p)
{
  if (p != NULL)
  {
    inorder(p->left);
    printf("%d \t", p->data);
    inorder(p->right);
  }
}

void postorder(struct node *p)

{

  if (p != NULL)
  {
    postorder(p->left);

    postorder(p->right);

    printf("%d \t", p->data);
  }
}

int main()
{
  int ch, x;
  struct node *tree = NULL, *temp = NULL;
  do
  {
    printf("\n1 Insert\n2 Search\n3 Preorder\n4 Inorder\n5 Postorder\n");
    printf("enter your choice\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("enter data to insert into tree\n");
      scanf("%d", &x);
      tree = insert(tree, x);
      break;
    case 2:
      if (tree == NULL)
        printf("\n Tree is NULL \n");
      else
      {
        printf("enter key to be search in tree\n");
        scanf("%d", &x);
        temp = search(tree, x);
        if (temp != NULL)
          printf("\n %d Key is found \n", temp->data);
        else
          printf("\n Key is not found \n");
      }
      break;
    case 3:
      if (tree == NULL)
        printf("\n Tree is NULL \n");
      else
        preorder(tree);
      break;
    case 4:
      if (tree == NULL)
        printf("\n Tree is NULL \n");
      else
        inorder(tree);
      break;
    case 5:
      if (tree == NULL)
        printf("\n Tree is NULL \n");
      else
        postorder(tree);
      break;
    }

  } while (ch > 0 && ch < 6);
}